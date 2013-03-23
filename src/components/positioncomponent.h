#ifndef POSITIONCOMPONENT_H
#define POSITIONCOMPONENT_H

#include <QObject>
#include <QVariant>

#include "component.h"

class PositionComponent : public Component
{
    Q_OBJECT

public:
    explicit PositionComponent(QObject *parent = 0);

public slots:
    virtual void subscribeToMessages();
    virtual void addProperties();
    virtual void receivedMessage(QString message);
    virtual void update();
};

#endif // POSITIONCOMPONENT_H
