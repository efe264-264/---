#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include "newwindow.h"
#include <QSqlQuery>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::on_loginButton_clicked);
    connect(ui->ExitButton, &QPushButton::clicked, this, &QMainWindow::close);
    connect(ui->tsButton, &QPushButton::clicked, this, &MainWindow::on_tsButton_clicked);
    DB=QSqlDatabase::addDatabase("QMYSQL");//加载mysql驱动
    DB.setDatabaseName("game");//数据库名字
    DB.setHostName("localhost");//数据库地址，本地默认localhost
    DB.setUserName("root");//用户名，本地默认root
    DB.setPassword("123456");//密码，你自己设置的那个
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

void MainWindow::on_loginButton_clicked()
{
    QString username = ui->usernameLineEdit->text(); // 假设你的账号输入框命名为usernameLineEdit
    QString password = ui->passwordLineEdit->text(); // 假设你的密码输入框命名为passwordLineEdit
    QSqlQuery query;
    query.exec("SELECT * FROM log WHERE id='" + username + "' AND pw='" + password + "'");

    if (query.next()) {
         qDebug() << "Login successful";
         QMessageBox::information(this, "登录成功", "欢迎！");
    } else {
         qDebug() << "Login failed";
    }
    // 在这里实现登录逻辑，比如检查用户名和密码



}
void MainWindow::on_tsButton_clicked()
{
    // 如果newWindow尚未创建，则创建它
    if (!newWindow) {
        newWindow = new newwindow(this); // 这里this作为parent是可选的，取决于你的需求
    }
    // 显示newWindow
    newWindow->show();
    // 或者，如果你想让newWindow成为主窗口并关闭当前窗口，可以使用：
   // this->close(); // 但请注意，这样做可能会导致问题，特别是如果newWindow依赖于MainWindow中的数据时
    // 更安全的做法是让newWindow管理自己的显示和关闭逻辑
}
