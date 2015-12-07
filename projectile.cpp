#include "projectile.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <typeinfo>
#include "enemy.h"
#include "enemy3.h"
#include "score.h"
#include <QPixmap>
#include <QFont>


Projectile::Projectile(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    //Draw Item
    setPixmap(QPixmap(":/images/laserGreen10.png"));

    //Connect
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    //Speed of bullet
    timer->start(50);


}


void Projectile::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        //Set collision to enemy one and 3
        if(typeid(*(colliding_items[i])) == typeid(Enemy) || (typeid(*(colliding_items[i])) == typeid(Enemy3)))
        {
            //Increase Score
            //Need to call the score object

            //Currently crashing program
            //score()->increase();

           //returnScore();


            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            //Now delete object
            delete colliding_items[i];
            delete this;

            return;
        }

        //set collision to enemy two
    }

    //Move the Projectile
    setPos(x(),y() - 10);


    //If the bullet goes off screen delete it
    //Need to find out the height of the bullet
    if(pos().y() + 20  < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
