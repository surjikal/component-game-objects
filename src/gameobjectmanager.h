#ifndef GAMEOBJECTMANAGER_H
#define GAMEOBJECTMANAGER_H

#include <QObject>
#include <QMultiHash>
#include <QPair>

class GameObjectManager : public QObject
{
    Q_OBJECT
public:
    explicit GameObjectManager(QObject *parent = 0);
    
signals:
    
public slots:
    void addComponent(GameObject* gameObject, Component* component);

};

#endif // GAMEOBJECTMANAGER_H
