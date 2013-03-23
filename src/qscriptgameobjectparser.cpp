#include "qscriptgameobjectparser.h"

#include <QtScript>

#include <QDebug>

#include "componentinstantiator.h"
#include "components/component.h"



QScriptGameObjectParser::QScriptGameObjectParser()
{
}


QList<std::shared_ptr<GameObjectDescriptor> > QScriptGameObjectParser::parse(const QString &gameObjectsConfig)
{
    QScriptEngine engine;
    QScriptValue global = engine.globalObject();

    QScriptValue result = engine.evaluate(gameObjectsConfig);

    if (engine.hasUncaughtException())
    {
        int line = engine.uncaughtExceptionLineNumber();
        qDebug() << "uncaught exception at line" << line << ":" << result.toString();
        throw GameObjectConfigParseError(line, result.toString());
    }

    QVariantList gameObjects = global.property("GameObjects").toVariant().toList();
    QList<std::shared_ptr<GameObjectDescriptor> > gameObjectDescriptors;

    parseGameObjects(gameObjects, gameObjectDescriptors);

    return gameObjectDescriptors;
}

void QScriptGameObjectParser::parseGameObjects(const QVariantList& gameObjects, QList<std::shared_ptr<GameObjectDescriptor> > &gameObjectDescriptors)
{
    foreach(QVariant gameObjectVariant, gameObjects)
    {
        std::shared_ptr<GameObjectDescriptor> gameObjectDescriptor( new GameObjectDescriptor() );
        QVariantMap gameObject = gameObjectVariant.toMap();

        parseGameObject(gameObject, gameObjectDescriptor);
        gameObjectDescriptors.append(gameObjectDescriptor);
    }
}

void QScriptGameObjectParser::parseGameObject(const QVariantMap& gameObject, std::shared_ptr<GameObjectDescriptor> gameObjectDescriptor)
{
    gameObjectDescriptor->name = gameObject["name"].toString();
    QVariantMap gameObjectComponents = gameObject["components"].toMap();

    parseComponents(gameObjectComponents, gameObjectDescriptor);
}

void QScriptGameObjectParser::parseComponents(const QVariantMap& gameObjectComponents, std::shared_ptr<GameObjectDescriptor> gameObjectDescriptor)
{
    foreach(QString componentName, gameObjectComponents.keys())
    {
        std::shared_ptr<ComponentDescriptor> component( new ComponentDescriptor() );
        component->name = componentName;
        component->arguments = gameObjectComponents[componentName].toMap();

        gameObjectDescriptor->components.append(component);
    }
}
