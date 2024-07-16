#include "window01.h"
#include "ui_window01.h"
#include "window02.h"
#include "operation.h"

Window01::Window01(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window01)
{
    ui->setupUi(this);

    //连接数据库
    db=QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("course_manager");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("xu2365651");

    //排版
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //从拓扑排序的数据库中读取数据，然后存到表格中
    QSqlQuery *query;
    for(int i=ui->tableWidget->rowCount();i>0;i--)
    {
        ui->tableWidget->removeRow(0);
    }
    QSqlRecord rec=query->record();
    query->exec("select *from topresult");
    while(query->next())
    {
        rec=query->record();
        int first=rec.indexOf("result1");
        int second=rec.indexOf("result2");
        int third=rec.indexOf("result3");
        int forth=rec.indexOf("result4");
        int index=ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(index);
        ui->tableWidget->setItem(index,0,new QTableWidgetItem(query->value(first).toString()));
        ui->tableWidget->setItem(index,1,new QTableWidgetItem(query->value(second).toString()));
        ui->tableWidget->setItem(index,2,new QTableWidgetItem(query->value(third).toString()));
        ui->tableWidget->setItem(index,3,new QTableWidgetItem(query->value(forth).toString()));
    }

    //按钮换页
    Window02 *s=new Window02();
    connect(ui->pushButton1,&QPushButton::clicked,[=](){
        choice_num=1;
        //当前窗口隐藏
        this->hide();
        //选课界面展示
        s->show();
    });
    connect(ui->pushButton2,&QPushButton::clicked,[=](){
        choice_num=2;
        this->hide();
        s->show();
    });
    connect(ui->pushButton3,&QPushButton::clicked,[=](){
        choice_num=3;
        this->hide();
        s->show();
    });
    connect(ui->pushButton4,&QPushButton::clicked,[=](){
        choice_num=4;
        this->hide();
        s->show();
    });
}

Window01::~Window01()
{
    delete ui;
}
