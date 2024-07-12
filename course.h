#pragma once
#include<string>
using namespace std;

struct course
{
	int course_id;
	string course_name;
	int course_credit;
	int class_num;
	string after_course;
	string course_class[3];//课头记录老师名字
	int total[3];//记录每个课头学生总量
	int allowance[3];//记录每个课头的余量
	string choice;
	course(int id, string name, int cre, int cl, string ac,string c);
	course();
};