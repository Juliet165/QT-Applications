
#include "topten.h"
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QGridLayout>
#include <QHeaderView>

topTen::topTen(QWidget *parent)
    : QWidget(parent), ratingTable(0, 2, this)
{
    setWindowTitle("Рекорды");
    setStyleSheet("background-color : #a1583e;");
    QGridLayout *layout = new QGridLayout(this);
    setLayout(layout);
    ratingTable.setStyleSheet("background-color : #fcf8f3;"
                            "color : #a1583e;" "font: 25px \"Bookman Old Style\";");
    ratingTable.setHorizontalHeaderLabels(QStringList({"Попытки", "Имя"}));
    ratingTable.horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    setMinimumSize(400, 550);
    layout->addWidget(&ratingTable);
    refill();
}

bool topTen::isTop(int score){
    int i = 0;
    for (auto it = storage.begin(); it != storage.end(); ++it) {
        if (i > 9)
            return false;;
        if (it->first > score)
            return true;
        ++i;
    }
    return true;
}

void topTen::add(int score, QString name){
    if (isTop(score)) {
        storage.insert(std::make_pair(score, name));
        refill();
    }
}

void topTen::refill(){
    while (ratingTable.rowCount() > 0) {
        ratingTable.removeRow(0);
    }
    int i = 0;
    for (auto it = storage.begin(); it != storage.end(); ++it) {
        if (i > 9){return;}

        auto size = ratingTable.rowCount();
        ratingTable.insertRow(size);
        ratingTable.setItem(size, 0, new QTableWidgetItem(QString::number(it->first)));
        ratingTable.setItem(size, 1, new QTableWidgetItem(it->second));
        ++i;
    }
}
