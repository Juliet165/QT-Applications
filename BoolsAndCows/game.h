
#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include "topten.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Game; }
QT_END_NAMESPACE

class Game : public QWidget

{
    Q_OBJECT

public:
    Game(topTen* highscore, QWidget *parent = nullptr);
    ~Game();

private:
    Ui::Game *ui;
    QString compNum;
    topTen *best;
private slots:
    void start();
    void checking();
    void rating();
public:
    void cowBool(QString a, QString b, int& cows, int& bulls);
    bool isCorrect(QString inp);
    bool isUnique(int num);
};

#endif // GAME_H
