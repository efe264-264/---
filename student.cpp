#include"student.h"

student::student(int id, string name)
{
	student_id = id;
	student_name = name;
}

student::student()
{
}

student& student::operator=(student stu)
{
	this->student_id = stu.student_id;
	this->student_name = stu.student_name;
	for (int i = 0; i < 8; i++)
	{
		this->course_class[i] = stu.course_class[i];
	}
	return *this;
}