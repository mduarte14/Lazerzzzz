#ifndef Enemy4_H
#define Enemy4_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "health.h"

class Enemy4: public QObject, public QGraphicsPixmapItem
{
    //Macro
    Q_OBJECT
public:
    Enemy4(QGraphicsItem *parent=0);
public slots:
    void move3();

};
#endif // Enemy4_H
