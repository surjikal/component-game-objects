#ifndef ASTEROIDGRAPHICSCOMPONENT_H
#define ASTEROIDGRAPHICSCOMPONENT_H

#include "graphicscomponent.h"

class AsteroidGraphicsComponent : public GraphicsComponent
{
    Q_OBJECT
public:
    AsteroidGraphicsComponent(QObject *parent = 0);

public slots:
    virtual void draw();
};

#endif // ASTEROIDGRAPHICSCOMPONENT_H
