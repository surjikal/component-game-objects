#ifndef INSTANTIATOR_H
#define INSTANTIATOR_H

#include <QMap>
#include <QObject>
#include <QString>
#include <QDebug>
#include <memory>

#include <stdexcept>

#include "componentfactory.h"

class ComponentInstantiator {

public:
    static void RemoveRegisteredTypes();
    static QList<QString> GetRegisteredComponentTypes();

    template<typename ComponentType>
    static void RegisterType( const QString& typeName )
    {
        qDebug() << "Registering component type" << typeName;
        ComponentInstantiator::Map[typeName] = new ComponentFactory<ComponentType>();
    }

    template<typename ComponentType>
    struct ComponentTypeRegistrator
    {
        ComponentTypeRegistrator(const QString& typeName)
        {
            ComponentInstantiator::RegisterType<ComponentType>(typeName);
        }
    };

    ComponentInstantiator();
    ~ComponentInstantiator();

    std::shared_ptr<Component> instantiate(const QString& typeName);

private:
    static QMap<QString, ComponentFactoryInterface*> Map;
};

class ComponentTypeNotFoundException: public std::runtime_error
{
public:
    ComponentTypeNotFoundException(const QString& typeName)
        : std::runtime_error(QString("Could not find component type '%1'").arg(typeName).toStdString())
        , typeName(typeName)
    {}

    virtual ~ComponentTypeNotFoundException() throw() {}

    QString getTypeName() const
    {
        return typeName;
    }

private:
    const QString typeName;
};

#endif // INSTANTIATOR_H
