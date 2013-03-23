#ifndef BULLETGRAPHICSCOMPONENT_H
#define BULLETGRAPHICSCOMPONENT_H

#include "graphicscomponent.h"
#include "gameobject.h"


class BulletGraphicsComponent : public GraphicsComponent
{
    Q_OBJECT
public:
    BulletGraphicsComponent(QObject *parent = 0);

    virtual void draw();
};

#endif // BULLETGRAPHICSCOMPONENT_H
