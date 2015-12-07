#-------------------------------------------------
#
# Project created by QtCreator 2014-12-08T19:52:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Lazerzzzz
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    projectile.cpp \
    enemy.cpp \
    score.cpp \
    highscores.cpp \
    health.cpp \
    user.cpp \
    enemy2.cpp \
    enemy3.cpp \
    enemy4.cpp

HEADERS  += mainwindow.h \
    projectile.h \
    enemy.h \
    score.h \
    highscores.h \
    health.h \
    User.h \
    enemy2.h \
    enemy3.h \
    enemy4.h

FORMS    += mainwindow.ui \
    highscores.ui

RESOURCES += \
    res.qrc
