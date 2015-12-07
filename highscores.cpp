#include "highscores.h"
#include "ui_highscores.h"
#include <QtCore>

void write();
void read();

HighScores::HighScores(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HighScores)
{
    ui->setupUi(this);

    //Set game background
    //Setting Background image for TitleScreen Ui - Miguel
    QPixmap bg(":/images/BG.png");
    bg = bg.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bg);
    this->setPalette(palette);
}

HighScores::~HighScores()
{
    delete ui;
}


void HighScores::on_QuitGame_clicked()
{
    close();
}



void Write()
{
    QFile file(":/images/scores.txt");

    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&file);

        //stream << "Hello\r\n";
        //stream << "World\r\n";

        stream.flush();
        file.close();
        qDebug() << "File has written" << endl;

    }
}

void Read()
{
    QFile file(":/images/scores.txt");

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);

        QString line;
        do
        {
            line = stream.readLine();
            qDebug() << line;

        }while(!line.isNull());

        file.close();
        qDebug() << "File has been read" << endl;

    }
}

