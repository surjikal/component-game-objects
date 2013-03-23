#include "inputsystem.h"
#include <QKeyEvent>
#include <QDebug>

InputSystem::InputSystem(QObject* parent)
    : QObject(parent)
{
}

void InputSystem::registerComponent(const std::shared_ptr<Component>& component)
{
}

bool InputSystem::isKeyPressed(Qt::Key key)
{
    return keyboardState.contains(key) && keyboardState[key];
}

bool InputSystem::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        keyboardState[keyEvent->key()] = true;

    } else if (event->type() == QEvent::KeyRelease) {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        keyboardState[keyEvent->key()] = false;
    }

    return QObject::eventFilter(object, event);
}
