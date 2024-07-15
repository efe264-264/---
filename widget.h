#ifndef WIDGET_H
#define WIDGET_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include <QWidget>
#include <QProcess>
#include <QSqlDatabase>
#include <QLineEdit>
#include <QPushButton>
#include <QSqlQuery>
#include <QTableWidget>

#include <QMessageBox> // 确保包含了 QMessageBox 类
#include <QSqlError> // 确保包含了 QSqlError 类


QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

//继承
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void addCoursesToTable(QTableWidget *tableWidget, QSqlQuery &sqlQuery);

//查询按钮转到槽，点击然后跳转
private slots:    //槽函数需加上关键字slots
    void on_queryButton_clicked();
    void on_cancelButton_clicked();

private:
    //QLineEdit *lineEdit;
    //QPushButton *queryButton;

    //数据库对象
    QSqlDatabase database;

    Ui::Widget *ui;
};
#endif // WIDGET_H
