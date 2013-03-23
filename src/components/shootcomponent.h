#ifndef SHOOTCOMPONENT_H
#define SHOOTCOMPONENT_H

#include <QObject>
#include <QPointF>
#include <memory>

#include "component.h"
#include "gameobject.h"
#include "gameobjectinstantiator.h"

class ShootComponent : public Component
{
    Q_OBJECT
public:
    ShootComponent(QObject* parent = 0);

    virtual void subscribeToMessages();
    virtual void initialize(const QVariantMap& arguments);
    virtual void receivedMessage(const QString& message, const QVariantMap& payload);

private:
    QString typeEmitted;
    float projectileSpeed;

    GameObjectInstantiator instantiator;

    void emitProjectile();
};

#endif // SHOOTCOMPONENT_H
