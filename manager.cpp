#include<QSql>
#include<QSqlQuery>
#include<QsqlError>
#include<QDebug>
#include<QString>
#include"manager.h"
extern QString databaseName;
course_manager::course_manager()
{
    DB=QSqlDatabase::addDatabase("QMYSQL");//加载mysql驱动
    DB.setDatabaseName(databaseName);                      //数据库名字
    DB.setHostName("localhost");                   //数据库地址，本地默认localhost
    DB.setUserName("root");                            //用户名，本地默认root
    DB.setPassword("123456");                       //密码，你自己设置的那个
    if(!DB.open())
    {
        qDebug()<<"Error: Connection with database failed: "<<DB.lastError().text();

    }
}

course_manager::~course_manager()
{
    DB.close();
}


/*bool course_manager::insert_course(course& cs)
{


    char sql[1024];
    sprintf_s(sql, "insert into courses(course_id,course_name,course_credit,class_num,after_course,course_class1,course_class2,course_class3,total1,total2,total3,allowance1,allowance2,allowance3,choice) values(%d,'%s',%d,%d,'%s','%s','%s','%s',%d,%d,%d,%d,%d,%d,'%s')",
              cs.course_id, cs.course_name.c_str(), cs.course_credit, cs.class_num, cs.after_course.c_str(),cs.course_class[0].c_str(),cs.course_class[1].c_str(),cs.course_class[2].c_str(),cs.total[0], cs.total[1], cs.total[2],cs.allowance[0], cs.allowance[1], cs.allowance[2], cs.choice.c_str());

    if (mysql_query(con, sql))
    {
        fprintf(stderr, "Failed to insert data : Error:%s\n", mysql_error(con));
        return false;
    }
    return true;
}*/

/*bool course_manager::insert_student(student& stu)
{
    char sql[1024];
    sprintf_s(sql, "insert into students(student_id,student_name,course_class1,course_class2,course_class3,course_class4,course_class5,course_class6,course_class7,course_class8) values(%d,'%s','%s','%s','%s','%s','%s','%s','%s','%s')",
              stu.student_id, stu.student_name.c_str(), stu.course_class[0].c_str(), stu.course_class[1].c_str(), stu.course_class[2].c_str(), stu.course_class[3].c_str(), stu.course_class[4].c_str(), stu.course_class[5].c_str(), stu.course_class[6].c_str(), stu.course_class[7].c_str());

    if (mysql_query(con, sql))
    {
        fprintf(stderr, "Failed to insert data : Error:%s\n", mysql_error(con));
        return false;
    }
    return true;
}*/

bool course_manager::update_course(course& cs)
{
    QSqlQuery query;
    bool ok;
    ok = query.exec(QString("UPDATE courses SET choice='%1' WHERE course_id=%2")
                        .arg(cs.choice).arg(cs.course_id));
    //ok = query.exec("UPDATE courses SET choice=2 WHERE course_id=1");
    if (!ok)
        qDebug() << "Update error:" << query.lastError().text();
    return ok;
}

bool course_manager::update_student(student& stu,int i)
{
    QSqlQuery query;
    bool ok;

    if (i == 1)
    {
        ok = query.exec(QString("UPDATE students SET course_class1='%1',class_1='%2' WHERE student_id=%3")
                            .arg(stu.course_class[0]).arg(stu.term_class[0]).arg(stu.student_id));
        //sprintf_s(sql, "update students set course_class1 = '%s'"
        //               "where student_id = %d", stu.course_class[0].c_str(), stu.student_id);
    }
    else if (i == 2)
    {
        ok = query.exec(QString("UPDATE students SET course_class2='%1',class_2='%2' WHERE student_id=%3")
                            .arg(stu.course_class[1]).arg(stu.term_class[1]).arg(stu.student_id));
        //sprintf_s(sql, "update students set course_class2 = '%s'"
        //             "where student_id = %d", stu.course_class[1].c_str(), stu.student_id);
    }
    else if (i == 3)
    {
        ok = query.exec(QString("UPDATE students SET course_class3='%1',class_3='%2' WHERE student_id=%3")
                            .arg(stu.course_class[2]).arg(stu.term_class[2]).arg(stu.student_id));
        //sprintf_s(sql, "update students set course_class3 = '%s'"
        //             "where student_id = %d", stu.course_class[2].c_str(), stu.student_id);
    }
    else if (i == 4)
    {
        ok = query.exec(QString("UPDATE students SET course_class4='%1',class_4='%2' WHERE student_id=%3")
                            .arg(stu.course_class[3]).arg(stu.term_class[3]).arg(stu.student_id));
        //sprintf_s(sql, "update students set course_class4 = '%s'"
        //             "where student_id = %d", stu.course_class[3].c_str(), stu.student_id);
    }
    else if (i == 5)
    {
        ok = query.exec(QString("UPDATE students SET course_class5='%1',class_5='%2' WHERE student_id=%3")
                            .arg(stu.course_class[4]).arg(stu.term_class[4]).arg(stu.student_id));
        //sprintf_s(sql, "update students set course_class5 = '%s'"
        //             "where student_id = %d", stu.course_class[4].c_str(), stu.student_id);
    }
    else if (i == 6)
    {
        ok = query.exec(QString("UPDATE students SET course_class6='%1',class_6='%2' WHERE student_id=%3")
                            .arg(stu.course_class[5]).arg(stu.term_class[5]).arg(stu.student_id));
        //sprintf_s(sql, "update students set course_class6 = '%s'"
        //             "where student_id = %d", stu.course_class[5].c_str(), stu.student_id);
    }
    else if (i == 7)
    {
        ok = query.exec(QString("UPDATE students SET course_class7='%1',class_7='%2' WHERE student_id=%3")
                            .arg(stu.course_class[6]).arg(stu.term_class[6]).arg(stu.student_id));
        //sprintf_s(sql, "update students set course_class7 = '%s'"
        //             "where student_id = %d", stu.course_class[6].c_str(), stu.student_id);
    }
    else
    {
        ok = query.exec(QString("UPDATE students SET course_class8='%1',class_8='%2' WHERE student_id=%3")
                            .arg(stu.course_class[7]).arg(stu.term_class[7]).arg(stu.student_id));
        //sprintf_s(sql, "update students set course_class8 = '%s'"
        //             "where student_id = %d", stu.course_class[7].c_str(), stu.student_id);
    }

    if (!ok)
        qDebug() << "Update error:" << query.lastError().text();
    return ok;
}

/*bool course_manager::update_top_result(top_result&tr)
{
    QSqlQuery query;
    bool ok;
    ok = query.exec(QString("UPDATE topresult SET result1='%1',result2='%2',result3='%3',result4='%4' WHERE num=1")
                        .arg(tr.result1).arg(tr.result2).arg(tr.result3).arg(tr.result4));
    if (!ok)
        qDebug() << "Update error:" << query.lastError().text();
    return ok;
}*/

bool course_manager::get_student(student& stu, QString condition)
{
    QSqlQuery query;
    if (query.exec("SELECT * FROM students"+condition))
    {
        query.next();
        stu.student_id = query.value(0).toInt(); // 假设第一列是name
        stu.student_name  = query.value(1).toString(); // 假设第二列是age
        stu.course_class[0] = query.value(2).toString();
        stu.term_class[0] = query.value(3).toString();
        stu.course_class[1] = query.value(4).toString();
        stu.term_class[1] = query.value(5).toString();
        stu.course_class[2] = query.value(6).toString();
        stu.term_class[2] = query.value(7).toString();
        stu.course_class[3] = query.value(8).toString();
        stu.term_class[3] = query.value(9).toString();
        stu.course_class[4] = query.value(10).toString();
        stu.term_class[4] = query.value(11).toString();
        stu.course_class[5] = query.value(12).toString();
        stu.term_class[5] = query.value(13).toString();
        stu.course_class[6] = query.value(14).toString();
        stu.term_class[6] = query.value(15).toString();
        stu.course_class[7] = query.value(16).toString();
        stu.term_class[7] = query.value(17).toString();

    } else {
        qDebug() << "Select error:" << query.lastError().text();
        return false;
    }

    return true;

}

/*bool course_manager::delete_course(int course_id)
{
    char sql[1024];
    sprintf_s(sql, "delete from courses where course_id = %d",course_id);

    if (mysql_query(con, sql))
    {
        fprintf(stderr, "Failed to delete data : Error:%s\n", mysql_error(con));
        return false;
    }
    return true;
}*/

vector<course> course_manager::get_course(QString condition)
{
    vector<course>cslist;

    QSqlQuery query;
    if (query.exec("SELECT * FROM courses"+condition))
    {
        while(query.next())
        {
            course cs;
            cs.course_id = query.value(0).toInt(); // 假设第一列是name
            cs.course_name  = query.value(1).toString(); // 假设第二列是age
            cs.course_credit = query.value(2).toInt();
            cs.class_num = query.value(3).toInt();
            cs.after_course = query.value(4).toString();
            cs.course_class[0] = query.value(5).toString();
            cs.course_class[1] = query.value(6).toString();
            cs.course_class[2] = query.value(7).toString();
            /*cs.total[0] = query.value(8).toInt();
            cs.total[1] = query.value(9).toInt();
            cs.total[2] = query.value(10).toInt();
            cs.allowance[0] = query.value(11).toInt();
            cs.allowance[1] = query.value(12).toInt();
            cs.allowance[2] = query.value(13).toInt();*/
            cs.choice = query.value(8).toString();
            cslist.push_back(cs);
        }

    } else {
        qDebug() << "Select error:" << query.lastError().text();
        return {};
    }

    return cslist;
}

bool course_manager::get_a_course(course& cs, QString condition)
{
    QSqlQuery query;
    if (query.exec("SELECT * FROM courses"+condition))
    {
        query.next();
        cs.course_id = query.value(0).toInt();
        cs.course_name  = query.value(1).toString();
        cs.course_credit = query.value(2).toInt();
        cs.class_num = query.value(3).toInt();
        cs.after_course = query.value(4).toString();
        cs.course_class[0] = query.value(5).toString();
        cs.course_class[1] = query.value(6).toString();
        cs.course_class[2] = query.value(7).toString();
        /*cs.total[0] = query.value(8).toInt();
        cs.total[1] = query.value(9).toInt();
        cs.total[2] = query.value(10).toInt();
        cs.allowance[0] = query.value(11).toInt();
        cs.allowance[1] = query.value(12).toInt();
        cs.allowance[2] = query.value(13).toInt();*/
        cs.choice = query.value(8).toString();


    } else {
        qDebug() << "Select error:" << query.lastError().text();
        return false;
    }

    return true;
}

/*bool course_manager::get_top_result(top_result&tr)
{
    QSqlQuery query;
    if (query.exec("SELECT * FROM topresult WHERE num=1"))
    {
        query.next();
        tr.result1 = query.value(0).toString();
        tr.result2 = query.value(1).toString();
        tr.result3 = query.value(2).toString();
        tr.result4 = query.value(3).toString();
    } else {
        qDebug() << "Select error:" << query.lastError().text();
        return false;
    }

    return true;
}*/
