#ifndef GAMEOBJECTDESCRIPTOR_H
#define GAMEOBJECTDESCRIPTOR_H

#include <QString>
#include <QList>
#include <memory>

#include "componentdescriptor.h"

class GameObjectDescriptor {
public:
    QString name;
    QList<std::shared_ptr<ComponentDescriptor> > components;
    QList<QString> properties;
};

#endif // GAMEOBJECTDESCRIPTOR_H
