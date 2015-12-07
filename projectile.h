#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include "score.h"
#include "mainwindow.h"
#include <QMainWindow>

class Projectile: public QObject, public QGraphicsPixmapItem
{
    //Macro
    Q_OBJECT
public:
    Projectile(QGraphicsItem * parent = 0);

    //bool returnScore(bool);

public slots:
    void move();

};

#endif // PROJECTILE_H
