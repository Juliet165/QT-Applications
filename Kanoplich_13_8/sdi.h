
#ifndef SDI_H
#define SDI_H

#include <QMainWindow>
#include <QtWidgets>
#include <QWidget>
#include "diagram.h"

QT_BEGIN_NAMESPACE
namespace Ui { class sdi; }
QT_END_NAMESPACE

class sdi : public QMainWindow

{
    Q_OBJECT

public:
    sdi(QWidget *parent = nullptr);
    ~sdi();

private slots:
    void on_actionopen_triggered();

    void on_actionsave_triggered();

    void on_actionsave_as_photo_triggered();

    void on_actionsave_as_document_triggered();

    void on_actionclose_triggered();

    void on_actionexit_triggered();

    void contextMenuEvent(QContextMenuEvent *event);

    void widthChange();

    void widthDialShow();

    void closeEvent (QCloseEvent *event);

    void on_actionpen_triggered();

    void on_actionbrush_triggered();

    void on_actionabout_triggered();

private:
    Ui::sdi *ui;
    Diagram *graphic;
    QLabel *statusWidth;
    QLabel *statusName;
    QLabel *statusStyle;
    QMenu *widthMenu;
    QDialog *widthDialog;
    QRadioButton *width1;
    QRadioButton *width2;
    QRadioButton *width3;
    QPushButton *ok;
    QFileDialog *FILE = new QFileDialog;
    QString currentFile;
};

#endif // SDI_H
