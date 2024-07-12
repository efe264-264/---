#pragma once
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include"manager.h"
#include"operation.h"
using namespace std;

struct op;

//邻接表节点
struct AdjVexNode
{
	int AdjVex;//邻接点位序，即课程所对应的编号
	AdjVexNode* Next;//指向下一个邻接点的指针
	AdjVexNode();
};

//顶点表节点
struct VexNode
{
	int num;//课程编号
	string data;			//课程名称
	int credit;			//节点学分（每门课学分）
	AdjVexNode* FirstArc;		//后修课程
	AdjVexNode* FirstArc_pre;//先修课程
	int In_degree;			//课程入度
	int class_num;
	VexNode(int n,string d, int c,int cn);
	VexNode();
	VexNode& operator=(VexNode v);
};

//学期信息
struct Message
{
	int term_num;			//学期数
	int max_credit;			//每学期学分上限
	Message();
};

//图
struct Class_arrange_Graph
{
	VexNode* Vex;			//顶点表
	int VexNum;			//节点数
	int ArcNum;			//边数
	Message* mes;			//每学期的信息(允许修改)
	Class_arrange_Graph();
	Class_arrange_Graph& operator=(Class_arrange_Graph g);
	void read(vector<course> cslist, op oper);
};

