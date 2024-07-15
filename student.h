#ifndef STUDENT_H
#define STUDENT_H

#include<QString>
using namespace std;

struct student
{
    int student_id;
    QString student_name;
    QString course_class[8];
    student(int id, QString name);
    student();
    student& operator=(student stu);
};

#endif // STUDENT_H
