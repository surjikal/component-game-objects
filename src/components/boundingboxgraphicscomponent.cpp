#include "boundingboxgraphicscomponent.h"

#include <GL/glew.h>
#include <QPointF>
#include <QVariant>

BoundingBoxGraphicsComponent::BoundingBoxGraphicsComponent(QObject *parent)
    : GraphicsComponent(parent)
{
}

void BoundingBoxGraphicsComponent::init()
{
}

void BoundingBoxGraphicsComponent::draw()
{
    QRectF boundingBox = getOwnerProperty("boundingBox").toRectF();
    QPointF position = getOwnerProperty("position").toPointF();

    glPushMatrix();

        glColor3f(1.0f, 1.0f, 0.0f);

        glTranslatef(position.x(), position.y(), 0.0);

        glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

        glBegin(GL_QUADS);
            glVertex3f(boundingBox.left(),  boundingBox.top(), 0.0f);
            glVertex3f(boundingBox.right(), boundingBox.top(), 0.0f);
            glVertex3f(boundingBox.right(), boundingBox.bottom(), 0.0f);
            glVertex3f(boundingBox.left(),  boundingBox.bottom(), 0.0f);
        glEnd();

        glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
    glPopMatrix();
}
