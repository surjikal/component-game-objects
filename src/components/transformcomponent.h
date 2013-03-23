#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include "component.h"

class TransformComponent : public Component
{
    Q_OBJECT
public:
    TransformComponent(QObject *parent = 0);

public slots:
    virtual void injectPropertiesInOwner(const QVariantMap& arguments = QVariantMap());
    // virtual void update(GameWorld& gameWorld);
};

#endif // TRANSFORMCOMPONENT_H
