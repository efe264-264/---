#pragma once
#include<mysql.h>
#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<vector>
#include"course.h"
#include"student.h"
using namespace std;


class course_manager
{
public:
	course_manager();
	~course_manager();
	bool insert_course(course& cs);
	bool insert_student(student& stu);
	bool update_course(course& cs);
	bool update_student(student& stu,int i);
	bool delete_course(int course_id);
	vector<course> get_course(string condition = "");
	bool get_a_course(course& cs, string condition = "");
	bool get_student(student& stu, string condition = "");
private:
	MYSQL* con;
	const char* host = "127.0.0.1";
	const char* user = "root";
	const char* pw = "xu2365651";
	const char* database_name = "course_manager";
	const int port = 3306;
};