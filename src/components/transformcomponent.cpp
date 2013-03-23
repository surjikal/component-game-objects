#include "transformcomponent.h"
#include "gameobject.h"
#include "gameworld.h"

#include <QRectF>
#include <QPointF>
#include <QVariant>

TransformComponent::TransformComponent(QObject *parent)
    : Component(parent)
{
}

void TransformComponent::injectPropertiesInOwner(const QVariantMap& arguments)
{
    setOwnerProperty("position", QPointF(0.0, 0.0));
    setOwnerProperty("rotation", 0.0);
    setOwnerProperty("scale", 0.0);
}
