#include"course.h"

course::course(int id, string name, int cre, int cl, string ac,string c)
{
	course_id = id;
	course_name = name;
	course_credit = cre;
	class_num = cl;
	after_course = ac;
	choice = c;
}

course::course()
{
}