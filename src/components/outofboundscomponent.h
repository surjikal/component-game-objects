#ifndef OUTOFBOUNDSCOMPONENT_H
#define OUTOFBOUNDSCOMPONENT_H

#include "component.h"


class OutOfBoundsComponent : public Component
{
    Q_OBJECT
public:
    OutOfBoundsComponent(QObject* parent = 0);

public slots:
    virtual void update(GameWorld& gameWorld);
};

#endif // OUTOFBOUNDSCOMPONENT_H
