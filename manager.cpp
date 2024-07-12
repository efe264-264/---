#include"manager.h"

course_manager::course_manager()
{
	con = mysql_init(NULL);
	//ÉèÖÃ×Ö·û±àÂë
	mysql_options(con, MYSQL_SET_CHARSET_NAME, "GBK");

	if (!mysql_real_connect(con, host, user, pw, database_name, port, NULL, 0))
	{
		exit(1);
	}
}

course_manager::~course_manager()
{
	mysql_close(con);
}


bool course_manager::insert_course(course& cs)
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
}

bool course_manager::insert_student(student& stu)
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
}

bool course_manager::update_course(course& cs)
{
	char sql[1024];
	sprintf_s(sql, "update courses set course_name = '%s',course_credit = '%d',class_num='%d',after_course='%s',course_class1='%s',course_class2='%s',course_class3='%s',total1='%d',total2='%d',total3='%d',allowance1='%d',allowance2='%d',allowance3='%d',choice='%s'"
		"where course_id = %d", cs.course_name.c_str(), cs.course_credit, cs.class_num, cs.after_course.c_str(), cs.course_class[0].c_str(), cs.course_class[1].c_str(), cs.course_class[2].c_str(), cs.total[0], cs.total[1], cs.total[2], cs.allowance[0], cs.allowance[1], cs.allowance[2], cs.choice.c_str(), cs.course_id);

	if (mysql_query(con, sql))
	{
		fprintf(stderr, "Failed to update data : Error:%s\n", mysql_error(con));
		return false;
	}
	return true;
}

bool course_manager::update_student(student& stu,int i)
{
	char sql[1024];
	if (i == 1)
	{
		sprintf_s(sql, "update students set course_class1 = '%s'"
			"where student_id = %d", stu.course_class[0].c_str(), stu.student_id);
	}
	else if (i == 2)
	{
		sprintf_s(sql, "update students set course_class2 = '%s'"
			"where student_id = %d", stu.course_class[1].c_str(), stu.student_id);
	}
	else if (i == 3)
	{
		sprintf_s(sql, "update students set course_class3 = '%s'"
			"where student_id = %d", stu.course_class[2].c_str(), stu.student_id);
	}
	else if (i == 4)
	{
		sprintf_s(sql, "update students set course_class4 = '%s'"
			"where student_id = %d", stu.course_class[3].c_str(), stu.student_id);
	}
	else if (i == 5)
	{
		sprintf_s(sql, "update students set course_class5 = '%s'"
			"where student_id = %d", stu.course_class[4].c_str(), stu.student_id);
	}
	else if (i == 6)
	{
		sprintf_s(sql, "update students set course_class6 = '%s'"
			"where student_id = %d", stu.course_class[5].c_str(), stu.student_id);
	}
	else if (i == 7)
	{
		sprintf_s(sql, "update students set course_class7 = '%s'"
			"where student_id = %d", stu.course_class[6].c_str(), stu.student_id);
	}
	else
	{
		sprintf_s(sql, "update students set course_class8 = '%s'"
			"where student_id = %d", stu.course_class[7].c_str(), stu.student_id);
	}

	if (mysql_query(con, sql))
	{
		fprintf(stderr, "Failed to update data : Error:%s\n", mysql_error(con));
		return false;
	}
	return true;
}

bool course_manager::delete_course(int course_id)
{
	char sql[1024];
	sprintf_s(sql, "delete from courses where course_id = %d",course_id);

	if (mysql_query(con, sql))
	{
		fprintf(stderr, "Failed to delete data : Error:%s\n", mysql_error(con));
		return false;
	}
	return true;
}

vector<course> course_manager::get_course(string condition)
{
	vector<course> cslist;
	char sql[1024];
	sprintf_s(sql, "select * from courses %s", condition.c_str());

	if (mysql_query(con, sql))
	{
		fprintf(stderr, "Failed to selete data : Error:%s\n", mysql_error(con));
		return {};
	}
	MYSQL_RES* res = mysql_store_result(con);
	MYSQL_ROW row;
	while (row = mysql_fetch_row(res))
	{
		course cs;
		cs.course_id = atoi(row[0]);
		cs.course_name = row[1];
		cs.course_credit = atoi(row[2]);
		cs.class_num= atoi(row[3]);
		cs.after_course = row[4];
		cs.course_class[0] = row[5];
		cs.course_class[1] = row[6];
		cs.course_class[2] = row[7];
		cs.total[0] = atoi(row[8]);
		cs.total[1] = atoi(row[9]);
		cs.total[2] = atoi(row[10]);
		cs.allowance[0] = atoi(row[11]);
		cs.allowance[1] = atoi(row[12]);
		cs.allowance[2] = atoi(row[13]);
		cs.choice = row[14];

		cslist.push_back(cs);
	}
	return cslist;
}

bool course_manager::get_a_course(course& cs, string condition)
{
	char sql[1024];
	sprintf_s(sql, "select * from courses %s", condition.c_str());

	if (mysql_query(con, sql))
	{
		fprintf(stderr, "Failed to selete data : Error:%s\n", mysql_error(con));
		return false;
	}
	MYSQL_RES* res = mysql_store_result(con);
	MYSQL_ROW row;
	row = mysql_fetch_row(res);
	cs.course_id = atoi(row[0]);
	cs.course_name = row[1];
	cs.course_credit = atoi(row[2]);
	cs.class_num = atoi(row[3]);
	cs.after_course = row[4];
	cs.course_class[0] = row[5];
	cs.course_class[1] = row[6];
	cs.course_class[2] = row[7];
	cs.total[0] = atoi(row[8]);
	cs.total[1] = atoi(row[9]);
	cs.total[2] = atoi(row[10]);
	cs.allowance[0] = atoi(row[11]);
	cs.allowance[1] = atoi(row[12]);
	cs.allowance[2] = atoi(row[13]);
	cs.choice = row[14];
	return true;
}

bool course_manager::get_student(student& stu, string condition)
{
	char sql[1024];
	sprintf_s(sql, "select * from students %s", condition.c_str());

	if (mysql_query(con, sql))
	{
		fprintf(stderr, "Failed to selete data : Error:%s\n", mysql_error(con));
		return false;
	}
	MYSQL_RES* res = mysql_store_result(con);
	MYSQL_ROW row;
	row = mysql_fetch_row(res);
	stu.student_id = atoi(row[0]);
	stu.student_name = row[1];
	stu.course_class[0] = row[2];
	stu.course_class[1] = row[3];
	stu.course_class[2] = row[4];
	stu.course_class[3] = row[5];
	stu.course_class[4] = row[6];
	stu.course_class[5] = row[7];
	stu.course_class[6] = row[8];
	stu.course_class[7] = row[9];
	return true;
}



