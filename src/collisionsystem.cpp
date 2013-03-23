#include "collisionsystem.h"
#include "components/collisioncomponent.h"

#include <QRectF>
#include <QPair>

CollisionSystem::CollisionSystem(QObject *parent)
    : QObject(parent)
{
}

void CollisionSystem::registerCollisionComponent(CollisionComponent* physicsComponent)
{
    registeredCollisionComponents[physicsComponent->getId()] = physicsComponent;
}

void CollisionSystem::unregisterCollisionComponent(const unsigned int &id)
{
    registeredCollisionComponents.remove(id);
}

void CollisionSystem::resolveCollisions()
{
    QList<QPair<unsigned int, QRectF> > translatedBoundingBoxes;

    foreach(CollisionComponent* physicsComponent, registeredCollisionComponents)
    {
        QRectF boundingBox = physicsComponent->getBoundingBox();
        QPointF position = physicsComponent->getPosition();

        boundingBox.translate(position);

        translatedBoundingBoxes.append(
            QPair<unsigned int, QRectF>(physicsComponent->getId(), boundingBox)
        );
    }

    QPair<unsigned int, QRectF> idBoundingBoxPair;
    QPair<unsigned int, QRectF> otherIdBoundingBoxPair;

    // FIXME: exponential
    foreach(idBoundingBoxPair, translatedBoundingBoxes)
    {
        unsigned int id = idBoundingBoxPair.first;
        QRectF boundingBox = idBoundingBoxPair.second;

        foreach(otherIdBoundingBoxPair, translatedBoundingBoxes)
        {
            unsigned int otherId = otherIdBoundingBoxPair.first;
            if (id == otherId)
            {
                continue;
            }

            QRectF otherBoundingBox = otherIdBoundingBoxPair.second;

            if (boundingBox.intersects(otherBoundingBox))
            {
                handleCollisionBetween(id, otherId);
            }
        }
    }
}

void CollisionSystem::handleCollisionBetween(const unsigned int &id, const unsigned int &otherId)
{
    CollisionComponent* other = registeredCollisionComponents[otherId];
    CollisionComponent* current = registeredCollisionComponents[id];

    // FIXME: Sometimes, current is null. Probably due to multiple collisions with the same item, and item deletes itself during
    // collision handling.
    if (current && other)
    {
        current->collidedWith(other->getOwner());
    }
}
