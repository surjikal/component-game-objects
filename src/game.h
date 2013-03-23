#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <memory>

class GameWorld;
class InputSystem;
class CollisionSystem;

class Game : public QObject
{
    Q_OBJECT

public:
    Game(QObject *parent = 0);

    void start();
    void timerEvent(QTimerEvent* event);

signals:
    void draw();

private:
    std::shared_ptr<CollisionSystem> collisionSystem;
    std::shared_ptr<GameWorld> gameWorld;
    std::shared_ptr<InputSystem> inputSystem;

    int updateTimerId;
    int drawTimerId;
};

#endif // GAME_H
