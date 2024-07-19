#ifndef NEWWINDOW_H
#define NEWWINDOW_H

#include <QWidget>

#include <QSqlDatabase>

#include "Widget.h"

namespace Ui {
class LogWindow;
}

class LogWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LogWindow(QWidget *parent = nullptr,QSqlDatabase* database = nullptr);
    ~LogWindow();
    QSqlDatabase *DB;//数据库

private slots:
    void on_stuButton_clicked();

    void on_TSLogButton_clicked();


private:
    Ui::LogWindow *ui;
    Widget * w;
};

#endif // NEWWINDOW_H
