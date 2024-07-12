#include"operation.h"
#include"graph.h"

extern VexNode result1[100];
extern VexNode result2[100];
extern VexNode result3[100];
extern VexNode result4[100];
extern Class_arrange_Graph G;


void op::Top_Sort(VexNode* result, int choice, course_manager* m)//�����Ĵβ�ͬ����������
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

				i = g->VexNum ;//�˴��иĶ�
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
		cout << "��������ʧ�ܣ��γ����޹�ϵ���ܴ��ڻ�·���밴����������˵�\n";
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
			cout << "��������ջʧ��,�밴����������˵�" << endl;
			getchar();
			/*mainmenu();*/
		}

	}
}

void op::Arrange(VexNode* result, int choice, course_manager*m)//Ҫ��¼��γ̿�ͷ��Ϣǰ��ԭ��Ϣ���
{
	int i = 0, j, k, course_num, per_max_num, Sumcredit, tag;

	if (choice == 0)
		per_max_num = G.VexNum;
	else
	{
		//ʹ�γ̾��ȷֲ�����������������С��ѧ������һ������
		if (G.VexNum % G.mes->term_num == 0 || G.VexNum % G.mes->term_num < G.mes->term_num / 2)
			per_max_num = G.VexNum / G.mes->term_num;
		else
			per_max_num = (G.VexNum / G.mes->term_num + 1);
	}

	VexNode* this_term_courses = new VexNode[G.VexNum];
	AdjVexNode* p;
	for (k = 0; k < G.VexNum; k++)
	{
		if (i == G.VexNum)	break;//ʹk��¼���ѧ����

		/*cout << "��" << k + 1 << "��ѧ�ڵĿγ�Ϊ��";*/

		Sumcredit = 0;       //��ѧ�ڰ��ſγ̵���ѧ��
		course_num = 0;	 //��ѧ�ڰ��ſγ̵�����
		p = result[i].FirstArc_pre;  //���޿�ָ��
		tag = 0;          //��־��ѧ���Ƿ��иÿγ̵����޿γ�
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

			if (tag == 1) break;//�����ѧ���иÿγ̵����޿γ̣���ÿγ��޷��ڱ�ѧ�ڿ���

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

	//	cout << "\n\n\n�ÿγ̰����Ⱥ�˳���£��˲����޽�,��Ϊ��������ѧ�����������ѧ����\n\n\n";
	//	cout << "�밴����������˵�" << endl;
	//	getchar();
	//	system("cls");
	//	/*mainmenu();*/
	//}

	cout << "\n\n\n �γ̰�����Ϣ�Ѿ����뵱ǰĿ¼�£�����ѧ�ڿγ̰��Ž��.txt�� \n\n�밴����������˵�";
	getchar();
	system("pause");
	/*mainmenu();*/

}

void op::Print_Top_Sort_Result()
{
	cout << "���γ̰����Ⱥ�˳��Ϊ:\n" << endl;
	cout << "ѡ��1��";
	for (int i = 0; i < G.VexNum; i++)
	{
		cout << result1[i].data << "  ";
	}

	cout << "\n\nѡ��2��";
	for (int i = 0; i < G.VexNum; i++)
	{
		cout << result2[i].data << "  ";
	}

	cout << "\n\nѡ��3��";
	for (int i = 0; i < G.VexNum; i++)
	{
		cout << result3[i].data << "  ";
	}

	cout << "\n\nѡ��4��";
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
	Print_Top_Sort_Result();//������й�
	cout << "\n\n\n��������ѡ��Ŀγ̰����Ⱥ�˳��";
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
		cout << "ѡ�������밴����������˵�";
		getchar();
		/*mainmenu();*/
	}

}

//string op::pick(VexNode*result,int i, course_manager* m)//������й�
//{
//	cout << "�ÿγ���" << result[i].class_num << "����ͷ" << endl;
//	vector<string>v;
//	print_course_class(result[i].num, m,v);
//	cout << "��������Ҫѡ��Ŀ�ͷ��";
//	string key;
//	cin >> key;
//	cout << "��Ϊ��ѡ��" << key << "��ͷ" << endl;
//
//	//ʹ�ÿγ���������
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