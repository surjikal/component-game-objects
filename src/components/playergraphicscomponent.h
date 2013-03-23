#ifndef PLAYERGRAPHICSCOMPONENT_H
#define PLAYERGRAPHICSCOMPONENT_H

#include "graphicscomponent.h"


class PlayerGraphicsComponent : public GraphicsComponent
{
    Q_OBJECT
public:
    PlayerGraphicsComponent(QObject *parent = 0);

public slots:
    virtual void draw();
    virtual void subscribeToMessages();
    virtual void receivedMessage(const QString& message, const QVariantMap& payload);

private:
    bool accelerating;
    void drawShip();
    void drawShipVertices();
    void drawAcceleration();
};

#endif // PLAYERGRAPHICSCOMPONENT_H
