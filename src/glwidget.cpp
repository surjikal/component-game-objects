#include "glwidget.h"
#include <QCoreApplication>
#include <QKeyEvent>
#include <QDebug>

GLWidget::GLWidget( QWidget* parent )
    : QGLWidget( parent )
{
}

void GLWidget::initializeGL()
{
    QGLFormat glFormat = QGLWidget::format();
    if ( !glFormat.sampleBuffers() ) {
        qWarning() << "Could not enable sample buffers";
    }

    // Set the clear color to black
    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
}

void GLWidget::resizeGL( int width, int height )
{
    glViewport( 0, 0, width, qMax( height, 1 ) );
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glScalef(0.05f, 0.05f, 0.05f);

    emit drawComponents();
}

void GLWidget::keyPressEvent( QKeyEvent* e )
{
    switch ( e->key() )
    {
        case Qt::Key_Escape:
            QCoreApplication::instance()->quit();
            break;

        default:
            QGLWidget::keyPressEvent( e );
    }
}

void GLWidget::paintEvent(QPaintEvent* /* event */)
{
    // nop
}

void GLWidget::draw()
{
    updateGL();
}
