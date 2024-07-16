#ifndef WINDOW03_H
#define WINDOW03_H

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

namespace Ui {
class Window03;
}

class Window03 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window03(QWidget *parent = 0);
    ~Window03();

private:
    Ui::Window03 *ui;
    QSqlDatabase db;
};

#endif // WINDOW03_H
