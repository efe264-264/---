#include "window02.h"
#include "ui_window02.h"
#include "window03.h"
#include "window01.h"

Window02::Window02(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window02)
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

    //展示所有数据
    //先把所有课头所有课程按照应该展示出来的状态存到数组中
    vector<courseinfo>all;
    vector<course>cslist=m.get_course();
    for(int i=0;i<cslist.size();i++)
    {
        course cs=cslist[i];
        for(int j=0;j<cs.class_num;j++)
        {
            courseinfo csi;
            csi.ID=cs.course_id;
            csi.NAME=cs.course_name;
            csi.id=j+1;
            csi.name=cs.course_class[j];
            all.push_back(csi);
        }
    }
    //从数组中提出来展示出来
    for(int i=0;i<all.size();i++)
    {
        courseinfo csi=all[i];

        QTableWidgetItem* item1=new QTableWidgetItem(csi.ID);

        QString str1=csi.NAME;
        QTableWidgetItem* item2=new QTableWidgetItem(str1);

        QTableWidgetItem* item3=new QTableWidgetItem(csi.id);

        QString str2=csi.name;
        QTableWidgetItem* item4=new QTableWidgetItem(str2);

        ui->tableWidget->setItem(i,0,item1);
        ui->tableWidget->setItem(i,1,item2);
        ui->tableWidget->setItem(i,2,item3);
        ui->tableWidget->setItem(i,3,item4);
    }


    //选上键   将所选课头的编号存到courses数据库的chioce里,
    int currentRow=ui->tableWidget->currentRow();
    int columnNeed=2;
    if(currentRow!=-1)
    {
        QTableWidgetItem* selecteditem=ui->tableWidget->item(currentRow,columnNeed);
        if(selecteditem)
        {
            QString data=selecteditem->text();
            connect(ui->pushButton,&QPushButton::clicked,[=](){
                QSqlQuery query(db);
                query.exec("insert into courses('choice') value('data')");
            });
        }
    }


    //确定键   完成选课，弹出一个信息窗口，选择均匀分布或者先紧后松
    QMessageBox* msgBox=new QMessageBox(QMessageBox::Question,"模式","请选择一种排课方式",QMessageBox::Ok|QMessageBox::Cancel);
    msgBox->button(QMessageBox::Ok)->setText("均匀安排");
    msgBox->button(QMessageBox::Cancel)->setText("先紧后松");
    connect(msgBox->button(QMessageBox::Ok),&QAbstractButton::clicked,[=](){
        int choice=1;
        oper.Arrange(result[choice_num],choice,&m);
    });
    connect(msgBox->button(QMessageBox::Cancel),&QAbstractButton::clicked,[=](){
        int choice=0;
        oper.Arrange(result[choice_num],choice,&m);
    });



    //详情键   换页
    Window03* s=new Window03();
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        this->hide();
        s->show();
    });
}

Window02::~Window02()
{
    delete ui;
}
