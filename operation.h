#ifndef OPERATION_H
#define OPERATION_H

#include<iostream>
#include<fstream>
#include<stdio.h>
#include<QString>
#include<vector>
#include<stack>
#include<queue>
#include"manager.h"
#include"graph.h"
using namespace std;

struct VexNode;

struct op//需要的操作
{
    void Top_Sort(VexNode* result, int choice, course_manager* m);
    void Arrange(VexNode* result, int choice, course_manager* m);
    void Print_Top_Sort_Result();
    void Arrange_Selete(int choice, course_manager* m);
    /*QString pick(VexNode* result, int i, course_manager* m);*/
    void print_course_class(int id, course_manager* m, vector<QString>& v);
    //int trans(QString d);
    void bk();

};

#endif // OPERATION_H
