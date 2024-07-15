#include "widget.h"
#include "queryresult.h"
#include "ui_widget.h"
#include <QSqlTableModel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)   //初始化指针
{
    ui->setupUi(this);


    database = QSqlDatabase::addDatabase("QMYSQL");    //加载数据库驱动
    database.setDatabaseName("lessonPlan");
    database.setHostName("localhost");
    database.setUserName("root");
    database.setPassword("zhangshuohan@126050");


    //创建数据库连接
    if(database.open()){
        QMessageBox::information(this,"连接提示","连接成功");
    }
    else{
        QMessageBox::warning(this,"连接提示","连接失败");
    }

    //链接信号与槽；谁发出信号 发出什么信号  谁处理信号  怎么处理
    connect(ui->IDlineEdit,SIGNAL(returnPressed()),this,SLOT(on_commitButton_clicked()));
    //   this指widget这个类

    connect(ui->cancelButton,&QPushButton::clicked,this,&Widget::on_cancelButton_clicked);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::addCoursesToTable(QTableWidget *tableWidget, QSqlQuery &sqlQuery)
{
    int row = 0; // 获取当前表格的行数，以便在末尾添加新行

    while (sqlQuery.next()) {
        // 从查询结果中提取课程信息
        QString courseName = sqlQuery.value("course_name").toString();
        int courseId = sqlQuery.value("course_id").toInt();
        int courseCredit = sqlQuery.value("course_credit").toInt();
        //QString courseNum = sqlQuery.value("course_num").toString();

        // 将新行添加到表格中
        tableWidget->insertRow(row);

        // 创建 QTableWidgetItem 实例并设置数据
        QTableWidgetItem *idItem = new QTableWidgetItem(QString::number(courseId));
        QTableWidgetItem *nameItem = new QTableWidgetItem(courseName);
        QTableWidgetItem *creditItem = new QTableWidgetItem(QString::number(courseCredit));
        //QTableWidgetItem *numItem = new QTableWidgetItem(courseNum);

        // 将 QTableWidgetItem 实例添加到表格中
        tableWidget->setItem(row, 0, idItem);
        tableWidget->setItem(row, 1, nameItem);
        tableWidget->setItem(row, 2, creditItem);
        //tableWidget->setItem(row, 3, numItem);

        // 移动到下一行
        row++;
    }
}

//查询按钮转到槽
void Widget::on_queryButton_clicked()
{
    //获取IDlineedit数据
    QString student_ID=ui->IDlineEdit->text();

    //错误：输入学号为空
    if(student_ID.isEmpty()){
        QMessageBox::warning(this,"错误","请输入学号");
        return;
    }

    //创建process对象
    QProcess *myProcess=new QProcess(this);
    myProcess->start(student_ID);   //studentID是从文本框中获取的信息，即输入的查询学生的学号

    //执行查询
    QSqlQuery query(database);
    query.prepare("SELECT student_id, student_name,course_class1,course_class2, course_class3, course_class4, course_class5, course_class6, course_class7, course_class8 FROM students WHERE student_id = :studentID");
    // 绑定学号参数
    query.bindValue(":studentID", student_ID);
    QueryResult *resultDialog = new QueryResult(student_ID,this);
    resultDialog->show(); // 以模式对话框方式显示

    if (query.exec()) {
        while (query.next()) {
            QString studentID = query.value("student_id").toString();
            QString name = query.value("student_name").toString();

            QString course_class1=query.value("course_class1").toString();
            QString course_class2=query.value("course_class2").toString();
            QString course_class3=query.value("course_class3").toString();
            QString course_class4=query.value("course_class4").toString();
            QString course_class5=query.value("course_class5").toString();
            QString course_class6=query.value("course_class6").toString();
            QString course_class7=query.value("course_class7").toString();
            QString course_class8=query.value("course_class8").toString();

            //#######    term1
            QStringList results1 = course_class1.split(','); // 使用逗号作为分隔符
            // 准备查询语句
            QString queryPattern1 = "SELECT * FROM courses WHERE course_name IN (%1)";
            QStringList placeholders1;
            for (int i = 0; i < results1.size(); ++i) {
                placeholders1 << QString(":%1").arg(i);
            }
            QString query1 = queryPattern1.arg(placeholders1.join(","));
            // 创建查询和执行
            QSqlQuery sqlQuery1;
            if (sqlQuery1.prepare(query1)) {
                for (int i = 0; i < results1.size(); ++i) {
                    sqlQuery1.bindValue(QString(":%1").arg(i), results1[i]);
                }
                if (sqlQuery1.exec()) {
                    addCoursesToTable(resultDialog->course_class1,sqlQuery1);
                } else {
                    qDebug() << "查询失败：" << sqlQuery1.lastError();
                }
            } else {
                qDebug() << "准备查询失败：" << sqlQuery1.lastError();
            }


            //#######    term2
            QStringList results2 = course_class2.split(','); // 使用逗号作为分隔符
            // 准备查询语句
            QString queryPattern2 = "SELECT * FROM courses WHERE course_name IN (%1)";
            QStringList placeholders2;
            for (int i = 0; i < results2.size(); ++i) {
                placeholders2 << QString(":%1").arg(i);
            }
            QString query2 = queryPattern2.arg(placeholders2.join(","));
            // 创建查询和执行
            QSqlQuery sqlQuery2;
            if (sqlQuery2.prepare(query2)) {
                for (int i = 0; i < results2.size(); ++i) {
                    sqlQuery2.bindValue(QString(":%1").arg(i), results2[i]);
                }
                if (sqlQuery2.exec()) {
                    addCoursesToTable(resultDialog->course_class2,sqlQuery2);
                } else {
                    qDebug() << "查询失败：" << sqlQuery2.lastError();
                }
            } else {
                qDebug() << "准备查询失败：" << sqlQuery2.lastError();
            }

            //#######    term3
            QStringList results3 = course_class3.split(','); // 使用逗号作为分隔符
            // 准备查询语句
            QString queryPattern3 = "SELECT * FROM courses WHERE course_name IN (%1)";
            QStringList placeholders3;
            for (int i = 0; i < results3.size(); ++i) {
                placeholders3 << QString(":%1").arg(i);
            }
            QString query3 = queryPattern3.arg(placeholders3.join(","));
            // 创建查询和执行
            QSqlQuery sqlQuery3;
            if (sqlQuery3.prepare(query3)) {
                for (int i = 0; i < results3.size(); ++i) {
                    sqlQuery3.bindValue(QString(":%1").arg(i), results3[i]);
                }
                if (sqlQuery3.exec()) {
                    addCoursesToTable(resultDialog->course_class3,sqlQuery3);
                } else {
                    qDebug() << "查询失败：" << sqlQuery3.lastError();
                }
            } else {
                qDebug() << "准备查询失败：" << sqlQuery3.lastError();
            }

            //#######    term4
            QStringList results4 = course_class4.split(','); // 使用逗号作为分隔符
            // 准备查询语句
            QString queryPattern4 = "SELECT * FROM courses WHERE course_name IN (%1)";
            QStringList placeholders4;
            for (int i = 0; i < results4.size(); ++i) {
                placeholders4 << QString(":%1").arg(i);
            }
            QString query4 = queryPattern4.arg(placeholders4.join(","));
            // 创建查询和执行
            QSqlQuery sqlQuery4;
            if (sqlQuery4.prepare(query4)) {
                for (int i = 0; i < results4.size(); ++i) {
                    sqlQuery4.bindValue(QString(":%1").arg(i), results4[i]);
                }
                if (sqlQuery4.exec()) {
                    addCoursesToTable(resultDialog->course_class4,sqlQuery4);
                } else {
                    qDebug() << "查询失败：" << sqlQuery4.lastError();
                }
            } else {
                qDebug() << "准备查询失败：" << sqlQuery4.lastError();
            }


            //#######    term5
            QStringList results5 = course_class5.split(','); // 使用逗号作为分隔符
            // 准备查询语句
            QString queryPattern5 = "SELECT * FROM courses WHERE course_name IN (%1)";
            QStringList placeholders5;
            for (int i = 0; i < results5.size(); ++i) {
                placeholders5 << QString(":%1").arg(i);
            }
            QString query5 = queryPattern5.arg(placeholders5.join(","));
            // 创建查询和执行
            QSqlQuery sqlQuery5;
            if (sqlQuery5.prepare(query5)) {
                for (int i = 0; i < results5.size(); ++i) {
                    sqlQuery5.bindValue(QString(":%1").arg(i), results5[i]);
                }
                if (sqlQuery5.exec()) {
                    addCoursesToTable(resultDialog->course_class5,sqlQuery5);
                } else {
                    qDebug() << "查询失败：" << sqlQuery5.lastError();
                }
            } else {
                qDebug() << "准备查询失败：" << sqlQuery5.lastError();
            }

            //#######    term6
            QStringList results6 = course_class6.split(','); // 使用逗号作为分隔符
            // 准备查询语句
            QString queryPattern6 = "SELECT * FROM courses WHERE course_name IN (%1)";
            QStringList placeholders6;
            for (int i = 0; i < results6.size(); ++i) {
                placeholders6 << QString(":%1").arg(i);
            }
            QString query6 = queryPattern6.arg(placeholders6.join(","));
            // 创建查询和执行
            QSqlQuery sqlQuery6;
            if (sqlQuery6.prepare(query6)) {
                for (int i = 0; i < results6.size(); ++i) {
                    sqlQuery6.bindValue(QString(":%1").arg(i), results6[i]);
                }
                if (sqlQuery6.exec()) {
                    addCoursesToTable(resultDialog->course_class6,sqlQuery6);
                } else {
                    qDebug() << "查询失败：" << sqlQuery6.lastError();
                }
            } else {
                qDebug() << "准备查询失败：" << sqlQuery6.lastError();
            }


            //#######    term7
            QStringList results7 = course_class7.split(','); // 使用逗号作为分隔符
            // 准备查询语句
            QString queryPattern7 = "SELECT * FROM courses WHERE course_name IN (%1)";
            QStringList placeholders7;
            for (int i = 0; i < results7.size(); ++i) {
                placeholders7 << QString(":%1").arg(i);
            }
            QString query7 = queryPattern7.arg(placeholders7.join(","));
            // 创建查询和执行
            QSqlQuery sqlQuery7;
            if (sqlQuery7.prepare(query7)) {
                for (int i = 0; i < results7.size(); ++i) {
                    sqlQuery7.bindValue(QString(":%1").arg(i), results7[i]);
                }
                if (sqlQuery7.exec()) {
                    addCoursesToTable(resultDialog->course_class7,sqlQuery7);
                } else {
                    qDebug() << "查询失败：" << sqlQuery7.lastError();
                }
            } else {
                qDebug() << "准备查询失败：" << sqlQuery7.lastError();
            }

            //#######    term8
            QStringList results8 = course_class8.split(','); // 使用逗号作为分隔符
            // 准备查询语句
            QString queryPattern8 = "SELECT * FROM courses WHERE course_name IN (%1)";
            QStringList placeholders8;
            for (int i = 0; i < results8.size(); ++i) {
                placeholders8 << QString(":%1").arg(i);
            }
            QString query8 = queryPattern8.arg(placeholders8.join(","));
            // 创建查询和执行
            QSqlQuery sqlQuery8;
            if (sqlQuery8.prepare(query8)) {
                for (int i = 0; i < results8.size(); ++i) {
                    sqlQuery8.bindValue(QString(":%1").arg(i), results8[i]);
                }
                if (sqlQuery8.exec()) {
                    addCoursesToTable(resultDialog->course_class8,sqlQuery8);
                } else {
                    qDebug() << "查询失败：" << sqlQuery8.lastError();
                }
            } else {
                qDebug() << "准备查询失败：" << sqlQuery8.lastError();
            }

            resultDialog->nametextBrowser->setText(name);
            resultDialog->IDtextBrowser->setText(studentID);
        }
    }



    else {
        QMessageBox::critical(this, "错误", "查询失败: " + query.lastError().text());
    }

    // 关闭数据库连接
    //database.close();
    //不关闭数据库，保证退出后能再次输入学号进行查询

}

//取消按钮
void Widget::on_cancelButton_clicked()
{
    this->close();
}

