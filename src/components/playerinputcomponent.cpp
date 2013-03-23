#include "playerinputcomponent.h"

#include "componentinstantiator.h"

#include "gameobject.h"
#include "gameworld.h"

#include <QDebug>
#include <qmath.h>
#include <QVariant>
#include <QPointF>

#define MAX_SPEED 2.0

PlayerInputComponent::PlayerInputComponent(QObject *parent)
    : InputComponent(parent)
{
}

void PlayerInputComponent::update(GameWorld& /* gameWorld */)
{
    static const float PI = 3.14159f;
    static const float RotationStep = 10.0f * PI / 180.0f; // 10 degrees

    QPointF velocity = getOwnerProperty("velocity").toPointF();
    float rotation = getOwnerProperty("rotation").toFloat();

    QPointF direction(qCos(rotation), qSin(rotation));

    if (inputSystem->isKeyPressed(Qt::Key_Up))
    {
        velocity += direction * 0.05;

        velocity.setX( qMin(velocity.x(),  MAX_SPEED) );
        velocity.setX( qMax(velocity.x(), -MAX_SPEED) );
        velocity.setY( qMin(velocity.y(),  MAX_SPEED) );
        velocity.setY( qMax(velocity.y(), -MAX_SPEED) );

        setOwnerProperty("velocity", velocity);

        sendMessage("accelerating");
    }

    if (inputSystem->isKeyPressed(Qt::Key_Left))
    {
        setOwnerProperty("rotation", rotation + RotationStep);
    }

    if (inputSystem->isKeyPressed(Qt::Key_Right))
    {
        setOwnerProperty("rotation", rotation - RotationStep);
    }

    static bool spaceKeyWasPressed = false;
    if (inputSystem->isKeyPressed(Qt::Key_Space))
    {
        if (!spaceKeyWasPressed) {
            sendMessage("shoot");
        }
        spaceKeyWasPressed = true;
    } else {
        spaceKeyWasPressed = false;
    }


    // Just a fun test to demonstrate dynamic insertion and removal
    // of components. In real code, you shouldn't really assume that these
    // components are available, unless you are wrapping them of course.
    static bool downKeyWasPressed = false;
    if (inputSystem->isKeyPressed(Qt::Key_Down))
    {
        if (!downKeyWasPressed)
        {
            static ComponentInstantiator instantiator;
            static int componentIndex = 0;
            static const unsigned int ComponentCount = 3;
            static QString cycleThrough[ComponentCount] = {
                "PlayerGraphicsComponent",
                "AsteroidGraphicsComponent",
                "BulletGraphicsComponent"
            };

            getOwner()->removeComponent(cycleThrough[componentIndex]);
            componentIndex = ++componentIndex % ComponentCount;

            getOwner()->addComponent(
                instantiator.instantiate(cycleThrough[componentIndex])
            );
        }
        downKeyWasPressed = true;
    } else {
        downKeyWasPressed = false;
    }
}
