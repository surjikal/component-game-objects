#ifndef GAMEOBJECTPARSER_H
#define GAMEOBJECTPARSER_H

#include <QList>
#include <memory>
#include "gameobjectdescriptor.h"

class GameObjectParser
{
public:
    virtual ~GameObjectParser() {}
    virtual QList<std::shared_ptr<GameObjectDescriptor> > parse(const QString& gameObjectsConfig) = 0;
};

#endif // GAMEOBJECTPARSER_H
