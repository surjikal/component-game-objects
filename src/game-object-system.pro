#-------------------------------------------------
#
# Project created by QtCreator 2012-03-09T16:10:49
#
#-------------------------------------------------

CONFIG  += c++11
QT      += core gui opengl script
TARGET   = game-object-system
TEMPLATE = app

#unix:LIBS  += -lGLU -lGL -lGLEW
#win32:LIBS += LC:\path\to\libs -lGLEW

#QMAKE_CXXFLAGS += -std=c++0x

INCLUDEPATH += $$(PWD)

SOURCES +=  main.cpp                    \
            mainwindow.cpp              \
            gameobject.cpp              \
            glwidget.cpp                \
            gameworld.cpp               \
            inputsystem.cpp             \
            componentinstantiator.cpp   \
            gameobjectinstantiator.cpp  \
    components/transformcomponent.cpp   \
    components/outofboundscomponent.cpp \
    qscriptgameobjectparser.cpp         \
    game.cpp \
    collisionsystem.cpp \
    components/collisioncomponent.cpp \
    jsedit.cpp \
    components/movementcomponent.cpp


HEADERS  += mainwindow.h             \
            gameobject.h             \
            message.h                \
            glwidget.h               \
            gameworld.h              \
            inputsystem.h            \
            factoryinterface.h       \
            componentfactory.h       \
            componentinstantiator.h  \
            gameobjectinstantiator.h \
            gameobjectdescriptor.h \
    components/transformcomponent.h \
    components/outofboundscomponent.h \
    gameobjectparser.h \
    qscriptgameobjectparser.h \
    componentdescriptor.h \
    game.h \
    collisionsystem.h \
    components/collisioncomponent.h \
    jsedit.h \
    components/movementcomponent.h




################
# Components
################

SOURCES +=  components/component.cpp                 \
            components/healthcomponent.cpp           \
            components/graphicscomponent.cpp         \
            components/playergraphicscomponent.cpp   \
            components/inputcomponent.cpp            \
            components/playerinputcomponent.cpp      \
            components/shootcomponent.cpp            \
            components/bulletgraphicscomponent.cpp   \
            components/asteroidgraphicscomponent.cpp \
            components/wraparoundcomponent.cpp       \
            components/boundingboxgraphicscomponent.cpp


HEADERS +=  components/component.h                 \
            components/healthcomponent.h           \
            components/graphicscomponent.h         \
            components/playergraphicscomponent.h   \
            components/inputcomponent.h            \
            components/playerinputcomponent.h      \
            components/shootcomponent.h            \
            components/bulletgraphicscomponent.h   \
            components/asteroidgraphicscomponent.h \
            components/wraparoundcomponent.h       \
            components/boundingboxgraphicscomponent.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    passthrough.vertex.glsl     \
    passthrough.fragment.glsl \
    game-objects.json

RESOURCES += \
    resources.qrc

