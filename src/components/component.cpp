#include "component.h"
#include "componentinstantiator.h"

// Derived Types
#include "wraparoundcomponent.h"
#include "shootcomponent.h"
#include "playerinputcomponent.h"
#include "playergraphicscomponent.h"
#include "collisioncomponent.h"
#include "movementcomponent.h"
#include "bulletgraphicscomponent.h"
#include "asteroidgraphicscomponent.h"
#include "healthcomponent.h"
#include "boundingboxgraphicscomponent.h"
#include "outofboundscomponent.h"

#include <QtScript>

#define REGISTER_COMPONENT(ComponentType) \
    ComponentInstantiator::RegisterType<ComponentType>(#ComponentType);

unsigned int Component::NextId;

void Component::RegisterDerivedTypes()
{
    REGISTER_COMPONENT(HealthComponent)
    REGISTER_COMPONENT(WrapAroundComponent)
    REGISTER_COMPONENT(ShootComponent)
    REGISTER_COMPONENT(PlayerInputComponent)
    REGISTER_COMPONENT(PlayerGraphicsComponent)
    REGISTER_COMPONENT(CollisionComponent)
    REGISTER_COMPONENT(MovementComponent)
    REGISTER_COMPONENT(BulletGraphicsComponent)
    REGISTER_COMPONENT(AsteroidGraphicsComponent)
    REGISTER_COMPONENT(BoundingBoxGraphicsComponent)
    REGISTER_COMPONENT(OutOfBoundsComponent)
}

Component::Component(QObject* parent)
    : QObject(parent)
    , ID(NextId++)
{
}

Component::~Component()
{
}

void Component::initialize(const std::shared_ptr<GameObject> &owner, const QVariantMap &arguments)
{
    setOwner(owner);
    initialize(arguments);
    subscribeToMessages();
    injectPropertiesInOwner(arguments);
}


unsigned int Component::getId() const
{
    return ID;
}

std::shared_ptr<GameObject> Component::getOwner() const
{
    return owner;
}

void Component::setOwner(const std::shared_ptr<GameObject>& owner)
{
    this->owner = owner;
}

QString Component::getName() const
{
    return metaObject()->className();
}

void Component::sendMessage(const QString& message, const QVariantMap& payload)
{
    owner->sendMessage(message, payload);
}

void Component::subscribeToMessage(const QString& message)
{
    owner->subscribeToMessage(message, shared_from_this());
}

QVariant Component::getOwnerProperty(const char* name) const
{
    return owner->property(name);
}

void Component::setOwnerProperty(const char* name, const QVariant& value)
{
    owner->setProperty(name, value);
}

void Component::markOwnerForDeletion()
{
    owner->markForDeletion();
    cleanup();
}

void Component::cleanup()
{
    owner.reset();
}
