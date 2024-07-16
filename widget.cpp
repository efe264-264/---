#include "widget.h"
#include "queryresult.h"
#include "ui_widget.h"
#include <QSqlTableModel>

Widget::Widget(QWidget *parent,QSqlDatabase *db)
    : QWidget(parent),database(db)
    , ui(new Ui::Widget)   //初始化指针
{

    ui->setupUi(this);


    //创建数据库连接
    if(database->open()){
        QMessageBox::information(this,"连接提示","连接成功");
    }
    else{
        QMessageBox::warning(this,"连接提示","连接失败");
    }

    //eg.
    //链接信号与槽；谁发出信号 发出什么信号  谁处理信号  怎么处理
    //connect(ui->IDlineEdit,SIGNAL(returnPressed()),this,SLOT(on_commitButton_clicked()));
    //   this指widget这个类
    connect(ui->cancelButton,&QPushButton::clicked,this,&Widget::on_cancelButton_clicked);
}

Widget::~Widget()
{
    delete ui;
}

/*
//将获取的课程信息放到表格中
void Widget::addCoursesToTable(QTableWidget *tableWidget, QSqlQuery &sqlQuery1,QStringList &classNums)
{
    int row=0;

    while (sqlQuery1.next()) {
        // 从查询结果中提取课程信息
        QString courseName = sqlQuery1.value("course_name").toString();
        int courseId = sqlQuery1.value("course_id").toInt();
        int courseCredit = sqlQuery1.value("course_credit").toInt();
        // 将新行添加到表格中
        tableWidget->insertRow(row);

        // 创建 QTableWidgetItem 实例并设置数据
        QTableWidgetItem *idItem = new QTableWidgetItem(QString::number(courseId));
        QTableWidgetItem *nameItem = new QTableWidgetItem(courseName);
        QTableWidgetItem *creditItem = new QTableWidgetItem(QString::number(courseCredit));

        // 将 QTableWidgetItem 实例添加到表格中
        tableWidget->setItem(row, 0, idItem);
        tableWidget->setItem(row, 1, nameItem);
        tableWidget->setItem(row, 2, creditItem);

        // 移动到下一行
        row++;
    }
    int row1=0;
    // 处理课头编号
    for (const QString &classNum : classNums) {
        //tableWidget->insertRow(row);
        // 创建 QTableWidgetItem 实例并设置数据
        QTableWidgetItem *classItem = new QTableWidgetItem(classNum);

        // 将 QTableWidgetItem 实例添加到表格中
        tableWidget->setItem(row1, 3, classItem);

        // 移动到下一行
        row1++;
    }
}
*/

void Widget::addCoursesToTable1(QTableWidget *tableWidget,  QString &courseName, QStringList &classNums)
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
            QTableWidgetItem *idItem = new QTableWidgetItem(QString::number(courseId));
            QTableWidgetItem *nameItem = new QTableWidgetItem(courseName);
            QTableWidgetItem *creditItem = new QTableWidgetItem(QString::number(courseCredit));

            // 将 QTableWidgetItem 实例添加到表格中
            tableWidget->setItem(tableWidget->rowCount() - 1, 0, idItem);
            tableWidget->setItem(tableWidget->rowCount() - 1, 1, nameItem);
            tableWidget->setItem(tableWidget->rowCount() - 1, 2, creditItem);
        }
    } else {
        qDebug() << "查询失败：" << sqlQuery.lastError();
    }

    // 处理课头编号
    int row1 = 0;
    for (const QString &classNum : classNums) {
        // 创建 QTableWidgetItem 实例并设置数据
        QTableWidgetItem *classItem = new QTableWidgetItem(classNum);

        // 将 QTableWidgetItem 实例添加到表格中
        tableWidget->setItem(row1, 3, classItem);

        // 移动到下一行
        row1++;
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
    QSqlQuery query(*database);
    query.prepare("SELECT student_id, student_name,course_class1,class_1,course_class2,class_2, course_class3,class_3, course_class4,class_4, course_class5,class_5, course_class6,class_6, course_class7,class_7, course_class8,class_8 FROM students WHERE student_id = :studentID");
    // 绑定学号参数
    query.bindValue(":studentID", student_ID);
    QueryResult *resultDialog = new QueryResult(student_ID,this);
    resultDialog->show(); // 以模式对话框方式显示

    if (query.exec()) {
        if(query.first()){
            QString studentID = query.value("student_id").toString();
            QString name = query.value("student_name").toString();

            //课程名称字符串
            QString course_class1=query.value("course_class1").toString();
            QString course_class2=query.value("course_class2").toString();
            QString course_class3=query.value("course_class3").toString();
            QString course_class4=query.value("course_class4").toString();
            QString course_class5=query.value("course_class5").toString();
            QString course_class6=query.value("course_class6").toString();
            QString course_class7=query.value("course_class7").toString();
            QString course_class8=query.value("course_class8").toString();


            //课程对应课头编号
            QString class_1=query.value("class_1").toString();
            QString class_2=query.value("class_2").toString();
            QString class_3=query.value("class_3").toString();
            QString class_4=query.value("class_4").toString();
            QString class_5=query.value("class_5").toString();
            QString class_6=query.value("class_6").toString();
            QString class_7=query.value("class_7").toString();
            QString class_8=query.value("class_8").toString();

            //课程名称的StringList
            QStringList classNum1=class_1.split(',');
            QStringList classNum2=class_2.split(',');
            QStringList classNum3=class_3.split(',');
            QStringList classNum4=class_4.split(',');
            QStringList classNum5=class_5.split(',');
            QStringList classNum6=class_6.split(',');
            QStringList classNum7=class_7.split(',');
            QStringList classNum8=class_8.split(',');


            //######## term1
            QStringList results1 = course_class1.split(',');
            for (int var = 0; var < results1.size(); ++var) {
                addCoursesToTable1(resultDialog->course_class1, results1[var], classNum1);
            }

            //######## term2
            QStringList results2 = course_class2.split(',');
            for (int var = 0; var < results2.size(); ++var) {
                addCoursesToTable1(resultDialog->course_class2, results2[var], classNum2);
            }

            //######## term3
            QStringList results3 = course_class3.split(',');
            /*  debug代码
            qDebug() << "results3:";
            for (const QString &item : results3) {
                qDebug() << item;
            }*/
            for (int var = 0; var < results3.size(); ++var) {
                addCoursesToTable1(resultDialog->course_class3, results3[var], classNum3);
            }

            //######## term4
            QStringList results4 = course_class4.split(',');
            for (int var = 0; var < results4.size(); ++var) {
                addCoursesToTable1(resultDialog->course_class4, results4[var], classNum4);
            }

            //######## term5
            QStringList results5 = course_class5.split(',');
            for (int var = 0; var < results5.size(); ++var) {
                addCoursesToTable1(resultDialog->course_class5, results5[var], classNum5);
            }

            //######## term6
            QStringList results6 = course_class6.split(',');
            for (int var = 0; var < results6.size(); ++var) {
                addCoursesToTable1(resultDialog->course_class6, results6[var], classNum6);
            }

            //######## term3
            QStringList results7 = course_class7.split(',');
            for (int var = 0; var < results7.size(); ++var) {
                addCoursesToTable1(resultDialog->course_class7, results7[var], classNum7);
            }

            //######## term8
            QStringList results8 = course_class8.split(',');
            for (int var = 0; var < results8.size(); ++var) {
                addCoursesToTable1(resultDialog->course_class8, results8[var], classNum8);
            }


            /**********    原对应addCoursesToTable函数的代码
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
            *****************/

            //将名字和学生学号放入相应的框里
            resultDialog->nametextBrowser->setText(name);
            resultDialog->IDtextBrowser->setText(studentID);
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

}

//取消按钮
void Widget::on_cancelButton_clicked()
{
    this->close();
}

