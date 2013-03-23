#include "componentinstantiator.h"

#include <QtAlgorithms>
#include <QDebug>

#include "components/component.h"

QMap<QString, ComponentFactoryInterface*> ComponentInstantiator::Map;

ComponentInstantiator::ComponentInstantiator()
{
}

ComponentInstantiator::~ComponentInstantiator()
{
}

std::shared_ptr<Component> ComponentInstantiator::instantiate(const QString &typeName)
{
    if (!ComponentInstantiator::Map.contains(typeName))
    {
        throw ComponentTypeNotFoundException(typeName);
    }

    std::shared_ptr<Component> component( ComponentInstantiator::Map[typeName]->make() );
    component->setObjectName(typeName);
    return component;
}

void ComponentInstantiator::RemoveRegisteredTypes()
{
    qDeleteAll( ComponentInstantiator::Map.values() );
}

QList<QString> ComponentInstantiator::GetRegisteredComponentTypes()
{
    return Map.keys();
}
