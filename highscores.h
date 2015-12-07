#ifndef HIGHSCORES_H
#define HIGHSCORES_H

#include <QObject>
#include <QDialog>

namespace Ui {
class HighScores;
}

class HighScores : public QDialog
{
    Q_OBJECT

public:
    explicit HighScores(QWidget *parent = 0);
    ~HighScores();

private slots:
    void on_QuitGame_clicked();

    void on_textBrowser_highlighted(const QUrl &arg1);

private:
    Ui::HighScores *ui;
};

#endif // HIGHSCORES_H
