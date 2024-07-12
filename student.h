#pragma once
#include<string>
using namespace std;

struct student
{
	int student_id;
	string student_name;
	string course_class[8];
	student(int id, string name);
	student();
	student& operator=(student stu);
};