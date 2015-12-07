#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>
#include "health.h"

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{

    //Set random position for enemy spawn point
    int random = rand() % 301;
    setPos(random,0);
    //Draw Item
    setPixmap(QPixmap(":/images/enemyBlue4.png"));

    //Connect
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    //Speed of bullet
    timer->start(50);
}

void Enemy::move()
{
    //Move the enemy
    setPos(x(),y() + 5);

    //Decrease health if it reaches the end of game board
    if(pos().y()  < 0 )
    {
        //health.decrease();
        scene()->removeItem(this);
        delete this;
    }

}
