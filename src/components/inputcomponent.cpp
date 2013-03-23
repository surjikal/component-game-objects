#include "inputcomponent.h"

InputSystem* InputComponent::inputSystem;

InputComponent::InputComponent(QObject *parent)
    : Component(parent)
{
}

InputComponent::~InputComponent()
{
}
