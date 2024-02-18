
#include "listwidget.h"
#include "ui_listwidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QInputDialog>
#include <QFlags>
#include <QtAlgorithms>

bool mult1 = false;
bool mult2 = false;
bool ic1 = false;
bool ic2 = false;

ListWidget::ListWidget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ListWidget)
{
    ui->setupUi(this);
    connect(ui->add1, &QPushButton::clicked, this, &ListWidget::addItem);
    connect(ui->rename1, &QPushButton::clicked, this, &ListWidget::renameItem);
    connect(ui->remove1, &QPushButton::clicked, this, &ListWidget::removeItem);
    connect(ui->removeAll1, &QPushButton::clicked, this, &ListWidget::clearItems1);
    connect(ui->add2, &QPushButton::clicked, this, &ListWidget::addItem);
    connect(ui->rename2, &QPushButton::clicked, this, &ListWidget::renameItem);
    connect(ui->remove2, &QPushButton::clicked, this, &ListWidget::removeItem);
    connect(ui->removeAll2, &QPushButton::clicked, this, &ListWidget::clearItems2);
    connect(ui->toLeft, &QPushButton::clicked, this, &ListWidget::moveToLeft);
    connect(ui->toRight, &QPushButton::clicked, this, &ListWidget::moveToRight);
    connect(ui->sort1, &QPushButton::clicked, this, &ListWidget::sortLeft);
    connect(ui->sort2, &QPushButton::clicked, this, &ListWidget::sortRight);
    connect(ui->multiple1, &QPushButton::clicked, this, &ListWidget::multipleChoice1);
    connect(ui->multiple2, &QPushButton::clicked, this, &ListWidget::multipleChoice2);
    connect(ui->icons1, &QPushButton::clicked, this, &ListWidget::iconMode1);
    connect(ui->icons2, &QPushButton::clicked, this, &ListWidget::iconMode2);

    ui->lw1->setStyleSheet("background-color : #f9f5f0;""border-radius : 10px;");
    ui->lw2->setStyleSheet("background-color : #f9f5f0;""border-radius : 10px;");

    ui->add2->setStyleSheet("background-color : #e79e85;""border-radius : 15px;"
                            "font: 0px \"Montserrat\";""color: black;""font-weight: bold;"
                            );
    ui->add2->setFixedSize(150, 100);
    ui->add1->setStyleSheet("background-color : #e79e85;""border-radius : 15px;"
                            "font: 0px \"Montserrat\";""color: black;""font-weight: bold;");
    ui->add1->setFixedSize(150, 100);

    ui->toLeft->setStyleSheet("background-color : #e79e85;""border-radius : 15px;"
                            "font: 0px \"Montserrat\";""color: black;""font-weight: bold;"
                            );
    ui->toLeft->setFixedSize(150, 100);
    ui->toRight->setStyleSheet("background-color : #e79e85;""border-radius : 15px;"
                            "font: 0px \"Montserrat\";""color: black;""font-weight: bold;");
    ui->toRight->setFixedSize(150, 100);

    ui->rename2->setStyleSheet("background-color : #e79e85;""border-radius : 15px;"
                            "font: 0px \"Montserrat\";""color: black;""font-weight: bold;"
                            );
    ui->rename2->setFixedSize(150, 100);
    ui->rename1->setStyleSheet("background-color : #e79e85;""border-radius : 15px;"
                            "font: 0px \"Montserrat\";""color: black;""font-weight: bold;");
    ui->rename1->setFixedSize(150, 100);

    ui->remove2->setStyleSheet("background-color : #e79e85;""border-radius : 15px;"
                            "font: 0px \"Montserrat\";""color: black;""font-weight: bold;"
                            );
    ui->remove2->setFixedSize(150, 100);
    ui->remove1->setStyleSheet("background-color : #e79e85;""border-radius : 15px;"
                            "font: 0px \"Montserrat\";""color: black;""font-weight: bold;");
    ui->remove1->setFixedSize(150, 100);

    ui->removeAll2->setStyleSheet("background-color : #e79e85;""border-radius : 15px;"
                               "font: 0px \"Montserrat\";""color: black;""font-weight: bold;"
                               );
    ui->removeAll2->setFixedSize(150, 100);
    ui->removeAll1->setStyleSheet("background-color : #e79e85;""border-radius : 15px;"
                               "font: 0px \"Montserrat\";""color: black;""font-weight: bold;");
    ui->removeAll1->setFixedSize(150, 100);


    ui->sort1->setStyleSheet("background-color : #e79e85;""border-radius : 15px;"
                               "font: 0px \"Montserrat\";""color: black;""font-weight: bold;"
                               );
    ui->sort1->setFixedSize(150, 100);
    ui->sort2->setStyleSheet("background-color : #e79e85;""border-radius : 15px;"
                               "font: 0px \"Montserrat\";""color: black;""font-weight: bold;");
    ui->sort2->setFixedSize(150, 100);

    ui->icons1->setStyleSheet("background-color : #e79e85;""border-radius : 15px;"
                                  "font: 30px \"Montserrat\";""color: black;""font-weight: bold;");
    ui->icons1->setFixedSize(150, 40);
    ui->icons2->setStyleSheet("background-color : #e79e85;""border-radius : 15px;"
                              "font: 30px \"Montserrat\";""color: black;""font-weight: bold;");
    ui->icons2->setFixedSize(150, 40);

    ui->multiple1->setStyleSheet("background-color : #e79e85;""border-radius : 15px;"
                              "font: 30px \"Montserrat\";""color: black;""font-weight: bold;");
    ui->multiple1->setFixedSize(150, 40);
    ui->multiple2->setStyleSheet("background-color : #e79e85;""border-radius : 15px;"
                              "font: 30px \"Montserrat\";""color: black;""font-weight: bold;");
    ui->multiple2->setFixedSize(150, 40);

}

ListWidget::~ListWidget()
{
    delete ui;
}

void ListWidget::addItem() {
    QPushButton *button =  (QPushButton *)sender();
    if (button == ui->add1){
        addItemDiv(*ui->lw1);
    }
    else if (button == ui->add2){
        addItemDiv(*ui->lw2);
    }
}

void ListWidget::renameItem() {

    QPushButton *button =  (QPushButton *)sender();
    if (button == ui->rename1){
        renameItemDiv(*ui->lw1);
    }
    else if (button == ui->rename2){
        renameItemDiv(*ui->lw2);
    }
}

void ListWidget::removeItem() {
    QPushButton *button =  (QPushButton *)sender();
    if (button == ui->remove1){
        removeItemDiv(*ui->lw1);
    }
    else if (button == ui->remove2){
        removeItemDiv(*ui->lw2);
    }
}

void ListWidget::clearItems1(){
    if (ui->lw1->count() != 0) {
        ui->lw1->clear();
    }
}

void ListWidget::sortLeft(){
    ui->lw1->sortItems(Qt::AscendingOrder);
}

void ListWidget::multipleChoice1(){
    mult1 = !mult1;
    if (mult1){
        ui->lw1->setSelectionMode(QAbstractItemView::MultiSelection);
        ui->multiple1->setText("Single");
    }
    else{
        ui->lw1->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->multiple1->setText("Multiple");
    }
}

void ListWidget::iconMode1(){
    ic1 = !ic1;
    if (ic1){
        ui->lw1->setViewMode(QListView::IconMode);
        ui->icons1->setText("List");
    }
    else{
        ui->lw1->setViewMode(QListView::ListMode);
        ui->icons1->setText("Icons");
    }
}


void ListWidget::addItemDiv(QListWidget &l) {
    QString c_text = QInputDialog::getText(this, "Item", "Enter new item");
    QString s_text = c_text.simplified();
    if (!s_text.isEmpty()) {
        QListWidgetItem *newIt = new QListWidgetItem;
        newIt->setText(s_text);
        if (&l == ui->lw1){
           newIt->setIcon(QIcon("cat.png"));
        }
        else if (&l == ui->lw2){
           newIt->setIcon(QIcon("dog.png"));
        }
        l.addItem(newIt);
    }
}

void ListWidget::renameItemDiv(QListWidget &l) {

    if ((&l == ui->lw1 && !mult1) || (&l == ui->lw2 && !mult2)){
        QListWidgetItem *curitem = l.currentItem();
        int r = l.row(curitem);
        QString c_text = curitem->text();
        QString r_text = QInputDialog::getText(this, "Item", "Enter new item", QLineEdit::Normal, c_text);
        QString s_text = r_text.simplified();
        if (!s_text.isEmpty()) {
           QListWidgetItem *item = l.takeItem(r);
           delete item;
           QListWidgetItem *newIt = new QListWidgetItem;
           newIt->setText(s_text);
           if (&l == ui->lw1){
               newIt->setIcon(QIcon("cat.png"));
           }
           else if (&l == ui->lw2){
               newIt->setIcon(QIcon("dog.png"));
           }
           l.insertItem(r, newIt);
           l.setCurrentRow(r);
        }
    }
    else if ((&l == ui->lw1 && mult1) || (&l == ui->lw2 && mult2)){
        QList m = l.selectedItems();
        foreach (QListWidgetItem* curitem, m){
           int r = l.row(curitem);
           QString c_text = curitem->text();
           QString r_text = QInputDialog::getText(this, "Item", "Enter new item", QLineEdit::Normal, c_text);
           QString s_text = r_text.simplified();
           if (!s_text.isEmpty()) {
               QListWidgetItem *item = l.takeItem(r);
               delete item;
               QListWidgetItem *newIt = new QListWidgetItem;
               newIt->setText(s_text);
               if (&l == ui->lw1){
                   newIt->setIcon(QIcon("cat.png"));
               }
               else if (&l == ui->lw2){
                   newIt->setIcon(QIcon("dog.png"));
               }
               l.insertItem(r, newIt);
           }
           l.setCurrentRow(r);
        }
    }
}

void ListWidget::removeItemDiv(QListWidget &l) {
    if ((&l == ui->lw1 && !mult1) || (&l == ui->lw2 && !mult2)){
        int r = l.currentRow();
        if (r != -1) {
            QListWidgetItem *item = l.takeItem(r);
            delete item;
        }
    }
    else if ((&l == ui->lw1 && mult1) || (&l == ui->lw2 && mult2)){
        QList m = l.selectedItems();
        for (int i = 0; i < m.size(); i++){
            int r = l.currentRow();
            if (r != -1) {
                QListWidgetItem *item = l.takeItem(r);
                delete item;
            }
        }
    }
}

void ListWidget::clearItems2(){
    if (ui->lw2->count() != 0) {
        ui->lw2->clear();
    }
}

void ListWidget::moveToRight(){
    if (!mult1){
        QListWidgetItem *curitem = ui->lw1->currentItem();
        QString s_text = curitem->text();
        if (!s_text.isEmpty()) {
            QListWidgetItem* newIt = ui->lw1->currentItem()->clone();
            newIt->setIcon(QIcon("dog.png"));
            ui->lw2->addItem(newIt);
            int r = ui->lw2->count() - 1;
            ui->lw2->setCurrentRow(r);
        }
        int r = ui->lw1->currentRow();
        if (r != -1) {
            QListWidgetItem *item = ui->lw1->takeItem(r);
            delete item;
        }
    }
    else {
        QList l = ui->lw1->selectedItems();
        for (int i = 0; i < l.size(); i++){
            QListWidgetItem* it = l[i]->clone();
            ui->lw1->removeItemWidget(l[i]);
            delete l[i];
            it->setIcon(QIcon("dog.png"));
            ui->lw2->addItem(it);
        }
    }
}

void ListWidget::moveToLeft(){
    if (!mult2){
        QListWidgetItem *curitem = ui->lw2->currentItem();
        QString s_text = curitem->text();
        if (!s_text.isEmpty()) {
            QListWidgetItem *newIt = new QListWidgetItem;
            newIt->setText(s_text);
            newIt->setIcon(QIcon("cat.png"));
            ui->lw1->addItem(newIt);
            int r = ui->lw1->count() - 1;
            ui->lw1->setCurrentRow(r);
        }
        int r = ui->lw2->currentRow();
        if (r != -1) {
            QListWidgetItem *item = ui->lw2->takeItem(r);
            delete item;
        }
    }
    else {
        QList l = ui->lw2->selectedItems();
        for (int i = 0; i < l.size(); i++){
            QListWidgetItem* it = l[i]->clone();
            ui->lw2->removeItemWidget(l[i]);
            delete l[i];
            it->setIcon(QIcon("cat.png"));
            ui->lw1->addItem(it);
        }
    }
}

void ListWidget::sortRight(){
    ui->lw2->sortItems(Qt::DescendingOrder);
}

void ListWidget::multipleChoice2(){
    mult2 = !mult2;
    if (mult2){
        ui->lw2->setSelectionMode(QAbstractItemView::MultiSelection);
        ui->multiple2->setText("Single");
    }
    else{
        ui->lw2->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->multiple2->setText("Multiple");
    }
}

void ListWidget::iconMode2(){
    ic2 = !ic2;
    if (ic2){
        ui->lw2->setViewMode(QListView::IconMode);
        ui->icons2->setText("List");

    }
    else{
        ui->lw2->setViewMode(QListView::ListMode);
        ui->icons2->setText("Icons");
    }

}

