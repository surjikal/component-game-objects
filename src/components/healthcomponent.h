#ifndef HEALTHCOMPONENT_H
#define HEALTHCOMPONENT_H

#include "component.h"
#include <QVariant>


class HealthComponent : public Component
{
    Q_OBJECT

public:
    HealthComponent(QObject *parent = 0);

public slots:
    virtual void injectPropertiesInOwner(const QVariantMap& arguments = QVariantMap());

private:
    float health;

};

#endif // HEALTHCOMPONENT_H
