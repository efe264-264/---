#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QSqlDatabase>
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include "newwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loginButton_clicked();
    void on_tsButton_clicked();

private:
    Ui::MainWindow *ui;
    newwindow *newWindow = nullptr;
     QSqlDatabase DB;
};
#endif // MAINWINDOW_H
