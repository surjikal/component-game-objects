#include "wraparoundcomponent.h"
#include "gameworld.h"
#include "math.h"

WrapAroundComponent::WrapAroundComponent(QObject *parent)
    : Component(parent)
{
}

void WrapAroundComponent::subscribeToMessages()
{
    subscribeToMessage("out-of-bounds");
}

void WrapAroundComponent::receivedMessage(const QString& type, const QVariantMap& /* payload */)
{
    if (type == "out-of-bounds")
    {
        float worldHalfWidth = getOwner()->getGameWorld()->getBounds().width() / 2.0f;
        QPointF position = getOwnerProperty("position").toPointF();
        setOwnerProperty("position", QPointF(wrap(position.x(), worldHalfWidth),
                                             wrap(position.y(), worldHalfWidth)));
    }
}

float WrapAroundComponent::wrap(float value, float halfLimit)
{
    if (value>0.0) return fmodf(value+halfLimit,2.0*halfLimit)-halfLimit;
    else return -fmodf(-value+halfLimit,2.0*halfLimit)+halfLimit;
}
