#include "window01.h"
#include "ui_window01.h"
#include "window02.h"
#include "operation.h"
extern bool top_fail;
extern QString databaseName;
Window01::Window01(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window01)
{
    ui->setupUi(this);
    resize(671, 511);
    //连接数据库
    db=QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName(databaseName);
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("123456");
    if(!db.open())
    {
        qDebug()<<"Error: Connection with database failed: "<<db.lastError().text();

    }

    //排版
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //从拓扑排序的数据库中读取数据，然后存到表格中
    QSqlQuery query(db);
    for(int i=ui->tableWidget->rowCount();i>0;i--)
    {
        ui->tableWidget->removeRow(0);
    }
    QSqlRecord rec/*=query->record()*/;
    query.exec("select *from topresult");
    while(query.next())
    {
        int index = ui->tableWidget->rowCount(); // 获取当前行数，作为新行的索引
        ui->tableWidget->insertRow(index);

        // 假设列的名称是 "result1", "result2", "result3", "result4"
    // 或者您可以使用列的索引，如 query.value(0).toString(), query.value(1).toString() 等
    ui->tableWidget->setItem(index, 0, new QTableWidgetItem(query.value("result1").toString()));
        ui->tableWidget->setItem(index, 1, new QTableWidgetItem(query.value("result2").toString()));
        ui->tableWidget->setItem(index, 2, new QTableWidgetItem(query.value("result3").toString()));
        ui->tableWidget->setItem(index, 3, new QTableWidgetItem(query.value("result4").toString()));
    }
    db.close();

    //按钮换页
    s=new Window02();
    connect(ui->pushButton1,&QPushButton::clicked,[=](){
        choice_num=0;
        //当前窗口隐藏
        this->hide();
        //选课界面展示
        s->show();
    });
    connect(ui->pushButton2,&QPushButton::clicked,[=](){
        choice_num=1;
        this->hide();
        s->show();
    });
    connect(ui->pushButton3,&QPushButton::clicked,[=](){
        choice_num=2;
        this->hide();
        s->show();
    });
    connect(ui->pushButton4,&QPushButton::clicked,[=](){
        choice_num=3;
        this->hide();
        s->show();
    });

}

Window01::~Window01()
{
    delete ui;
}
