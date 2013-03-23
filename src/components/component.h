#ifndef COMPONENT_H
#define COMPONENT_H

#include <QObject>
#include <QVariantMap>

#include <memory>

#include "componentinstantiator.h"

class GameWorld;
class GameObject;

class Component : public QObject, public std::enable_shared_from_this<Component>
{
    Q_OBJECT

public:
    static void RegisterDerivedTypes();
    static unsigned int NextId;

    Component(QObject* parent = 0);
    virtual ~Component() = 0;

public slots:
    unsigned int getId() const;
    QString getName() const;

    std::shared_ptr<GameObject> getOwner() const;
    void setOwner(const std::shared_ptr<GameObject>& owner);

    void initialize(const std::shared_ptr<GameObject>& owner, const QVariantMap& arguments = QVariantMap());

    virtual void receivedMessage(const QString& /* type */, const QVariantMap& /* payload */ = QVariantMap()) {}
    virtual void update(GameWorld& /* gameWorld */) {}

protected:
    virtual void initialize(const QVariantMap& /* arguments */ = QVariantMap()) {}
    virtual void injectPropertiesInOwner(const QVariantMap& /* arguments */ = QVariantMap()) {}
    virtual void subscribeToMessages() {}

    void sendMessage(const QString& message, const QVariantMap& payload = QVariantMap());
    void subscribeToMessage(const QString& message);

    void setOwnerProperty(const char* name, const QVariant& value);
    QVariant getOwnerProperty(const char* name) const;

    void markOwnerForDeletion();
    virtual void cleanup();

private:
    unsigned int ID;
    std::shared_ptr<GameObject> owner;
};

#endif // COMPONENT_H
