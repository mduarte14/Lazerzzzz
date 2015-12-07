#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QImage>
#include <QBrush>
#include "enemy.h"
#include "enemy2.h"
#include "enemy3.h"
#include "User.h"
#include "highscores.h"
#include "health.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Set UI LOGO on
    ui->TitleLogo->setPixmap(QPixmap(":/images/logo.png"));

    //Set game background
    //Setting Background image for TitleScreen Ui - Miguel
    QPixmap bg(":/images/BG.png");
    bg = bg.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bg);
    this->setPalette(palette);


    //Create scene
    scene = new QGraphicsScene(this);

    //Set this view method to this scene in ui
    ui->graphicsView->setScene(scene);

    //Set the background of the
    scene->setBackgroundBrush(QBrush(QImage(":/images/MainBG.png")));

    //create the player and add him to the scene
    User *user = new User();

    //add the score into the second screen
    //Second QGraphicsScene will hold Score and health bars


    scene2 = new QGraphicsScene(this);
    ui->graphicsView_2->setScene(scene2);
    ui->graphicsView_2->setFixedSize(256,192);
    scene2->setSceneRect(0,0,256,192);

    score = new Score();
    scene2->addItem(score);

    //Move the health screen object


    health = new Health();
    health->setPos(health->x(),health->y() + 50);
    scene2->addItem(health);

    //Now add item into scene
    scene->addItem(user);

    //Make sure the scene does not grow
    ui->graphicsView->setFixedSize(401,551);
    scene->setSceneRect(0,0,401,551);

    //Need to take into account the pixel size
    //Set the players position
    user->setPos(180,451);

    //Make item focused
    user->setFlag(QGraphicsItem::ItemIsFocusable);
    user->setFocus();

    //Spawn enemy 1
    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),user,SLOT(spawn()));
    timer->start(2000);

    //Spawn enemy 3
    QTimer *timer3 = new QTimer();
    QObject::connect(timer3,SIGNAL(timeout()),user,SLOT(spawn2()));
    timer->start(3000);

}

MainWindow::~MainWindow()
{
    //Destructor
    delete ui;
}

void MainWindow::on_QuitGame_clicked()
{
    //Delete Button To quite game
    QApplication::quit();
}

void MainWindow::on_highScores_clicked()
{
    //Open Title screen through modal approach - Miguel
    HighScores hscores;
    hscores.setModal(true);
    hscores.exec();
}
