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
	string course_class[3];//��ͷ��¼��ʦ����
	int total[3];//��¼ÿ����ͷѧ������
	int allowance[3];//��¼ÿ����ͷ������
	string choice;
	course(int id, string name, int cre, int cl, string ac,string c);
	course();
};