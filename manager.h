#ifndef MANAGER_H
#define MANAGER_H

#include<QSqlDatabase>
#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<vector>
#include<QString>
#include"student.h"
using namespace std;

struct course
{
    int course_id;
    QString course_name;
    int course_credit;
    int class_num;
    QString after_course;
    QString course_class[3];//课头记录老师名字
    int total[3];//记录每个课头学生总量
    int allowance[3];//记录每个课头的余量
    QString choice;
    //course(int id, QString name, int cre, int cl, QString ac,QString c);
    //course();
};

struct top_result
{
    QString result1;
    QString result2;
    QString result3;
    QString result4;
};


class course_manager
{
public:
    course_manager();
    ~course_manager();
    bool insert_course(course& cs);
    bool insert_student(student& stu);
    bool update_course(course& cs);
    bool update_student(student& stu,int i);
    bool update_top_result(top_result&tr);
    bool delete_course(int course_id);
    vector<course> get_course(QString condition = "");
    bool get_a_course(course& cs, QString condition = "");
    bool get_student(student& stu, QString condition = "");
    bool get_top_result(top_result&tr);
private:
    QSqlDatabase DB;
};

#endif // MANAGER_H
