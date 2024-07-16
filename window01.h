#ifndef WINDOW01_H
#define WINDOW01_H

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
#include "graph.h"

extern int choice_num;
extern VexNode result1[100];
extern VexNode result2[100];
extern VexNode result3[100];
extern VexNode result4[100];
extern VexNode result[4][100];
namespace Ui {
class Window01;
}

class Window01 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window01(QWidget *parent = 0);
    ~Window01();

private:
    Ui::Window01 *ui;
    QSqlDatabase db;

};

#endif // WINDOW01_H
