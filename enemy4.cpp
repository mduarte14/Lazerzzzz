#include "Enemy4.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>
#include "health.h"

Enemy4::Enemy4(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{

    //Set random position for Enemy4 spawn point
    int random = rand() % 301;
    setPos(random,0);
    //Draw Item
    setPixmap(QPixmap(":/images/meteorGrey_tiny1.png"));

    //Connect
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move3()));

    //Speed of Enemy
    timer->start(150);
}

void Enemy4::move3()
{
    //Known bug, this is not being called

    //qDebug() << "Enemy spawned";

    //Move the Enemy4
    //Lets try to move this in a diagonal direction

        setPos(x() ,y() + 1);

    //Decrease health if it reaches the end of game board
    if(pos().y()  < 0 )
    {
        //health.decrease();
        scene()->removeItem(this);
        delete this;
    }

}
