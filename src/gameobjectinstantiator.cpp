#include "gameobjectinstantiator.h"
#include "components/component.h"
#include "componentdescriptor.h"
#include <QDebug>

QMap<QString, std::shared_ptr<GameObjectDescriptor> > GameObjectInstantiator::RegisteredGameObjectTypes;

void GameObjectInstantiator::RegisterType(const QString& typeName, const std::shared_ptr<GameObjectDescriptor>& gameObjectDescriptor)
{
    RegisteredGameObjectTypes[typeName] = gameObjectDescriptor;
}

GameObjectInstantiator::GameObjectInstantiator()
{
}

std::shared_ptr<GameObject> GameObjectInstantiator::instantiate(const QString& typeName)
{
    if (!RegisteredGameObjectTypes.contains(typeName))
    {
        // throw GameObjectTypeNotFoundException(typeName);
        GameObject* gameObject = new GameObject();
        gameObject->setObjectName("UnknownType");
        return std::shared_ptr<GameObject>(gameObject);
    }

    std::shared_ptr<GameObjectDescriptor> descriptor = RegisteredGameObjectTypes[typeName];
    return instantiate(descriptor);
}

void GameObjectInstantiator::ClearRegisteredTypes()
{
    GameObjectInstantiator::RegisteredGameObjectTypes.clear();
}

std::shared_ptr<GameObject> GameObjectInstantiator::instantiate(const std::shared_ptr<GameObjectDescriptor>& gameObjectDescriptor)
{
    ComponentInstantiator componentInstantiator;

    std::shared_ptr<GameObject> gameObject( new GameObject() );
    gameObject->setObjectName(gameObjectDescriptor->name);

    foreach(std::shared_ptr<ComponentDescriptor> componentDescriptor, gameObjectDescriptor->components)
    {
        try
        {
            std::shared_ptr<Component> component = componentInstantiator.instantiate(componentDescriptor->name);
            component->setObjectName(componentDescriptor->name);
            gameObject->addComponent(component, componentDescriptor->arguments);
        }
        catch (const ComponentTypeNotFoundException& e)
        {
            qDebug() << "Could not find component type" << e.getTypeName();
        }
    }

//    QString propertyName;
//    foreach(propertyName, gameObjectDescriptor->properties)
//    {
//        component = componentInstantiator.instantiate(componentType);
//        if (component == 0) {
//            qDebug() << "Could not instantiate game object" << gameObjectDescriptor->name;
//            return 0;
//        }
//    }

    return gameObject;
}


