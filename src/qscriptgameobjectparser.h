#ifndef QSCRIPTGAMEOBJECTPARSER_H
#define QSCRIPTGAMEOBJECTPARSER_H

#include <QVariant>
#include <stdexcept>
#include "gameobjectparser.h"


class QScriptGameObjectParser : public GameObjectParser
{
public:
    QScriptGameObjectParser();
    virtual QList<std::shared_ptr<GameObjectDescriptor> > parse(const QString& gameObjectsConfig);

private:
    void parseGameObjects(const QVariantList& gameObjects, QList<std::shared_ptr<GameObjectDescriptor> >& gameObjectDescriptors);
    void parseGameObject(const QVariantMap& gameObject, std::shared_ptr<GameObjectDescriptor> gameObjectDescriptor);
    void parseComponents(const QVariantMap &gameObjectComponents, std::shared_ptr<GameObjectDescriptor> gameObjectDescriptor);
};


class GameObjectConfigParseError : public std::runtime_error
{
public:
    GameObjectConfigParseError(int lineNumber, const QString& errorMsg)
        : std::runtime_error(QString("ParseException at line %1: %2").arg(lineNumber).arg(errorMsg).toStdString())
        , lineNumber(lineNumber)
        , errorMsg(errorMsg)
    {
    }

    virtual ~GameObjectConfigParseError() throw() {}

    int lineNumber;
    QString errorMsg;
};

#endif // QSCRIPTGAMEOBJECTPARSER_H
