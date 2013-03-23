#include "collisioncomponent.h"
#include "gameobject.h"
#include "gameworld.h"
#include "collisionsystem.h"

#include <QPointF>
#include <QVariant>

std::shared_ptr<CollisionSystem> CollisionComponent::collisionSystem;


CollisionComponent::CollisionComponent(QObject* parent)
    : Component(parent)
{
    CollisionComponent::collisionSystem->registerCollisionComponent(this);
}

CollisionComponent::~CollisionComponent()
{
    CollisionComponent::collisionSystem->unregisterCollisionComponent(getId());
}

void CollisionComponent::injectPropertiesInOwner(const QVariantMap& arguments)
{
    setOwnerProperty("boundingBox", QRectF(-1, -1, 2, 2));
}

// This would usually be split up into multiple components.
void CollisionComponent::collidedWith(const std::shared_ptr<GameObject>& gameObject)
{
    const QString& collidedWithType = gameObject->objectName();
    const QString& ownerType = getOwner()->objectName();

    if (ownerType == "Bullet" && collidedWithType == "Asteroid")
    {
        markOwnerForDeletion();
    }
    else if (ownerType == "Asteroid" && collidedWithType == "Bullet")
    {
        QPointF bulletVelocity = gameObject->property("velocity").toPointF();
        QPointF asteroidVelocity = getOwnerProperty("velocity").toPointF();

        asteroidVelocity += bulletVelocity * 0.05;
        setOwnerProperty("velocity", asteroidVelocity);
    }
}

void CollisionComponent::cleanup()
{
    Component::cleanup();
    CollisionComponent::collisionSystem->unregisterCollisionComponent(getId());
}

QRectF CollisionComponent::getBoundingBox() const
{
    return getOwnerProperty("boundingBox").toRectF();
}

QPointF CollisionComponent::getPosition() const
{
    return getOwnerProperty("position").toPointF();
}
