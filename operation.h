#pragma once
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include"manager.h"
#include"graph.h"
using namespace std;

struct VexNode;

struct op//��Ҫ�Ĳ���
{
	void Top_Sort(VexNode* result, int choice, course_manager* m);
	void Arrange(VexNode* result, int choice, course_manager* m);
	void Print_Top_Sort_Result();
	void Arrange_Selete(int choice, course_manager* m);
	/*string pick(VexNode* result, int i, course_manager* m);*/
	void print_course_class(int id, course_manager* m, vector<string>& v);
	int trans(string d);

};
