#ifndef WRAPAROUNDCOMPONENT_H
#define WRAPAROUNDCOMPONENT_H

#include "component.h"

class WrapAroundComponent : public Component
{
    Q_OBJECT
public:
    WrapAroundComponent(QObject *parent = 0);

public slots:
    virtual void subscribeToMessages();
    virtual void receivedMessage(const QString& type, const QVariantMap& payload = QVariantMap());


private:

    // Function taken from:
    // http://www-graphics.stanford.edu/~tolis/toli/software/asteroids/
    float wrap(float value, float halfLimit);
};

#endif // WRAPAROUNDCOMPONENT_H
