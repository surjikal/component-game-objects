#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

#include <QHash>
#include <QKeyEvent>
#include "components/component.h"
#include <memory>

class InputSystem : public QObject
{
    Q_OBJECT

public:
    explicit InputSystem(QObject *parent = 0);
    void registerComponent(const std::shared_ptr<Component>& component);

    bool isKeyPressed(Qt::Key key);

protected:
    virtual bool eventFilter(QObject *object, QEvent *event);
    QHash<int, bool> keyboardState;
};

#endif // INPUTSYSTEM_H
