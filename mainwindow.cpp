#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include "LogWindow.h"
#include <QSqlQuery>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::on_loginButton_click);
    connect(ui->ExitButton, &QPushButton::clicked, this, &QMainWindow::close);
    connect(ui->tsButton, &QPushButton::clicked, this, &MainWindow::on_tsButton_clicked);
    DB=QSqlDatabase::addDatabase("QMYSQL");//加载mysql驱动
    DB.setDatabaseName("game");//数据库名字
    DB.setHostName("localhost");//数据库地址，本地默认localhost
    DB.setUserName("root");//用户名，本地默认root
    DB.setPassword("123456");//密码，
     if(DB.open())
    {
        QMessageBox::information(this,"连接","连接成功");
     }
     else
     {
         QMessageBox::warning(this,"连接","连接失败");
     }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginButton_click()
{
    QString username = ui->usernameLineEdit->text(); // 假设你的账号输入框命名为usernameLineEdit
    QString password = ui->passwordLineEdit->text(); // 假设你的密码输入框命名为passwordLineEdit
    QSqlQuery query;
    query.exec       ("SELECT * FROM log WHERE id='" + username + "' AND pw='" + password + "'");

    if (query.next())
    {
         qDebug() << "Login successful";
         QMessageBox::information(this, "登录成功", "欢迎！");
    }
    else {
         qDebug() << "Login failed";
         QMessageBox::information(this, "登录失败", "账号或密码输入错误");
    }
    // 在这里实现登录逻辑，比如检查用户名和密码



}
void MainWindow::on_tsButton_clicked()
{
    // 如果LogWindow尚未创建，则创建它
    if (!newLogWindow) {
        newLogWindow = new LogWindow(this,&DB);
    }

    //this->hide();
    newLogWindow->show();// 显示LogWindow

}
