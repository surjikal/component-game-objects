#include "asteroidgraphicscomponent.h"

#include <GL/glew.h>
#include "gameobject.h"

AsteroidGraphicsComponent::AsteroidGraphicsComponent(QObject *parent)
    : GraphicsComponent(parent)
{
}

void AsteroidGraphicsComponent::draw()
{
    static const float PI = 3.14159f;
    QPointF position = getOwnerProperty("position").toPointF();
    float rotation = getOwnerProperty("rotation").toFloat();

    glPushMatrix();

        glTranslatef(position.x(), position.y(), 0.0f);
        glRotatef(rotation * 180.0f / PI, 0.0f, 0.0f, 1.0f);

        glColor3f(0.9f, 0.9f, 0.6f);

        glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

        glBegin(GL_TRIANGLE_FAN);
            glVertex3f(-1.0f, -0.5f, 0.0f);    // A
            glVertex3f( 1.0f, -0.5f, 0.0f);    // B
            glVertex3f( 0.0f,  0.5f, 0.0f);    // C
            glVertex3f(-1.5f,  0.0f, 0.0f);    // D
            glVertex3f(-1.8f, -1.0f, 0.0f);    // E
            glVertex3f( 0.2f, -1.5f, 0.0f);    // F
            glVertex3f( 1.0f, -0.5f, 0.0f);    // G
        glEnd();

        glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );

    glPopMatrix();
}
