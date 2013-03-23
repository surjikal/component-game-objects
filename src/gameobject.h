#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QObject>
#include <QMap>
#include <QMultiHash>
#include <QList>
#include <QString>
#include <QVariant>
#include <memory>


class GameWorld;
class Component;

class GameObject : public QObject, public std::enable_shared_from_this<GameObject>
{
    Q_OBJECT

public:
    explicit GameObject(QObject *parent = 0);
    ~GameObject();

    // Returns true if both IDs are equal.
    bool operator == (const GameObject& gameObject);
    bool operator != (const GameObject& gameObject);

    typedef unsigned int GameObjectId;

public slots:
    GameObjectId getId() const;
    GameWorld* getGameWorld() const;
    void setGameWorld(GameWorld* gameWorld);

    void addComponent(const std::shared_ptr<Component>& component, const QVariantMap& arguments = QVariantMap());
    void removeComponent(const QString& name);

    void subscribeToMessage(const QString& message, const std::shared_ptr<Component>& component);

    void sendMessage(const QString &type, const QVariantMap& payload = QVariantMap());

    void update(GameWorld& gameWorld);

    // On the next update, clears its components and tells its game world that it should be deleted.
    void markForDeletion();

    // Called by game world when it is destroyed. This will be removed in a future version.
    void cleanup();

private:
    static unsigned int NextId;
    const unsigned int ID;
    bool markedForDeletion;

    GameWorld* gameWorld;

    QMap<QString, std::shared_ptr<Component> > components;
    QMultiMap<QString, std::shared_ptr<Component> > messageMapping;

    void unsubscribeToMessages(const QString& componentName);
};

#endif // GAMEOBJECT_H
