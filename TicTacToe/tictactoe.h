#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QLineEdit>
#include <QTextEdit>
#include <QCheckBox>


QT_BEGIN_NAMESPACE
namespace Ui { class TicTacToe; }
QT_END_NAMESPACE

class TicTacToe : public QWidget

{
    Q_OBJECT

public:
    TicTacToe(QWidget *parent, int s);
    QLabel *res = new QLabel(" ", this);
    QCheckBox *gameWComp = new QCheckBox("COMPUTER MODE", this);
    QPushButton *clearBtn = new QPushButton("  CLEAR  ", this);
    ~TicTacToe();

private:
    Ui::TicTacToe *ui;
    void gamePosition();
    void gameResult();
    void computerMove();
    QString getButtonStyleSheet();
    int size;
    QPushButton** buttons;


private slots:
    void buttonClicked();
    void clearClicked();
    void checkBoxClear();

};

#endif // TICTACTOE_H
