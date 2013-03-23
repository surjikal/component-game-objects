#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <QObject>
#include <QList>
#include <QRectF>
#include <QElapsedTimer>

#include <memory>

#include "glwidget.h"
#include "gameobject.h"

class GameWorld : public QObject, public std::enable_shared_from_this<GameWorld>
{
    Q_OBJECT
public:
    explicit GameWorld(QObject *parent = 0);
    ~GameWorld();
    static QRectF getBounds();

public slots:
    void start();
    void update();

    void registerGameObject(const std::shared_ptr<GameObject>& gameObject);
    void markGameObjectForDeletion(const std::shared_ptr<GameObject>& gameObject);
    bool isObjectOutOfBounds(const std::shared_ptr<GameObject>& gameObject);

private:
    QList<std::shared_ptr<GameObject> > gameObjects;
    QList<std::shared_ptr<GameObject> > gameObjectsToAdd;
    QList<std::shared_ptr<GameObject> > gameObjectsToDelete;

    void initGameObjects();
};

#endif // GAMEWORLD_H
