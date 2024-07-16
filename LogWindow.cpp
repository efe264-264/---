#include <QtWidgets>
#include "LogWindow.h"
#include "ui_LogWindow.h"
#include "widget.h"
LogWindow::LogWindow(QWidget *parent,QSqlDatabase * database) :
    QWidget(parent),DB(database),
    ui(new Ui::LogWindow)
{
    ui->setupUi(this);
}

LogWindow::~LogWindow()
{
    delete ui;
}

void LogWindow::on_stuButton_clicked()
{
    this->hide();
}





void LogWindow::on_TSLogButton_clicked()
{

        QString TSpassword = ui->TSPasswordLine->text();
        if(TSpassword=="123456")
        {  QMessageBox::information(this, "登录成功", "欢迎登录教秘系统！");
            w = new Widget(this, DB); // 创建 Widget 实例，并设置为 LogWindow 的子对象
            w->show();
        }
        else
        { QMessageBox::information(this, "登录失败", "非法凭证！");}


}

