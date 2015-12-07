#include "health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    health = 10;

    //Draw The text score
    setPlainText("HEALTH: " + QString::number(health));
    setDefaultTextColor(Qt::white);
    setFont(QFont("terminal",25));
}

void Health::increase()
{
    //Simply iterate the score
    health--;

    //Draw The text score
    setPlainText("HEALTH: " + QString::number(health));
    setDefaultTextColor(Qt::white);
    setFont(QFont("terminal",25));
}

int Health::getHealth()
{
    return health;
}
