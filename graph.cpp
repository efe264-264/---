#include"graph.h"

extern Class_arrange_Graph G;

void Class_arrange_Graph::read(vector<course> cslist, op oper)
{
	G.Vex = new VexNode[cslist.size()];
	G.VexNum = cslist.size();
	for (int i = 0; i < cslist.size(); i++)
	{
		G.Vex[i].class_num = cslist[i].class_num;
		G.Vex[i].num = cslist[i].course_id;
		G.Vex[i].data = cslist[i].course_name;
		G.Vex[i].credit = cslist[i].course_credit;
		/*AdjVexNode* p=G.Vex[i].FirstArc;*/
		string s = cslist[i].after_course;
		string d = "";
		for (int j = 0; j < s.length(); j++)
		{
			if ((s[j] >= '0' && s[j] <= '9') || s[j] == '-')
			{
				d += s[j];
			}
			if ((s[j] < '0' || s[j] > '9' || j == s.length() - 1) && s[j] != '-')
			{
				int k = oper.trans(d);
				if (k == -1) break;
				G.Vex[k].In_degree++;

				//初始化FirstArc
				AdjVexNode* node = new AdjVexNode;
				node->AdjVex = k;
				node->Next = NULL;
				if (G.Vex[i].FirstArc == NULL)
				{
					G.Vex[i].FirstArc = node;
				}
				else if (G.Vex[i].FirstArc->Next == NULL)
				{
					G.Vex[i].FirstArc->Next = node;
				}
				else
				{
					AdjVexNode* p = G.Vex[i].FirstArc->Next;
					while (p->Next != NULL) p = p->Next;
					p->Next = node;
				}

				//初始化FirstArc_pre
				AdjVexNode* node_pre = new AdjVexNode;
				node_pre->AdjVex = i;
				node_pre->Next = NULL;
				if (G.Vex[k].FirstArc_pre == NULL)
				{
					G.Vex[k].FirstArc_pre = node_pre;
				}
				else if (G.Vex[k].FirstArc_pre->Next == NULL)
				{
					G.Vex[k].FirstArc_pre->Next = node_pre;
				}
				else
				{
					AdjVexNode* p = G.Vex[i].FirstArc_pre->Next;
					while (p->Next != NULL) p = p->Next;
					p->Next = node_pre;
				}


				G.ArcNum++;
				d = "";
			}
		}
	}
}