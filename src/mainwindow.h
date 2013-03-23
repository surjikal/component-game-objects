#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QErrorMessage>

#include <memory>

#include "inputsystem.h"
#include "game.h"

class GameObjectDescriptor;
class GameWorld;
class CollisionSystem;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void on_reload_clicked();

private:
    Ui::MainWindow *ui;

    InputSystem inputSystem;


    std::shared_ptr<Game> game;
    std::shared_ptr<Game> createNewGame();

    QList<std::shared_ptr<GameObjectDescriptor> > parseGameObjectConfiguration(const QString& configContents);
    void registerGameObjectTypes(const QList<std::shared_ptr<GameObjectDescriptor> >& gameObjectDescriptors);

    QString fileToString(const QString& filename);

    QErrorMessage errorMessage;
};

#endif // MAINWINDOW_H
