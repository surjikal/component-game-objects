#ifndef _H
#define _H

#include "component.h"

class GameWorld;

class MovementComponent: public Component
{
    Q_OBJECT
public:
    MovementComponent(QObject *parent = 0);

public slots:
    virtual void injectPropertiesInOwner(const QVariantMap& arguments = QVariantMap());
    virtual void update(GameWorld &gameWorld);

};

#endif // _H
