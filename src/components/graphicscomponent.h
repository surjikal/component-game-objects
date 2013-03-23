#ifndef GRAPHICSCOMPONENT_H
#define GRAPHICSCOMPONENT_H

#include <QGraphicsScene>
#include "component.h"

class GLWidget;
class GameWorld;

class GraphicsComponent : public Component
{
    Q_OBJECT
public:
    GraphicsComponent(QObject *parent = 0);
    ~GraphicsComponent();
    static GLWidget* glWidget; // FIXME: abomination

public slots:
    virtual void draw() = 0;
};

#endif // GRAPHICSCOMPONENT_H
