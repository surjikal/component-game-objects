#ifndef PLAYERINPUTCOMPONENT_H
#define PLAYERINPUTCOMPONENT_H

#include "inputcomponent.h"

class PlayerInputComponent : public InputComponent
{
    Q_OBJECT
public:
    PlayerInputComponent(QObject *parent = 0);

    virtual void update(GameWorld &);
};

#endif // PLAYERINPUTCOMPONENT_H
