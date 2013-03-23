#ifndef FACTORYINTERFACE_H
#define FACTORYINTERFACE_H

#include <memory>

template <class T>
class FactoryInterface {

public:
    virtual std::shared_ptr<T> make() = 0;
};


template <class Derived, class Base>
class ConcreteFactory : public FactoryInterface<Base> {

public:
    virtual std::shared_ptr<Base> make() {
        return new Derived();
    }
};

#endif // FACTORYINTERFACE_H
