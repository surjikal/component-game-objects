#ifndef COMPONENTFACTORY_H
#define COMPONENTFACTORY_H

#include "factoryinterface.h"

class Component;

class ComponentFactoryInterface {

public:
    virtual ~ComponentFactoryInterface() {}
    virtual std::shared_ptr<Component> make() = 0;
};


template<class ComponentDerivedType>
class ComponentFactory : public ComponentFactoryInterface {

public:
    virtual ~ComponentFactory() {}
    virtual std::shared_ptr<Component> make() {
        return std::shared_ptr<Component>(new ComponentDerivedType());
    }
};

#endif // COMPONENTFACTORY_H
