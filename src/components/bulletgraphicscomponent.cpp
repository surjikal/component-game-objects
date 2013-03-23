#include "bulletgraphicscomponent.h"

#include <GL/glew.h>
#include <QPointF>
#include <QVariant>

BulletGraphicsComponent::BulletGraphicsComponent(QObject *parent)
    : GraphicsComponent(parent)
{
}

void BulletGraphicsComponent::draw()
{
    static const float PI = 3.14159f;
    QPointF position = getOwnerProperty("position").toPointF();
    float rotation = getOwnerProperty("rotation").toFloat();

    glPushMatrix();

        glTranslatef(position.x(), position.y(), -0.1f);

        glRotatef(rotation * 180.0f / PI, 0.0f, 0.0f, 1.0f);
        glTranslatef(1.0f, 0.0f, 0.0f);
        glColor3f(0.0f, 1.0f, 1.0f);

        glColor3f(0.6f, 1.0f, 1.0f);
        glBegin(GL_LINES);
            glVertex3f(-1.0f, 0.0f, 0.0f);
            glVertex3f(1.0f, 0.0f, 0.0f);
        glEnd();

    glPopMatrix();
}
