#ifndef COLLISIONSYSTEM_H
#define COLLISIONSYSTEM_H

#include <QMap>
#include <QObject>

class CollisionComponent;

class CollisionSystem : public QObject
{
    Q_OBJECT

public:
    CollisionSystem(QObject* parent = 0);

    void registerCollisionComponent(CollisionComponent* physicsComponent);
    void unregisterCollisionComponent(const unsigned int& id);

    void resolveCollisions();
    void handleCollisionBetween(const unsigned int& id, const unsigned int& otherId);

private:
    QMap<unsigned int, CollisionComponent*> registeredCollisionComponents;
};

#endif // COLLISIONSYSTEM_H
