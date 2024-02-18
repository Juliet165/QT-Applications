#include "flags.h"
#include "ui_flags.h"
#include "germanflagwidget.h"
#include "russianflagwidget.h"
#include <QWidget>
#include <QPainter>
#include <QTabWidget>
#include <QLayout>


Flags::Flags(QTabWidget *parent)
    : QTabWidget(parent)
    , ui(new Ui::Flags)
{
    germanFlagWidget *germanFlag = new germanFlagWidget();
    addTab(germanFlag, "German Flag");
    russianFlagWidget *russianFlag = new russianFlagWidget();
    addTab(russianFlag, "Russian Flag");
    this->setMinimumSize(500, 335);
    this->setStyleSheet("border-radius : 5px;"
                        "font: 20px \"Montserrat\";""color: black;""font-weight: bold;");
}

Flags::~Flags()
{
    delete ui;
}
