#include "movementcomponent.h"
#include "gameworld.h"

#include <QDebug>

MovementComponent::MovementComponent(QObject *parent)
    : Component(parent)
{
}

void MovementComponent::injectPropertiesInOwner(const QVariantMap& arguments)
{
    setOwnerProperty("position", arguments["position"]);
    setOwnerProperty("velocity", arguments["velocity"]);
    setOwnerProperty("speed", arguments["speed"]);
    setOwnerProperty("rotation", arguments["rotation"]);
    setOwnerProperty("acceleration", arguments["acceleration"]);
}

void MovementComponent::update(GameWorld& /* gameWorld */)
{
    QPointF position = getOwnerProperty("position").toPointF();
    QPointF velocity = getOwnerProperty("velocity").toPointF();
    QPointF acceleration = getOwnerProperty("acceleration").toPointF();

    velocity += acceleration;
    position += velocity;

    setOwnerProperty("velocity", velocity);
    setOwnerProperty("position", position);
}
