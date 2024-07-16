#ifndef WINDOW02_H
#define WINDOW02_H

#include<QAbstractButton>
#include <QMainWindow>
#include <QPushButton>
#include<QtSql/QSqlDatabase>
#include<QDebug>
#include<QMessageBox>
#include<QtSql/QSqlError>
#include<QString>
#include<QtSql/QSqlQuery>
#include<QVariantList>
#include<QtSql/QSqlRecord>
#include<QMessageBox>
#include<QList>
#include "courseinfo.h"
#include "operation.h"
#include "graph.h"
#include "manager.h"
namespace Ui {
class Window02;
}

class Window02 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window02(QWidget *parent = 0);
    ~Window02();

    void Choose();
    /*void Choose2(VexNode* result);*/
private slots:
   // void on_pushButton_clicked();

private:
    Ui::Window02 *ui;
    QSqlDatabase db;
    //course cs;
    op oper;
    course_manager m;
};

#endif // WINDOW02_H
