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

//�ڽӱ�ڵ�
struct AdjVexNode
{
	int AdjVex;//�ڽӵ�λ�򣬼��γ�����Ӧ�ı��
	AdjVexNode* Next;//ָ����һ���ڽӵ��ָ��
	AdjVexNode();
};

//�����ڵ�
struct VexNode
{
	int num;//�γ̱��
	string data;			//�γ�����
	int credit;			//�ڵ�ѧ�֣�ÿ�ſ�ѧ�֣�
	AdjVexNode* FirstArc;		//���޿γ�
	AdjVexNode* FirstArc_pre;//���޿γ�
	int In_degree;			//�γ����
	int class_num;
	VexNode(int n,string d, int c,int cn);
	VexNode();
	VexNode& operator=(VexNode v);
};

//ѧ����Ϣ
struct Message
{
	int term_num;			//ѧ����
	int max_credit;			//ÿѧ��ѧ������
	Message();
};

//ͼ
struct Class_arrange_Graph
{
	VexNode* Vex;			//�����
	int VexNum;			//�ڵ���
	int ArcNum;			//����
	Message* mes;			//ÿѧ�ڵ���Ϣ(�����޸�)
	Class_arrange_Graph();
	Class_arrange_Graph& operator=(Class_arrange_Graph g);
	void read(vector<course> cslist, op oper);
};

