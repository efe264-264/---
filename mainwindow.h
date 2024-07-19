#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QSqlDatabase>
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include "LogWindow.h"
#include"window01.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSqlDatabase DB;//数据库界面公用

private slots:
    void on_loginButton_click();
    void on_tsButton_clicked();

private:
    Ui::MainWindow *ui;
    LogWindow *newLogWindow = nullptr;
    Window01 w;
};
#endif // MAINWINDOW_H
