
#include "sdi.h"
#include "ui_sdi.h"

#include "diagram.h"
#include <QtWidgets>
#include <QWidget>

sdi::sdi(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::sdi)
{
    ui->setupUi(this);
    graphic = new Diagram(this);
    setCentralWidget(graphic);
    graphic->brushColor = Qt::cyan;
    graphic->penColor = Qt::black;
    graphic->pen.setWidth(1);

    ui->actionopen->setEnabled(false);
    ui->actionclose->setEnabled(false);
    ui->actionsave->setEnabled(false);

    statusWidth = new QLabel(" Ширина карандаша: 1px ");
    statusName = new QLabel(" Нормированная линейчатая диаграмма с накоплением ");
    statusStyle = new QLabel(" Стиль линии: пунктир ");
    statusBar()->addWidget(statusName);
    statusBar()->addWidget(statusStyle);
    statusBar()->addWidget(statusWidth);

    widthMenu = new QMenu;
    QAction* contextWidth =  new QAction("Задать ширину пера");
    connect(contextWidth, SIGNAL(triggered()), this, SLOT(widthDialShow()));
    widthMenu->addAction(contextWidth);
    widthDialog = new QDialog;
    widthDialog->setFixedSize(170, 200);
    QVBoxLayout *dialogLayout = new QVBoxLayout();
    ok = new QPushButton("OK", widthDialog);
    width1 = new QRadioButton("1 px");
    width2 = new QRadioButton("2 px");
    width3 = new QRadioButton("5 px");
    ok->resize(100,30);
    dialogLayout->addWidget(width1);
    dialogLayout->addWidget(width2);
    dialogLayout->addWidget(width3);
    dialogLayout->addWidget(ok);
    widthDialog->setLayout(dialogLayout);
    connect(ok, SIGNAL(clicked()), this, SLOT(widthChange()));

}

sdi::~sdi()
{
    delete ui;
}

void sdi::contextMenuEvent(QContextMenuEvent* event){
    widthMenu->exec(event->globalPos());
}

void sdi::widthDialShow(){
    if(graphic->pen.width() == 1)
        width1->setChecked(1);
    else if(graphic->pen.width() == 2)
        width2->setChecked(1);
    else if(graphic->pen.width() == 5)
        width3->setChecked(1);
    widthDialog->exec();
}

void sdi::widthChange(){
    if (width1->isChecked()){
        graphic->pen.setWidth(1);
        statusWidth->setText(" Ширина карандаша: 1px ");
    }
    if (width2->isChecked()){
        graphic->pen.setWidth(2);
        statusWidth->setText(" Ширина карандаша: 2px ");
    }
    if (width3->isChecked()){
        graphic->pen.setWidth(5);
        statusWidth->setText(" Ширина карандаша: 5px ");
    }
    graphic->update();
    widthDialog->close();
}

void sdi::closeEvent (QCloseEvent *event) {
    on_actionexit_triggered();
}

void sdi::on_actionopen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", QDir::currentPath());
    if(!fileName.isEmpty()){
        graphic->openGraph(fileName);
        statusWidth->setText(" Ширина карандаша:" + QString::number(graphic->pen.width()) + "px ");
    }
    ui->actionsave->setEnabled(true);
    currentFile = fileName;
}


void sdi::on_actionsave_triggered()
{
    QFile file(currentFile);
    if (file.open(QIODevice::WriteOnly))
    {
        graphic->saveImg(currentFile);
    }
}


void sdi::on_actionsave_as_photo_triggered()
{
    QPixmap p(graphic->size());
    graphic->render(&p,QPoint(0,0), graphic->rect());
    p.save(FILE->getSaveFileName()+".jpg","jpg");
}


void sdi::on_actionsave_as_document_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", QDir::currentPath(), "TXT (*.txt)");
    if(!fileName.isEmpty())
    {
        graphic->saveImg(fileName);
        ui->actionopen->setEnabled(true);
        ui->actionclose->setEnabled(true);
    }
}


void sdi::on_actionclose_triggered()
{
    graphic->nums.clear();
    graphic->update();
}


void sdi::on_actionexit_triggered()
{
    if (graphic->nums.size()==0) {
        return;
    }
    if (QMessageBox::question(this, "Закрытие приложения", "Хотите сохранить диаграмму?",
                              QMessageBox::Yes | QMessageBox::No) == QMessageBox::No)
        QApplication::quit();
    else {
        on_actionsave_as_document_triggered();
        QApplication::quit();
    }
}


void sdi::on_actionpen_triggered()
{
    QColor col = QColorDialog::getColor();
    if(col.isValid()){
        graphic->penColor = col;
    }
    graphic->update();
}


void sdi::on_actionbrush_triggered()
{
    QColor col = QColorDialog::getColor();
    if(col.isValid()){
        graphic->brushColor = col;
    }
    graphic->update();
}


void sdi::on_actionabout_triggered()
{
    QMessageBox::information(0, "Обо мне", "Каноплич Юлия. 13 группа. Вариант 8");
}

