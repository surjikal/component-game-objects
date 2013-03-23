#include "shootcomponent.h"

#include <QList>
#include <QPointF>
#include <QVariant>
#include <qmath.h>

#include "gameworld.h"


ShootComponent::ShootComponent(QObject *parent)
    : Component(parent)
{
}

void ShootComponent::subscribeToMessages()
{
    subscribeToMessage("shoot");
}

void ShootComponent::initialize(const QVariantMap &arguments)
{
    projectileSpeed = arguments["projectileSpeed"].toFloat();
    typeEmitted = arguments["projectileType"].toString();
}

void ShootComponent::receivedMessage(const QString& message, const QVariantMap& payload)
{
    if (message == "shoot")
    {
        emitProjectile();
    }
}

void ShootComponent::emitProjectile()
{
    float rotation = getOwnerProperty("rotation").toFloat();
    QPointF position = getOwnerProperty("position").toPointF();
    QPointF velocity(projectileSpeed * qCos(rotation), projectileSpeed * qSin(rotation));

    std::shared_ptr<GameObject> projectile = instantiator.instantiate(typeEmitted);
    projectile->setProperty("position", position);
    projectile->setProperty("rotation", rotation);
    projectile->setProperty("velocity", velocity);
    projectile->setProperty("speed", projectileSpeed);

    getOwner()->getGameWorld()->registerGameObject(projectile);
}
