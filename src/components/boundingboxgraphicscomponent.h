#ifndef BOUNDINGBOXGRAPHICSCOMPONENT_H
#define BOUNDINGBOXGRAPHICSCOMPONENT_H

#include "graphicscomponent.h"
#include "gameobject.h"


class BoundingBoxGraphicsComponent : public GraphicsComponent
{
public:
    BoundingBoxGraphicsComponent(QObject* parent = 0);

    virtual void init();
    virtual void draw();
};

#endif // BOUNDINGBOXGRAPHICSCOMPONENT_H
