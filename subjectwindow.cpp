#include "subjectwindow.h"
#include "ui_subjectwindow.h"

subjectwindow::subjectwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::subjectwindow)
{
    ui->setupUi(this);
}

subjectwindow::~subjectwindow()
{
    delete ui;
}



void subjectwindow::on_comboBox_currentTextChanged(const QString &arg1)
{

}

