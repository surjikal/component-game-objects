#ifndef GAMEOBJECTINSTANTIATOR_H
#define GAMEOBJECTINSTANTIATOR_H

#include <QString>
#include <QMap>

#include <memory>
#include <stdexcept>

#include "gameobjectdescriptor.h"
#include "componentinstantiator.h"
#include "gameobject.h"

class GameObjectInstantiator
{
public:
    static void RegisterType( const QString& typeName, const std::shared_ptr<GameObjectDescriptor>& gameObjectDescriptor );

    static void ClearRegisteredTypes();

    GameObjectInstantiator();
    std::shared_ptr<GameObject> instantiate( const QString& typeName );

private:
    static QMap<QString, std::shared_ptr<GameObjectDescriptor> > RegisteredGameObjectTypes;

    std::shared_ptr<GameObject> instantiate( const std::shared_ptr<GameObjectDescriptor>& gameObjectDescriptor );
};

class GameObjectTypeNotFoundException: public std::runtime_error
{
public:
    GameObjectTypeNotFoundException(const QString& typeName)
        : std::runtime_error(QString("Could not find game object type type '%1'").arg(typeName).toStdString())
        , typeName(typeName)
    {}

    virtual ~GameObjectTypeNotFoundException() throw() {}

    QString getTypeName() const
    {
        return typeName;
    }

private:
    const QString typeName;
};


#endif // GAMEOBJECTINSTANTIATOR_H
