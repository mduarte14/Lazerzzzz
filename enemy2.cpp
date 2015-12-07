#include "Enemy2.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>
#include <typeinfo>
#include "health.h"

Enemy2::Enemy2(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{

    //Set random position for Enemy2 spawn point
    int random = rand() % 301;
    setPos(random,0);
    //Draw Item
    setPixmap(QPixmap(":/images/meteorBrown_big4.png"));

    //Connect
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    //Speed of bullet
    timer->start(80);
}

void Enemy2::move()
{
    //Move the Enemy2
    setPos(x(),y() + 2);

    //Decrease health if it reaches the end of game board
    if(pos().y()  < 0 )
    {
        //health.decrease();
        scene()->removeItem(this);
        delete this;
    }


    //Attempting to lower health if giant rock damages user, not functional
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for(int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        //Set collision to enemy one and 3
        if(typeid(*(colliding_items[i])) == typeid(Enemy2))
        {

            //If hit by this object decrease health by 1
            Enemy2().health;

            qDebug() << "Health lowered";

        }


    }

}
