
#include "game.h"
#include "topten.h"
#include "ui_game.h"
#include <QTableWidget>
#include <QString>
#include <QGridLayout>
#include <QHeaderView>
#include <QInputDialog>

Game::Game(topTen* highscore, QWidget *parent)
    : QWidget(parent), ui(new Ui::Game), best(highscore)
{
    ui->setupUi(this);
    //setStyleSheet("background-color : #d3a284;");
    QBrush br(Qt::TexturePattern);
    br.setTextureImage(QImage("back.jpg"));
    QPalette plt = palette();
    plt.setBrush(QPalette::Background, br);
    setPalette(plt);
    setWindowTitle("Быки и коровы");
    connect(ui->newGame, SIGNAL(clicked()), SLOT(start()));
    connect(ui->check, SIGNAL(clicked()), SLOT(checking()));
    connect(ui->viewRecords, SIGNAL(clicked()), SLOT(rating()));
    ui->newGame->setText("Начать игру!");
    ui->newGame->setStyleSheet("background-color : white;""border-radius : 15px;"
                               "color : #a1583e;"
                               "border: 4px solid  #a1583e;");
    ui->viewRecords->setStyleSheet("background-color : #a1583e;""border-radius : 15px;"
                               "color : #fcf8f3;"
                               "border: 4px solid  #a1583e;");
    ui->check->setStyleSheet("background-color : #fcf8f3;""border-radius : 15px;"
                               "color : #a1583e;"
                               "border: 4px solid  #a1583e;");
    ui->igra->setStyleSheet("background-color : #fcf8f3;"
                            "color : #a1583e;" "font: 25px \"Bookman Old Style\";");
    ui->state->setStyleSheet("color : #a1583e;");
    ui->input->setStyleSheet("background-color : #fcf8f3;""border-radius : 15px;"
                             "color : #a1583e;"
                             "border: 4px solid  #a1583e;");
    ui->enternum->setStyleSheet("color : #a1583e;");
    ui->igra->hide();
    ui->state->hide();
    ui->check->hide();
    ui->input->hide();
    ui->viewRecords->hide();
    ui->enternum->hide();
}

Game::~Game()
{
    delete ui;
}

void Game::start(){
    ui->input->clear();
    setStyleSheet("background-color : #fcf8f3");
    ui->newGame->setStyleSheet("background-color : #fcf8f3;""border-radius : 15px;"
                               "color : #a1583e;"
                               "border: 4px solid  #a1583e;");
    ui->newGame->setText("Новая игра");
    ui->igra->show();
    ui->check->show();
    ui->state->show();
    ui->input->show();
    ui->viewRecords->show();
    ui->enternum->show();
    while (ui->igra->rowCount() > 0) {
        ui->igra->removeRow(0);
    }
    int comp = 1000 + rand()%9000;
    if (!isUnique(comp)){
        while (!isUnique(comp)){
            comp = 1000 + rand()%9000;
        }
    }
    compNum = QString::number(comp);
    ui->state->setText("Идёт игра..." + compNum);
}

bool Game::isCorrect(QString inp){
    bool ok = true;
    int c = inp.toInt(&ok, 10);
    if (!ok) {
        ui->state->setText("Введите ЧИСЛО!");
    }
    else if ((c < 1000) || (c > 9999)) {
        ui->state->setText("Введите ЧЕТЫРЁХЗНАЧНОЕ число!");
        ok = false;
    }
    else if (!isUnique(c)){
        ui->state->setText("Цифры не должны повторяться!");
        ok = false;
    }
    return ok;
}


void Game::cowBool(QString a, QString b, int &cows, int &bulls){
    bulls = 0;
    cows = 0;
    QChar space(' ');
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == b[i]) {
            bulls++;
            b[i] = space;
            a[i] = space;
        }
    }
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a.size(); ++j){
            if (a[i] == b[j] && a[i]!= space) {
                cows++;
                b[j] = space;
                a[i] = space;
            }
        }
    }
}

void Game::checking(){
    QString value = ui->input->text();
    if (!isCorrect(value)){
        return;
    }
    else {
        if (value == compNum) {
            int score = ui->igra->rowCount();
            if (best->isTop(score) == false)  {
                ui->state->setText("Вы выиграли, но не попали в рейтинг(");
            }
            else if (best->isTop(score) == true){
                bool ok;
                QString name = QInputDialog::getText(0, "Победа!", "Ваше имя:", QLineEdit::Normal, "", &ok);
                if (ok) {
                    best->add(score, name);
                }
            }
            start();
        }
        else{
            ui->state->setText("Не угадали:(");
            ui->igra->insertRow(ui->igra->rowCount());
            ui->igra->setItem(ui->igra->rowCount()-1, 0, new QTableWidgetItem(value));

            int bullsNum, cowsNum;
            cowBool(value, compNum, cowsNum,bullsNum);
            QString result =  "Быков: " + QString::number(bullsNum) + ", коров: "  + QString::number(cowsNum);
            ui->igra->setItem(ui->igra->rowCount()-1, 1, new QTableWidgetItem(result));
        }
    }
    ui->input->clear();
    return;
}

bool Game::isUnique(int num){
    bool res = true;
    int a, b, c, d;
    a = num%10;
    num/=10;
    b = num%10;
    num/=10;
    c = num%10;
    num/=10;
    d = num%10;
    if (a == b || a == c || a == d || b == c || b == d || c == d){
        res = false;
    }
    return res;
}

void Game::rating(){
    bool visibility = best->isVisible();
    best->setVisible(!visibility);
}
