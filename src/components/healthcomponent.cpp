#include "healthcomponent.h"
#include "gameobject.h"

#include <QVariant>

HealthComponent::HealthComponent(QObject *parent)
    : Component(parent)
    , health(100)
{

}

void HealthComponent::injectPropertiesInOwner(const QVariantMap& arguments)
{
    setOwnerProperty("health", arguments["health"]);
}
