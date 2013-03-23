#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QGLBuffer>
#include <QGLShaderProgram>
#include <QPaintEvent>
#include <QList>
#include <QDebug>

#include "components/graphicscomponent.h"

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    GLWidget( QWidget* parent = 0 );

signals:
    void drawComponents();

public slots:
    void draw();

protected:
    virtual void initializeGL();
    virtual void resizeGL( int w, int h );
    virtual void paintGL();

    virtual void keyPressEvent( QKeyEvent* e );
    virtual void paintEvent(QPaintEvent*  /* event */);
};

#endif // GLWIDGET_H
