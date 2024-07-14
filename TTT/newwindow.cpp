#include "newwindow.h"
#include "ui_newwindow.h"

newwindow::newwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newwindow)
{
    ui->setupUi(this);
}

newwindow::~newwindow()
{
    delete ui;
}
