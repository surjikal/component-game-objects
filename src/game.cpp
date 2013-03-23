#include "game.h"
#include "gameworld.h"

#include "components/collisioncomponent.h"
#include "collisionsystem.h"
#include <QDebug>


Game::Game(QObject* parent)
    : QObject(parent)
    , collisionSystem(new CollisionSystem)
    , gameWorld(new GameWorld)
    , updateTimerId(-1)
    , drawTimerId(-1)
{
    CollisionComponent::collisionSystem = collisionSystem;
}

void Game::start()
{
    gameWorld->start();

    drawTimerId = startTimer(17); // ~ 60fps
    updateTimerId = startTimer(30);
}

void Game::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == drawTimerId)
    {
        emit draw();
    }

    else if (event->timerId() == updateTimerId)
    {
        gameWorld->update();
        collisionSystem->resolveCollisions();
    }
}
