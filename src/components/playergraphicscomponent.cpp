#include "playergraphicscomponent.h"
#include "gameobject.h"

#include <QPointF>
#include <QVariant>
#include <GL/glew.h>

#include "gameworld.h"

PlayerGraphicsComponent::PlayerGraphicsComponent(QObject *parent)
    : GraphicsComponent(parent)
    , accelerating(false)
{
}

void PlayerGraphicsComponent::draw()
{
    static const float PI = 3.14159f;
    QPointF position = getOwnerProperty("position").toPointF();
    float rotation = getOwnerProperty("rotation").toFloat();

    glPushMatrix();

        glTranslatef(position.x(), position.y(), 0.0f);
        glRotatef(rotation * 180.0f / PI, 0.0f, 0.0f, 1.0f);

        if (accelerating)
        {
            drawAcceleration();
            accelerating = false;
        }

        drawShip();

        glColor3f(0.9f, 0.2f, 0.0f);

        glPopMatrix();
}

void PlayerGraphicsComponent::subscribeToMessages()
{
    subscribeToMessage("accelerating");
}

void PlayerGraphicsComponent::receivedMessage(const QString &message, const QVariantMap &payload)
{
    if (message == "accelerating")
    {
        accelerating = true;
    }
}

void PlayerGraphicsComponent::drawShip()
{
    glPushMatrix();

        glPushMatrix();
            glScalef(0.6f, -1.5f, 1.0f);
            glColor3f(0.3f, 0.3f, 0.3f);
            drawShipVertices();
        glPopMatrix();

        glColor3f(0.6f, 0.6f, 0.6f);
        glScalef(0.9f, 1.0f, 1.0f);
        drawShipVertices();

        glPushMatrix();
            glScalef(1.0f, 0.5f, 1.0f);
            glColor3f(0.8f, 0.8f, 0.8f);
            drawShipVertices();
        glPopMatrix();

        glScalef(0.4f, 0.5f, 1.0f);
        glTranslatef(-0.8f, 0.0f, 0.0f);
        glColor3f(0.0f, 0.5f, 0.8f);
        drawShipVertices();

    glPopMatrix();
}

void PlayerGraphicsComponent::drawShipVertices()
{
    glBegin(GL_TRIANGLES);
        glVertex3f(-1.0f,  1.0f, 0.0f);
        glVertex3f(1.0f,  0.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, 0.0f);
    glEnd();
}

void PlayerGraphicsComponent::drawAcceleration()
{
    glPushMatrix();

    glTranslatef(-0.4f, 0.0f, 0.0f);
    glScalef(1.0f, 0.5f, 1.0f);
    glColor3f(0.8f, 0.0f, 0.2f);

    drawShipVertices();

    glScalef(1.0f, 0.6f, 1.0f);
    glColor3f(1.0f, 0.6f, 0.0f);
    drawShipVertices();

    glPopMatrix();
}
