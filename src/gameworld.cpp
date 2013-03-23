#include "gameworld.h"

#include <QVariant>

#include "gameobject.h"
#include "gameobjectinstantiator.h"


GameWorld::GameWorld(QObject *parent)
    : QObject(parent)
{
}

GameWorld::~GameWorld()
{
    foreach(std::shared_ptr<GameObject> gameObject, gameObjects)
    {
        gameObject->cleanup();
    }

    gameObjects.clear();
}

void GameWorld::start()
{
    initGameObjects();
}

void GameWorld::update()
{
    gameObjects.append(gameObjectsToAdd);
    gameObjectsToAdd.clear();

    foreach(std::shared_ptr<GameObject> gameObject, gameObjects)
    {
        gameObject->update(*this);
    }

    foreach(std::shared_ptr<GameObject> gameObject, gameObjectsToDelete)
    {
        int idx = gameObjects.indexOf(gameObject);
        gameObjects.removeAt(idx);
    }

    gameObjectsToDelete.clear();
}


void GameWorld::registerGameObject(const std::shared_ptr<GameObject>& gameObject)
{
    gameObjectsToAdd.append(gameObject);
    gameObject->setGameWorld(this);
}

void GameWorld::markGameObjectForDeletion(const std::shared_ptr<GameObject>& gameObject)
{
    gameObjectsToDelete.append(gameObject);
}

void GameWorld::initGameObjects()
{
    GameObjectInstantiator instantiator;

    std::shared_ptr<GameObject> spaceShip = instantiator.instantiate("SpaceShip");
    registerGameObject(spaceShip);

    std::shared_ptr<GameObject> asteroid = instantiator.instantiate("Asteroid");
    registerGameObject(asteroid);

    asteroid->setProperty("velocity", QPointF(0.2, 0.01));
    asteroid->setProperty("position", QPointF(-2.0, 3.0));
}


bool GameWorld::isObjectOutOfBounds(const std::shared_ptr<GameObject>& gameObject)
{
    QPointF position = gameObject->property("position").toPointF();

    return !getBounds().contains(position);
}


QRectF GameWorld::getBounds()
{
    static QRectF bounds(-20.0, -20.0, 40.0f, 40.0f);

    return bounds;
}
