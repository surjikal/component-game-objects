#include "outofboundscomponent.h"
#include "gameworld.h"

OutOfBoundsComponent::OutOfBoundsComponent(QObject *parent)
    : Component(parent)
{
}

void OutOfBoundsComponent::update(GameWorld& gameWorld)
{
    QRectF bounds = gameWorld.getBounds();
    QPointF position = getOwnerProperty("position").toPointF();

    bool isOutOfBounds = !bounds.contains(position);

    if (isOutOfBounds)
    {
        sendMessage("out-of-bounds");
    }
}
