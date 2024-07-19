#include "window02.h"
#include "ui_window02.h"
#include "window01.h"
#include"mainwindow.h"
#include "queryresult.h"
extern int ID;
extern bool arrange_fail;
extern QString stuID;
extern QString databaseName;
Window02::Window02(QWidget *parent/*,QSqlDatabase *DB*/) :
    QMainWindow(parent)/*,db2(DB)*/,
    ui(new Ui::Window02)
{
    ui->setupUi(this);
    ui->pushButton_2->setText("查看结果");
    resize(660, 505);
    //连接数据库
    //连接数据库
    /*
    if(!db2.open())
    {
        qDebug()<<"Error: Connection with database failed: "<<db2.lastError().text();

    }*/



    //排版
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->pushButton_2->setText("退出");
    vector<courseinfo>all;
    //展示所有数据
    //先把所有课头所有课程按照应该展示出来的状态存到数组中
    {
        course_manager*m=new course_manager;
        vector<course>cslist=m->get_course();
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
        delete m;
    }
    //从数组中提出来展示出来
    for(int i=0;i<all.size();i++)
    {
        courseinfo csi=all[i];

        QString str1=QString::number(csi.ID);
        QTableWidgetItem* item1=new QTableWidgetItem(str1);

        QString str2=csi.NAME;
        QTableWidgetItem* item2=new QTableWidgetItem(str2);

        QString str3=QString::number(csi.id);
        QTableWidgetItem* item3=new QTableWidgetItem(str3);

        QString str4=csi.name;
        QTableWidgetItem* item4=new QTableWidgetItem(str4);

        ui->tableWidget->setItem(i,0,item1);
        ui->tableWidget->setItem(i,1,item2);
        ui->tableWidget->setItem(i,2,item3);
        ui->tableWidget->setItem(i,3,item4);
    }


    //选上键   将所选课头的编号存到courses数据库的chioce里,
    connect(ui->tableWidget,&QTableWidget::currentItemChanged, this, [=](){

    //});
    //int cR = ui->tableWidget->currentRow();
    //if (cR != -1)
    //{
       // QTableWidget* tableView=new QTableWidget;
        //tableView->setSelectionMode(QAbstractItemView::SingleSelection);


        int currentRow=ui->tableWidget->currentRow();
       qDebug()<< currentRow;
        //int currentRow=1;
        int columnNeed1=0;
        int columnNeed=2;
        const QTableWidgetItem* selecteditem=ui->tableWidget->item(currentRow,columnNeed);
        const QTableWidgetItem* selecteditem1=ui->tableWidget->item(currentRow,columnNeed1);
        if(selecteditem)
        {
            ui->tableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
            ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
            QString data=selecteditem->text();
            int data1=selecteditem1->text().toInt();
            //connect(ui->pushButton,&QPushButton::clicked,[=](){
            /*QSqlQuery query2(db2);
            bool success = query2.exec("update courses set choice=2 where course_id=1");
            if (!success) {
                // 处理错误
                qDebug() << "Database update failed:" << query2.lastError().text();
            }*/
            course cs;
            cs.choice=data;
            cs.course_id=data1;
            course_manager*mg=new course_manager;
            mg->update_course(cs);
        }
        else
        {
            qDebug() << "Cell is empty.";
        }

     });
    //}


    //确定键   完成选课，弹出一个信息窗口，选择均匀分布或者先紧后
    QMessageBox* msgBox=new QMessageBox(QMessageBox::Question,"模式","请选择一种排课方式",QMessageBox::Ok|QMessageBox::Cancel);
    msgBox->button(QMessageBox::Ok)->setText("均匀安排");
    msgBox->button(QMessageBox::Cancel)->setText("先紧后松");
    connect(ui->pushButton_3, &QPushButton::clicked, [=]() {
        msgBox->show();

        course_manager* m=new course_manager;
        // 连接对话框按钮的点击事件
        connect(msgBox->button(QMessageBox::Ok), &QAbstractButton::clicked, [=](){//均匀安排
            int choice = 1;

            oper.Arrange(result[choice_num], choice, m);
            if(arrange_fail==true)  {QMessageBox::information(this,"警告","此排序不满足均匀安排，请更换排序方式！");arrange_fail=false;}//检测是否合理
            msgBox->close(); // 显示完毕后关闭对话框

        });

        connect(msgBox->button(QMessageBox::Cancel), &QAbstractButton::clicked, [=](){
            int choice = 0;
            oper.Arrange(result[choice_num], choice, m);
            if(arrange_fail==true)  {QMessageBox::information(this,"警告","此排序不满足先紧后松安排，请更换排序方式！");arrange_fail=false;}//检测是否合理
            msgBox->close(); // 显示完毕后关闭对话框

        });
    });


    db2.close();

    //详情键   换页

  connect(ui->pushButton_2,&QPushButton::clicked,[=](){//退出

          //this->hide();
      //  neww=new MainWindow();
       //   neww->show();
          db2=QSqlDatabase::addDatabase("QMYSQL");
          db2.setDatabaseName(databaseName);
          db2.setHostName("localhost");
          db2.setUserName("root");
          db2.setPassword("123456");
          if(db2.open())
          {
              //QMessageBox::information(this,"连接","连接成功");
          }
          else
          {
              QMessageBox::warning(this,"连接","连接失败");
          }
          searchw=new QueryResult(stuID,this);
    //执行查询
    QSqlQuery query(db2);
    query.prepare("SELECT student_id, student_name,course_class1,class_1,course_class2,class_2, course_class3,class_3, course_class4,class_4, course_class5,class_5, course_class6,class_6, course_class7,class_7, course_class8,class_8 FROM students WHERE student_id = :studentID");
    // 绑定学号参数
    query.bindValue(":studentID", stuID);
    //QueryResult* searchw = new QueryResult(student_ID, this);
    searchw->show(); // 以模式对话框方式显示

    if (query.exec()) {
        if (query.first()) {
            QString studentID = query.value("student_id").toString();
            QString name = query.value("student_name").toString();

            //课程名称字符串
            QString course_class1 = query.value("course_class1").toString();
            QString course_class2 = query.value("course_class2").toString();
            QString course_class3 = query.value("course_class3").toString();
            QString course_class4 = query.value("course_class4").toString();
            QString course_class5 = query.value("course_class5").toString();
            QString course_class6 = query.value("course_class6").toString();
            QString course_class7 = query.value("course_class7").toString();
            QString course_class8 = query.value("course_class8").toString();


            //课程对应课头编号
            QString class_1 = query.value("class_1").toString();
            QString class_2 = query.value("class_2").toString();
            QString class_3 = query.value("class_3").toString();
            QString class_4 = query.value("class_4").toString();
            QString class_5 = query.value("class_5").toString();
            QString class_6 = query.value("class_6").toString();
            QString class_7 = query.value("class_7").toString();
            QString class_8 = query.value("class_8").toString();

            //课程名称的StringList
            QStringList classNum1 = class_1.split(',');
            QStringList classNum2 = class_2.split(',');
            QStringList classNum3 = class_3.split(',');
            QStringList classNum4 = class_4.split(',');
            QStringList classNum5 = class_5.split(',');
            QStringList classNum6 = class_6.split(',');
            QStringList classNum7 = class_7.split(',');
            QStringList classNum8 = class_8.split(',');


            //######## term1
            QStringList results1 = course_class1.split(',');
            for (int var = 0; var < results1.size(); ++var) {
                addCoursesToTable1(searchw->course_class1, results1[var], classNum1);
            }

            //######## term2
            QStringList results2 = course_class2.split(',');
            for (int var = 0; var < results2.size(); ++var) {
                addCoursesToTable1(searchw->course_class2, results2[var], classNum2);
            }

            //######## term3
            QStringList results3 = course_class3.split(',');
            /*  debug代码
            qDebug() << "results3:";
            for (const QString &item : results3) {
                qDebug() << item;
            }*/
            for (int var = 0; var < results3.size(); ++var) {
                addCoursesToTable1(searchw->course_class3, results3[var], classNum3);
            }

            //######## term4
            QStringList results4 = course_class4.split(',');
            for (int var = 0; var < results4.size(); ++var) {
                addCoursesToTable1(searchw->course_class4, results4[var], classNum4);
            }

            //######## term5
            QStringList results5 = course_class5.split(',');
            for (int var = 0; var < results5.size(); ++var) {
                addCoursesToTable1(searchw->course_class5, results5[var], classNum5);
            }

            //######## term6
            QStringList results6 = course_class6.split(',');
            for (int var = 0; var < results6.size(); ++var) {
                addCoursesToTable1(searchw->course_class6, results6[var], classNum6);
            }

            //######## term3
            QStringList results7 = course_class7.split(',');
            for (int var = 0; var < results7.size(); ++var) {
                addCoursesToTable1(searchw->course_class7, results7[var], classNum7);
            }

            //######## term8
            QStringList results8 = course_class8.split(',');
            for (int var = 0; var < results8.size(); ++var) {
                addCoursesToTable1(searchw->course_class8, results8[var], classNum8);
            }



            //将名字和学生学号放入相应的框里
            searchw->nametextBrowser->setText(name);
            searchw->IDtextBrowser->setText(studentID);
        }
        else {
            // 如果没有查询结果，则显示一个消息框提醒“未查询到该学生”
            QMessageBox::information(this, "查询结果", "未查询到该学生");
        }
    }

    else {
        QMessageBox::critical(this, "错误", "查询失败: " + query.lastError().text());
    }

    // 关闭数据库连接
    //database.close();
    //不关闭数据库，退出后能再次输入学号进行查询

          searchw->show();
    });
}





void Window02::addCoursesToTable1(QTableWidget* tableWidget, QString& courseName, QStringList& classNums)
{

  // 创建一个SQL查询，根据课程名称从courses表中查找相关信息
  QString queryPattern = "SELECT * FROM courses WHERE course_name = ?";
  QSqlQuery sqlQuery(queryPattern);
  sqlQuery.addBindValue(courseName);

  if (sqlQuery.exec()) {
        // 遍历查询结果，并显示课程信息
        while (sqlQuery.next()) {
            int courseId = sqlQuery.value("course_id").toInt();
            int courseCredit = sqlQuery.value("course_credit").toInt();

            // 将新行添加到表格中
            tableWidget->insertRow(tableWidget->rowCount());    //添加新行到表格的末尾行

            // 创建 QTableWidgetItem 实例并设置数据
            QTableWidgetItem* idItem = new QTableWidgetItem(QString::number(courseId));
            QTableWidgetItem* nameItem = new QTableWidgetItem(courseName);
            QTableWidgetItem* creditItem = new QTableWidgetItem(QString::number(courseCredit));

            // 将 QTableWidgetItem 实例添加到表格中
            tableWidget->setItem(tableWidget->rowCount() - 1, 0, idItem);
            tableWidget->setItem(tableWidget->rowCount() - 1, 1, nameItem);
            tableWidget->setItem(tableWidget->rowCount() - 1, 2, creditItem);
        }
  }
  else {
        qDebug() << "查询失败：" << sqlQuery.lastError();
  }

  // 处理课头编号
  int row1 = 0;
  for (const QString& classNum : classNums) {
        // 创建 QTableWidgetItem 实例并设置数据
        QTableWidgetItem* classItem = new QTableWidgetItem(classNum);

        // 将 QTableWidgetItem 实例添加到表格中
        tableWidget->setItem(row1, 3, classItem);

        // 移动到下一行
        row1++;
  }
}
Window02::~Window02()
{
    delete ui;
}

