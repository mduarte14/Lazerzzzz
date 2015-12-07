#ifndef User_H
#define User_H

#include <QGraphicsPixmapItem>
#include <QObject>


class User: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    User(QGraphicsItem *parent = 0);
    void keyPressEvent(QKeyEvent *event);

public slots:

    void spawn();
    void spawn2();

};

#endif // User_H
