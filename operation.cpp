#include"operation.h"
#include"graph.h"

extern VexNode result1[100];
extern VexNode result2[100];
extern VexNode result3[100];
extern VexNode result4[100];
extern Class_arrange_Graph G;


void op::Top_Sort(VexNode* result, int choice, course_manager* m)//进行四次不同的拓扑排序
{
	Class_arrange_Graph* g = new Class_arrange_Graph;
	*g = G;
	int tag = 0, i;
	AdjVexNode* p;
	queue<VexNode> S;
	stack <AdjVexNode*> S1;

	if (choice == 0)

		while (tag == 0)
		{
			tag = 1;
			for (i = g->VexNum - 1; i >= 0; i--)
				if (g->Vex[i].In_degree == 0)
				{
					S.push(g->Vex[i]);
					g->Vex[i].In_degree--;
					p = g->Vex[i].FirstArc;
					S1.push(p);
					tag = 0;
				}

			while (S1.empty() == false)
			{
				p = S1.top();
				S1.pop();

				while (p != nullptr)
				{
					g->Vex[p->AdjVex].In_degree--;
					p = p->Next;
				}
			}
		}



	else if (choice == 1)

		while (tag == 0)
		{
			tag = 1;
			for (i = 0; i < g->VexNum; i++)
				if (g->Vex[i].In_degree == 0)
				{
					S.push(g->Vex[i]);
					g->Vex[i].In_degree--;
					p = g->Vex[i].FirstArc;
					S1.push(p);
					tag = 0;
				}

			while (S1.empty() == false)
			{
				p = S1.top();
				S1.pop();

				while (p != nullptr)
				{
					g->Vex[p->AdjVex].In_degree--;
					p = p->Next;
				}
			}
		}



	else if (choice == 2)

		for (i = g->VexNum - 1; i >= 0; i--)
		{
			if (g->Vex[i].In_degree == 0)
			{
				S.push(g->Vex[i]);
				g->Vex[i].In_degree--;
				p = g->Vex[i].FirstArc;
				while (p != nullptr)
				{
					g->Vex[p->AdjVex].In_degree--;
					p = p->Next;
				}

				i = g->VexNum ;//此处有改动
				/*i = g->VexNum - 1;*/
			}
		}



	else

		for (i = 0; i < g->VexNum; i++)
		{
			if (g->Vex[i].In_degree == 0)
			{
				S.push(g->Vex[i]);
				g->Vex[i].In_degree--;
				p = g->Vex[i].FirstArc;
				while (p != nullptr)
				{
					g->Vex[p->AdjVex].In_degree--;
					p = p->Next;
				}

				i = -1;
			}
		}




	i = S.size();

	if (i < g->VexNum)
	{
		cout << "拓扑排序失败，课程先修关系可能存在环路，请按任意键回主菜单\n";
		getchar();
		system("cls");
		/*mainmenu();*/
	}

	for (i = 0; i < g->VexNum; i++)
	{
		if (S.empty() == false)
		{
			result[i] = S.front();
			S.pop();
		}
		else
		{
			cout << "拓扑排序弹栈失败,请按任意键回主菜单" << endl;
			getchar();
			/*mainmenu();*/
		}

	}
}

void op::Arrange(VexNode* result, int choice, course_manager*m)//要在录入课程课头信息前将原信息清空
{
	int i = 0, j, k, course_num, per_max_num, Sumcredit, tag;

	if (choice == 0)
		per_max_num = G.VexNum;
	else
	{
		//使课程均匀分布，可以整除和余数小于学期数的一半的情况
		if (G.VexNum % G.mes->term_num == 0 || G.VexNum % G.mes->term_num < G.mes->term_num / 2)
			per_max_num = G.VexNum / G.mes->term_num;
		else
			per_max_num = (G.VexNum / G.mes->term_num + 1);
	}

	VexNode* this_term_courses = new VexNode[G.VexNum];
	AdjVexNode* p;
	for (k = 0; k < G.VexNum; k++)
	{
		if (i == G.VexNum)	break;//使k记录最大学期数

		/*cout << "第" << k + 1 << "个学期的课程为：";*/

		Sumcredit = 0;       //本学期安排课程的总学分
		course_num = 0;	 //本学期安排课程的总数
		p = result[i].FirstArc_pre;  //先修课指针
		tag = 0;          //标志本学期是否有该课程的先修课程
		while (Sumcredit + result[i].credit <= G.mes->max_credit && tag == 0 && course_num < per_max_num)
		{
			while (p != nullptr && tag == 0)
			{
				for (j = 0; j < course_num; j++)
				{
					if (p->AdjVex == this_term_courses[j].num)
					{
						tag = 1;
						break;
					}
				}
				p = p->Next;
			}

			if (tag == 1) break;//如果本学期有该课程的先修课程，则该课程无法在本学期开课

			if (i == G.VexNum)	break;

			cout << result[i].data << endl;

			/*string key=pick(result, i,m);*/
			const string s = " where student_id=3";
			course cs;
			char con[1024];
			sprintf_s(con, " where course_id=%d", result[i].num);
			m->get_a_course(cs, con);
			student stu;
			m->get_student(stu,s);
			if (stu.course_class[k] == "n") stu.course_class[k] = "";
			stu.course_class[k] = result[i].data + cs.choice +','+stu.course_class[k];
			m->update_student(stu,k+1);

			Sumcredit += result[i].credit;
			this_term_courses[course_num] = result[i];
			/*if (i == G.VexNum)	break;*/
			i++;
			course_num++;
			p = result[i].FirstArc_pre;
		}

	}

	//if (k > G.mes->term_num)
	//{

	//	cout << "\n\n\n该课程安排先后顺序下，此策略无解,因为安排所需学期数超过最大学期数\n\n\n";
	//	cout << "请按任意键回主菜单" << endl;
	//	getchar();
	//	system("cls");
	//	/*mainmenu();*/
	//}

	cout << "\n\n\n 课程安排信息已经存入当前目录下，“各学期课程安排结果.txt” \n\n请按任意键回主菜单";
	getchar();
	system("pause");
	/*mainmenu();*/

}

void op::Print_Top_Sort_Result()
{
	cout << "各课程安排先后顺序为:\n" << endl;
	cout << "选择1：";
	for (int i = 0; i < G.VexNum; i++)
	{
		cout << result1[i].data << "  ";
	}

	cout << "\n\n选择2：";
	for (int i = 0; i < G.VexNum; i++)
	{
		cout << result2[i].data << "  ";
	}

	cout << "\n\n选择3：";
	for (int i = 0; i < G.VexNum; i++)
	{
		cout << result3[i].data << "  ";
	}

	cout << "\n\n选择4：";
	for (int i = 0; i < G.VexNum; i++)
	{
		cout << result4[i].data << "  ";
	}

}

void op::Arrange_Selete(int choice, course_manager*m)
{
	Top_Sort(result1, 0,m);
	Top_Sort(result2, 1,m);
	Top_Sort(result3, 2,m);
	Top_Sort(result4, 3,m);
	Print_Top_Sort_Result();//与界面有关
	cout << "\n\n\n请输入你选择的课程安排先后顺序：";
	char key = getchar();

	if (key == '1')
		Arrange(result1, choice,m);
	else if (key == '2')
		Arrange(result2, choice,m);
	else if (key == '3')
		Arrange(result3, choice,m);
	else if (key == '4')
		Arrange(result4, choice,m);

	else
	{
		cout << "选择有误，请按任意键回主菜单";
		getchar();
		/*mainmenu();*/
	}

}

//string op::pick(VexNode*result,int i, course_manager* m)//与界面有关
//{
//	cout << "该课程有" << result[i].class_num << "个课头" << endl;
//	vector<string>v;
//	print_course_class(result[i].num, m,v);
//	cout << "请输入您要选择的课头：";
//	string key;
//	cin >> key;
//	cout << "已为您选择" << key << "课头" << endl;
//
//	//使该课程余量减少
//	course cs;
	//char con[1024];
	//sprintf_s(con, " where course_id=%d", result[i].num);
	//m->get_a_course(cs, con);
//	cs.allowance[trans(key) - 1]--;
//	m->update_course(cs);
//	return key;
//}

void op::print_course_class(int id, course_manager* m, vector<string>& v)
{
	course cs;
	char con[1024];
	sprintf_s(con, " where course_id=%d", id);

	m->get_a_course(cs, con);
	for (int i = 0; i < cs.class_num; i++)
	{
		cout << i + 1 << " " << cs.course_class[i] << endl;
		v.push_back(cs.course_class[i]);
	}
}


VexNode::VexNode(int n,string d,int c,int cn)
{
	num = n;
	data = d;
	credit = c;
	FirstArc = NULL;
	FirstArc_pre = NULL;
	In_degree = 0;
	class_num = cn;
}

VexNode::VexNode()
{
	In_degree = 0;
	FirstArc = NULL;
	FirstArc_pre = NULL;
}

VexNode& VexNode::operator=(VexNode v)
{
	this->num = v.num;
	this->credit = v.credit;
	this->data = v.data;
	this->FirstArc = v.FirstArc;
	this->FirstArc_pre = v.FirstArc_pre;
	this->In_degree = v.In_degree; 
	this->class_num = v.class_num;
	return *this;
}

Message::Message()
{
	term_num = 8;
	max_credit = 40;
}

AdjVexNode::AdjVexNode()
{
	Next = NULL;
}

Class_arrange_Graph::Class_arrange_Graph()
{
	VexNum = 0;
	ArcNum = 0;
}

Class_arrange_Graph& Class_arrange_Graph::operator=(Class_arrange_Graph g)
{
	this->ArcNum = g.ArcNum;
	this->mes = g.mes;
	this->VexNum = g.VexNum;
	this->Vex = new VexNode[VexNum];
	for (int i = 0; i < VexNum; i++) this->Vex[i] = g.Vex[i];
	return *this;
}

int op::trans(string d)
{
	int sum = 0;
	int sig = 1;
	for (int i = 0; i < d.length(); i++)
	{
		if (d[i] == '-') sig = -1;
		else sum = sum * 10 + d[i] - '0';
	}
	return sum * sig;
}