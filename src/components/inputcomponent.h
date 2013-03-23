#ifndef INPUTCOMPONENT_H
#define INPUTCOMPONENT_H

#include <QObject>
#include "component.h"
#include "inputsystem.h"

class InputComponent : public Component
{
    Q_OBJECT
public:
    InputComponent(QObject *parent = 0);

    virtual ~InputComponent() = 0;

    static InputSystem* inputSystem;
};

#endif // INPUTCOMPONENT_H
