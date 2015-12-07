#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QLabel>
#include <QtGui>
#include <QtCore>
#include <QGraphicsScene>
#include "User.h"
#include "score.h"
#include "health.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    //Score *score = new Score;



    ~MainWindow();

private slots:
    void on_QuitGame_clicked();

    void on_highScores_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsScene *scene2;
    QGraphicsEllipseItem *ellipse;
    QGraphicsRectItem *rectangle;

    //Need to pass these over to projectiles inorder for them to be functional
    Score *score;
    Health *health;


};

#endif // MAINWINDOW_H
