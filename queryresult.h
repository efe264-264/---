#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <QTextBrowser>
#include <QWidget>
#include <QDialog>
#include <QTabWidget>
#include <QTableWidget>

namespace Ui {
class QueryResult;
}

class QueryResult : public QWidget
{
    Q_OBJECT

public:
    QueryResult(const QString &studentID,QWidget *parent=nullptr);
    //explicit QueryResult(QWidget *parent = nullptr);
    ~QueryResult();

    QTextBrowser *nametextBrowser;
    QTextBrowser *IDtextBrowser;
    //  term1~8
    QTableWidget *course_class1;
    QTableWidget *course_class2;
    QTableWidget *course_class3;
    QTableWidget *course_class4;
    QTableWidget *course_class5;
    QTableWidget *course_class6;
    QTableWidget *course_class7;
    QTableWidget *course_class8;


private slots:
    void on_quitButton_clicked();


private:
    QString studentID;    //在 Ui::QueryResult *ui  之前声明
    Ui::QueryResult *ui;
};

#endif // QUERYRESULT_H
