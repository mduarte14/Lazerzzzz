#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    score= 0;

    //Draw The text score
    setPlainText("SCORE: " + QString::number(score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("terminal",25));
}

void Score::increase()
{
    //Simply iterate the score
    score++;

    //Draw The text score
    setPlainText("SCORE: " + QString::number(score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("terminal",25));
}

int Score::getScore()
{
    return score;
}
