#-------------------------------------------------
#
# Project created by QtCreator 2017-05-26T22:11:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Stalingrad_vol2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        dialog.cpp \
    element.cpp \
    movable.cpp \
    aggressor.cpp \
    weapon.cpp \
    bullet.cpp \
    board.cpp \
    gamemanager.cpp \
    shooter.cpp \
    pistol.cpp \
    player.cpp \
    draw.cpp \
    bead.cpp \
    team.cpp \
    soldier.cpp \
    sniper.cpp \
    tower.cpp \
    ground.cpp \
    box.cpp \
    bazookabullet.cpp \
    bazooka.cpp

HEADERS += \
        dialog.h \
    element.h \
    movable.h \
    aggressor.h \
    weapon.h \
    bullet.h \
    board.h \
    gamemanager.h \
    shooter.h \
    pistol.h \
    player.h \
    draw.h \
    xy.h \
    bead.h \
    team.h \
    soldier.h \
    sniper.h \
    tower.h \
    ground.h \
    box.h \
    bazookabullet.h \
    bazooka.h

FORMS += \
        dialog.ui
