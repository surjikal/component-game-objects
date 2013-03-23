#include "gameobject.h"

#include "components/component.h"
#include "gameworld.h"

#include <QDebug>

Q_DECLARE_METATYPE(GameObject*)

unsigned int GameObject::NextId = 0;

GameObject::GameObject(QObject *parent)
    : QObject(parent)
    , ID(NextId++)
    , markedForDeletion(false)
{
}

GameObject::~GameObject()
{
    components.clear();
    messageMapping.clear();
}

GameWorld* GameObject::getGameWorld() const
{
    return gameWorld;
}

void GameObject::setGameWorld(GameWorld* gameWorld)
{
    this->gameWorld = gameWorld;
}

GameObject::GameObjectId GameObject::getId() const
{
    return ID;
}

void GameObject::addComponent(const std::shared_ptr<Component>& component, const QVariantMap& arguments)
{
    component->initialize(shared_from_this(), arguments);
    components[component->getName()] = component;
}

void GameObject::removeComponent(const QString &name)
{
    unsubscribeToMessages(name);
    components.remove(name);
}

void GameObject::subscribeToMessage(const QString& message, const std::shared_ptr<Component>& component)
{
    messageMapping.insert(message, component);
}

void GameObject::sendMessage(const QString& type, const QVariantMap &payload)
{
    auto i = messageMapping.find(type);

    while (i != messageMapping.end() && i.key() == type)
    {
        std::shared_ptr<Component> component = (i++).value();
        component->receivedMessage(type, payload);
    }
}

void GameObject::update(GameWorld& gameWorld)
{
    if (markedForDeletion)
    {
        cleanup();
        return;
    }

    foreach(std::shared_ptr<Component> component, components.values())
    {
        component->update(gameWorld);
    }
}

void GameObject::markForDeletion()
{
    markedForDeletion = true;
}

void GameObject::cleanup()
{
    components.clear();
    messageMapping.clear();
    gameWorld->markGameObjectForDeletion(shared_from_this());
}

bool GameObject::operator == (const GameObject &gameObject)
{
    return ID == gameObject.getId();
}

bool GameObject::operator != (const GameObject &gameObject)
{
    return !(*this == gameObject);
}

void GameObject::unsubscribeToMessages(const QString& componentName)
{
    auto i = messageMapping.begin();

    while (i != messageMapping.end())
    {
        auto component = i.value();

        if (component->getName() == componentName)
        {


            i = messageMapping.erase(i);
        } else {
            i++;
        }
    }
}
