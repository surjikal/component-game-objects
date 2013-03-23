#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

#include "gameobjectinstantiator.h"

#include "qscriptgameobjectparser.h"
#include "gameobjectdescriptor.h"

#include "componentinstantiator.h"
#include "components/graphicscomponent.h"
#include "components/inputcomponent.h"

#include "gameworld.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFont font("Monospace");
    font.setStyleHint(QFont::TypeWriter);

    ui->editor->setFont(font);


    //ui->horizontalLayout->setContentsMargins(0, 0, 0, 0);

    Component::RegisterDerivedTypes();

    // Initializing subsystems
    InputComponent::inputSystem = &inputSystem;
    qApp->installEventFilter( &inputSystem );

    GraphicsComponent::glWidget = ui->glWidget;

    // Loading game object types from config file
    QString configContents = fileToString(":/game-objects.json");

    QList<std::shared_ptr<GameObjectDescriptor> > gameObjectDescriptors = parseGameObjectConfiguration(configContents);

    registerGameObjectTypes(gameObjectDescriptors);

    ui->editor->insertPlainText(configContents);

    // Starting the game loop
    game = createNewGame();
    game->start();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_reload_clicked()
{
    QString configContents = ui->editor->toPlainText();

    QList<std::shared_ptr<GameObjectDescriptor> > gameObjectDescriptors = parseGameObjectConfiguration(configContents);
    GameObjectInstantiator::ClearRegisteredTypes();
    registerGameObjectTypes(gameObjectDescriptors);

    game = createNewGame();
    game->start();
}

std::shared_ptr<Game> MainWindow::createNewGame()
{
    std::shared_ptr<Game> game(new Game());
    QObject::connect(game.get(), SIGNAL(draw()), ui->glWidget, SLOT(draw()));

    return game;
}


QList<std::shared_ptr<GameObjectDescriptor> > MainWindow::parseGameObjectConfiguration(const QString& configContents)
{
    QScriptGameObjectParser parser;

    try
    {
        return parser.parse( configContents );
    }
    catch (const GameObjectConfigParseError& e)
    {
        QString errorMsg = QString("Parsing failed at line %1:\n%2").arg(e.lineNumber).arg(e.errorMsg);

        QMessageBox::critical(this, "Configuration Parsing Error", errorMsg, QMessageBox::Ok);

        return QList<std::shared_ptr<GameObjectDescriptor> >();
    }
}


void MainWindow::registerGameObjectTypes(const QList<std::shared_ptr<GameObjectDescriptor> >& gameObjectDescriptors)
{
    foreach(std::shared_ptr<GameObjectDescriptor> descriptor, gameObjectDescriptors)
    {
        GameObjectInstantiator::RegisterType(descriptor->name, descriptor);
    }
}

QString MainWindow::fileToString(const QString &filename)
{
    QFile file(filename);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString content = file.readAll();
    file.close();

    return content;
}
