
#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QMainWindow>
#include <QPushButton>
#include <QListWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ListWidget; }
QT_END_NAMESPACE

class ListWidget : public QMainWindow

{
    Q_OBJECT

public:
    ListWidget(QWidget *parent = nullptr);
    ~ListWidget();
    void addItemDiv(QListWidget&);
    void renameItemDiv(QListWidget&);
    void removeItemDiv(QListWidget&);

private slots:
    void addItem();
    void renameItem();
    void removeItem();
    void clearItems2();
    void clearItems1();
    void sortLeft();
    void sortRight();
    void moveToLeft();
    void moveToRight();
    void multipleChoice1();
    void multipleChoice2();
    void iconMode1();
    void iconMode2();


private:
    Ui::ListWidget *ui;
};

#endif // LISTWIDGET_H
