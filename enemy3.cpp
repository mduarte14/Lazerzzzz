#include "Enemy3.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>
#include "health.h"

Enemy3::Enemy3(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{

    //Set random position for Enemy3 spawn point
    int random = rand() % 301;
    setPos(random,0);
    //Draw Item
    setPixmap(QPixmap(":/images/enemyGreen1.png"));

    //Connect
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move2()));

    //Speed of Enemy
    timer->start(20);
}

void Enemy3::move2()
{
    //Known bug, this is not being called

    //qDebug() << "Enemy spawned";

    //Move the Enemy3
    setPos(x(),y() + 5);

    //Decrease health if it reaches the end of game board
    if(pos().y()  < 0 )
    {
        //health.decrease();
        scene()->removeItem(this);
        delete this;
    }

}
