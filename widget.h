#ifndef WIDGET_H
#define WIDGET_H

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
class LogWindow;
namespace Ui {
class Widget;
}

QT_END_NAMESPACE
//继承
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr,QSqlDatabase *db= nullptr,LogWindow * FLOGW=NULL);
    ~Widget();
    void addCoursesToTable(QTableWidget *tableWidget, QSqlQuery &sqlQuery1,QStringList &classNums);
    void addCoursesToTable1(QTableWidget *tableWidget, QString &courseName, QStringList &classNums);
    LogWindow * FLW;

//查询按钮转到槽，点击然后跳转
private slots:      //槽函数需加上关键字slots
    void on_queryButton_clicked();    //查询键
    void on_cancelButton_clicked();   //取消键

private:

    //数据库对象
    QSqlDatabase *database;

    Ui::Widget *ui;
};
#endif // WIDGET_H
