#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "health.h"

class Enemy: public QObject, public QGraphicsPixmapItem
{
    //Macro
    Q_OBJECT
public:
    Enemy(QGraphicsItem *parent=0);
public slots:
    void move();

};
#endif // ENEMY_H
