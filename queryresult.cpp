#include "queryresult.h"
#include "ui_queryresult.h"

QueryResult::QueryResult(const QString &studentID, QWidget *parent)
    : QWidget(parent), studentID(studentID), ui(new Ui::QueryResult)
{
    ui->setupUi(this);

    //设置tabWidget页面名字
    ui->tabWidget->setTabText(0,"第一学期");
    ui->tabWidget->setTabText(1,"第二学期");
    ui->tabWidget->setTabText(2,"第三学期");
    ui->tabWidget->setTabText(3,"第四学期");
    ui->tabWidget->setTabText(4,"第五学期");
    ui->tabWidget->setTabText(5,"第六学期");
    ui->tabWidget->setTabText(6,"第七学期");
    ui->tabWidget->setTabText(7,"第八学期");

    //平均摆放
    ui->course_class1->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->course_class2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->course_class3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->course_class4->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->course_class5->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->course_class6->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->course_class7->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->course_class8->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //term1~8
    course_class1=ui->course_class1;
    course_class2=ui->course_class2;
    course_class3=ui->course_class3;
    course_class4=ui->course_class4;
    course_class5=ui->course_class5;
    course_class6=ui->course_class6;
    course_class7=ui->course_class7;
    course_class8=ui->course_class8;

    nametextBrowser = ui->nametextBrowser;
    IDtextBrowser = ui->IDtextBrowser;
}


QueryResult::~QueryResult()
{
    delete ui;
}

void QueryResult::on_quitButton_clicked()
{
    this->close();
}
