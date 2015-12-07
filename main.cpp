#include "mainwindow.h"
#include <QApplication>
#include <QPixmap>
#include <QLabel>
#include "score.h"

Score *score;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    return a.exec();
}
