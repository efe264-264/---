#include "window03.h"
#include "ui_window03.h"
#include "window01.h"
Window03::Window03(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window03)
{
    ui->setupUi(this);

    //连接数据库
    db=QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("course_manager");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("xu2365651");

    //显示每个学期腰上的课，不显示课头
    QSqlQuery* query;
    QSqlRecord rec=query->record();
    query->exec("select *from students");

    int index1=rec.indexOf("course_class1");
    QString course_class1=query->value(index1).toString();
    ui->tableWidget->setItem(0,0,new QTableWidgetItem(course_class1));

    int index2=rec.indexOf("course_class2");
    QString course_class2=query->value(index2).toString();
    ui->tableWidget_3->setItem(0,0,new QTableWidgetItem(course_class2));

    int index3=rec.indexOf("course_class3");
    QString course_class3=query->value(index3).toString();
    ui->tableWidget_8->setItem(0,0,new QTableWidgetItem(course_class3));

    int index4=rec.indexOf("course_class4");
    QString course_class4=query->value(index4).toString();
    ui->tableWidget_2->setItem(0,0,new QTableWidgetItem(course_class4));

    int index5=rec.indexOf("course_class5");
    QString course_class5=query->value(index5).toString();
    ui->tableWidget41->setItem(0,0,new QTableWidgetItem(course_class5));

    int index6=rec.indexOf("course_class6");
    QString course_class6=query->value(index6).toString();
    ui->tableWidget_5->setItem(0,0,new QTableWidgetItem(course_class6));

    int index7=rec.indexOf("course_class7");
    QString course_class7=query->value(index7).toString();
    ui->tableWidget_6->setItem(0,0,new QTableWidgetItem(course_class7));

    int index8=rec.indexOf("course_class8");
    QString course_class8=query->value(index8).toString();
    ui->tableWidget_7->setItem(0,0,new QTableWidgetItem(course_class8));

    connect(ui->pushButton,&QPushButton::clicked,[=](){
        this->hide();
    });

}

Window03::~Window03()
{
    delete ui;
}
