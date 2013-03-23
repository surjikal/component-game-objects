#include "graphicscomponent.h"
#include "glwidget.h"

GLWidget* GraphicsComponent::glWidget;

GraphicsComponent::GraphicsComponent(QObject *parent)
    : Component(parent)
{
    QObject::connect(glWidget, SIGNAL(drawComponents()), this, SLOT(draw()));
}

GraphicsComponent::~GraphicsComponent()
{
}
