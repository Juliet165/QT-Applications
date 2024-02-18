
#ifndef FLAGS_H
#define FLAGS_H

#include <QWidget>
#include <QPainter>
#include <QTabWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class Flags; }
QT_END_NAMESPACE

class Flags : public QTabWidget

{
    Q_OBJECT

public:
    Flags(QTabWidget *parent = nullptr);
    ~Flags();

private:
    Ui::Flags *ui;

    //QTabWidget *tabWidget;
    //QWidget *russianFlagWidget;
    //QWidget *germanFlagWidget;
    //void paintEvent (QPaintEvent* painter);

private slots:
    //void tabChanged(int index);
    //void on_tabWidget_currentChanged(int index);
};

#endif // FLAGS_H
