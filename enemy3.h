#ifndef Enemy3_H
#define Enemy3_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "health.h"

class Enemy3: public QObject, public QGraphicsPixmapItem
{
    //Macro
    Q_OBJECT
public:
    Enemy3(QGraphicsItem *parent=0);
public slots:
    void move2();

};
#endif // Enemy3_H
