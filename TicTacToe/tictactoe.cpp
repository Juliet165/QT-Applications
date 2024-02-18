#include "tictactoe.h"
#include "ui_tictactoe.h"
#include <time.h>

bool flag = true;
bool turnX = true;
bool end = false;

TicTacToe::TicTacToe(QWidget *parent, int s)
    : QWidget(parent), ui(new Ui::TicTacToe)
{
    ui->setupUi(this);
    size = s;
    QGridLayout *grid = new QGridLayout(this);
    grid->setSizeConstraint(QLayout::SetFixedSize);
    buttons = new QPushButton*[size];
    for (int i = 0; i < size; i++)
        buttons[i] = new QPushButton[size];
    clearBtn->setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed,
                                        QSizePolicy::ToolButton));
    connect(clearBtn, SIGNAL(clicked()),this, SLOT(clearClicked()));
    connect (gameWComp, SIGNAL (pressed()), this, SLOT (checkBoxClear()));
    clearBtn->setStyleSheet("background-color : #ffdcea;""border-radius : 5px;"
                                "color : #c00c3d;" "font: 35px \"Verdana\";"
                            "border: 2px solid #f44d78;");
    grid->addWidget(res, size/2, size+1);
    grid->addWidget(gameWComp, 0, size+1);
    grid->addWidget(clearBtn, size-1, size+1);
    res->setStyleSheet("font: 30px \"Montserrat\";""color: black;""font-weight: bold;");
    gameWComp->setStyleSheet("font: 30px \"Tahoma\";""color: black;");
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            buttons[i][j].setFixedSize(900/(size+2), 900/(size+2));
            grid->addWidget(&buttons[i][j], i, j);
            buttons[i][j].setStyleSheet("background-color : #fbbace;""border-radius : 15px;");
            connect(&buttons[i][j], SIGNAL(clicked()),this, SLOT(buttonClicked()));
        }
    }
    res->setText("PLAYER XУЙ MOVE");
}

TicTacToe::~TicTacToe()
{
    delete ui;
    delete res;
    delete gameWComp;
    delete clearBtn;
    for (int i = 0; i<size; i++)
    {
        delete [] buttons[i];
    }
    delete [] buttons;
}

void TicTacToe::checkBoxClear(){
    clearClicked();
}

void TicTacToe::buttonClicked()
{
    QPushButton *button =  (QPushButton *)sender();
    if (flag){
        button->setText("xуй");
        flag = false;
        res->setText("PLAYER ♥ MOVE");
    }
    else
    {
        button->setText("♥");
        res->setText("PLAYER XУЙ MOVE");
        flag = true;
    }
    button->setEnabled(false);
    button->setStyleSheet(getButtonStyleSheet());
    gamePosition();
    if (end != true){
        if(gameWComp->isChecked()) {
            computerMove();
            gamePosition();
        }
    }
}

void TicTacToe::clearClicked()
{
    turnX = !turnX;
    flag = turnX;
    end = false;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            buttons[i][j].setEnabled(true);
            buttons[i][j].setText("");
            buttons[i][j].setStyleSheet("background-color : #fbbace;""border-radius : 15px;");
        }
    }
    res->setText("");
}


void TicTacToe::gamePosition(){
    bool win = false;
    int s = size;
    for (int i = 0; i < s; i++){
        int countX = 0;
        int countO = 0;
        for (int j = 0; j < s; j++) {
            if (buttons[i][j].text() == "xуй") {
                   countX++;
            }
            if (buttons[i][j].text() == "♥") {
                   countO++;
            }
        }
        if (countX == s) {
            res->setText("XУЙ WON!");
            win = true;
            gameResult();
        }
        if (countO == s) {
            res->setText("♥ WON!");
            win = true;
            gameResult();
        }
    }
    for (int i = 0; i < s; i++){
        int countX = 0;
        int countO = 0;
        for (int j = 0; j < s; j++) {
            if (buttons[j][i].text() == "xуй") {
                   countX++;
            }
            if (buttons[j][i].text() == "♥") {
                   countO++;
            }
        }
        if (countX == s) {
            res->setText("XУЙ WON!");
            win = true;
            gameResult();
        }
        if (countO == s) {
            res->setText("♥ WON!");
            win = true;
            gameResult();
        }
    }
    int countX = 0;
    int countO = 0;
    for (int j = 0; j < s; j++) {
        if (buttons[j][j].text() == "xуй") {
            countX++;
        }
        if (buttons[j][j].text() == "♥") {
            countO++;
        }
    }
    if (countX == s) {
        res->setText("XУЙ WON!");
        win = true;
        gameResult();
    }
    if (countO == s) {
        res->setText("♥ WON!");
        win = true;
        gameResult();
    }
    countX = 0;
    countO = 0;
    for (int j = 0; j < s; j++) {
        if (buttons[j][s-j-1].text() == "xуй") {
            countX++;
        }
        if (buttons[j][s-j-1].text() == "♥") {
            countO++;
        }
    }
    if (countX == s) {
        res->setText("XУЙ WON!");
        win = true;
        gameResult();
    }
    if (countO == s) {
        res->setText("♥ WON!");
        win = true;
        gameResult();
    }

    if (win == false){
        int count = 0;
        for (int i = 0; i < s; i++){
            for (int j = 0; j < s; j++) {
                   if (buttons[i][j].text() == "xуй" || buttons[i][j].text() == "♥") {
                       count++;
                   }
            }
        }
        if (count == s*s){
            res->setText("DRAW!");
            gameResult();
        }
    }
}

QString TicTacToe::getButtonStyleSheet()
{
    QString color;
    if(flag) {
        color = "#fafafa";
        return QString("font: 50px \"Verdana\";"
                       "color:#cc0000;"
                       "border-radius : 20px;"
                       "background-color: %1").arg(color);
    }
    else {
        color = "#f44d78";
        return QString("font: 50px \"Verdana\";"
                       "color: black;"
                       "border-radius : 20px;"
                       "background-color: %1").arg(color);
    }

    return QString("font: 50px \"Verdana\";"
                   "color:black;"
                   "background-color: %1").arg(color);
}

void TicTacToe::gameResult(){
    end = true;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            buttons[i][j].setEnabled(false);
        }
    }
}

void TicTacToe::computerMove(){
    int iComp = 0 + rand() % size;
    int jComp = 0 + rand() % size;
    int count = 0;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++) {
            if (buttons[i][j].text() == "xуй" || buttons[i][j].text() == "♥") {
                   count++;
            }
        }
    }
    if (count == size*size){
        gameResult();
    }
    else{
        if(buttons[iComp][jComp].text() == "xуй" || buttons[iComp][jComp].text() == "♥"){
            while (buttons[iComp][jComp].text() == "xуй" || buttons[iComp][jComp].text() == "♥"){
                   iComp = 0 + rand() % size;
                   jComp = 0 + rand() % size;
            }
        }
        if (flag == true){
            buttons[iComp][jComp].setText("x");
            buttons[iComp][jComp].setStyleSheet("font: 50px \"Verdana\";"
                                                "color: black;"
                                                "border-radius : 20px;"
                                                "background-color: #f44d78");
            flag = false;
        }
        else
        {
            buttons[iComp][jComp].setText("♥");
            buttons[iComp][jComp].setStyleSheet("font: 50px \"Verdana\";"
                                                "color:#cc0000;"
                                                "border-radius : 20px;"
                                                "background-color: #fafafa");
            flag = true;
        }
        buttons[iComp][jComp].setEnabled(false);
    }
}

