#include "User.h"
#include "projectile.h"
#include <QDebug>
#include <QKeyEvent>
#include "enemy.h"
#include "enemy2.h"
#include <QGraphicsScene>
#include "enemy3.h"
#include "enemy4.h"

User::User(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/playerShip2_red.png"));

}

void User::keyPressEvent(QKeyEvent *event)
{
    //qDebug()<< "Key Input";

    if(event->key() == Qt::Key_Left)
    {
        if(pos().x() > 0)
        setPos(x()- 10, y());
    }
    else if(event->key() == Qt::Key_Right)
    {
        if(pos().x() + 100 < 401)
        setPos(x() + 10, y());
    }
    else if(event->key() == Qt::Key_Up)
    {
        setPos(x() , y() - 10);
    }
    else if(event->key() == Qt::Key_Down)
    {
        setPos(x(), y() + 10);
    }
    else if(event->key() == Qt::Key_Space)
    {

        //Create the Bullet
        Projectile * projectile = new Projectile();


        projectile->setPos(x(),y());
        scene()->addItem(projectile);
    }
}



void User::spawn()
{
    //Spawn enemy
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);

    Enemy2 *enemy2 = new Enemy2();
    scene()->addItem(enemy2);

    Enemy3 *enemy3 = new Enemy3();
    scene()->addItem(enemy3);

    Enemy4 *enemy4 = new Enemy4();
    scene()->addItem(enemy4);
}

//Add second spawning time object for different plane
void User::spawn2()
{
    // Not working
    //spawn enemy
    //Enemy3 *enemy3 = new Enemy3();
    //scene()->addItem(enemy3);
}
