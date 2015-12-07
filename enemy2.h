#ifndef Enemy2_H
#define Enemy2_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "health.h"

class Enemy2: public QObject, public QGraphicsPixmapItem
{
    //Macro
    Q_OBJECT
public:
    Enemy2(QGraphicsItem *parent=0);
    int health = 10;
public slots:
    void move();

};

#endif // Enemy2_H
