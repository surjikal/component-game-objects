#ifndef PHYSICSCOMPONENT_H
#define PHYSICSCOMPONENT_H

#include <QMap>
#include <QRectF>
#include <memory>

#include "component.h"

class CollisionSystem;
class GameWorld;

class CollisionComponent : public Component
{
    Q_OBJECT
public:
    CollisionComponent(QObject *parent = 0);
    virtual ~CollisionComponent();

    static std::shared_ptr<CollisionSystem> collisionSystem;

public slots:
    virtual void injectPropertiesInOwner(const QVariantMap& arguments = QVariantMap());
    virtual void collidedWith(const std::shared_ptr<GameObject>& gameObject);
    virtual void cleanup();

    QRectF getBoundingBox() const;
    QPointF getPosition() const;

protected:
    //std::shared_ptr<PhysicsWorld> physicsWorld;
};

#endif // PHYSICSCOMPONENT_H
