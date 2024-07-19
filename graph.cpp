#include"graph.h"
#include "qdebug.h"

extern Class_arrange_Graph G;

int Class_arrange_Graph::trans(QString d)
{
    string ds=d.toStdString();
    int sum = 0;
    int sig = 1;
    for (int i = 0; i < ds.length(); i++)
    {
        if (ds[i] == '-') sig = -1;
        else sum = sum * 10 + ds[i] - '0';
    }
    return sum * sig;
}

void Class_arrange_Graph::read(vector<course> cslist)
{
    G.Vex = new VexNode[cslist.size()];
    G.VexNum = cslist.size();
    for (int i = 0; i < cslist.size(); i++)
    {
        G.Vex[i].class_num = cslist[i].class_num;
        G.Vex[i].num = cslist[i].course_id-1;
        G.Vex[i].data = cslist[i].course_name;
        G.Vex[i].credit = cslist[i].course_credit;
        /*AdjVexNode* p=G.Vex[i].FirstArc;*/
        QString s = cslist[i].after_course;
        QString d = "";
        for (int j = 0; j < s.length(); j++)
        {
            if ((s[j] >= '0' && s[j] <= '9') || s[j] == '-')
            {
                d += s[j];
            }
            if ((s[j] < '0' || s[j] > '9' || (j == s.length() - 1)) && s[j] != '-')
            {
                int k = trans(d)-1;
                if (k == -2) break;
                G.Vex[k].In_degree++;

                //初始化FirstArc
                AdjVexNode* node = new AdjVexNode;
                node->AdjVex = k;
                node->Next = NULL;
                qDebug()<<G.Vex[i].num;
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
                //G.Vex[k].data = cslist[k].course_name;
                //G.Vex[k].num = cslist[k].course_id;
                AdjVexNode* node_pre = new AdjVexNode;
                node_pre->AdjVex = i;
                node_pre->Next = NULL;
                //qDebug()<<G.Vex[k].num;
                if (G.Vex[k].FirstArc_pre == NULL)
                {
                    G.Vex[k].FirstArc_pre = node_pre;
                    G.Vex[k].FirstArc_pre->Next = NULL;
                }
                else if (G.Vex[k].FirstArc_pre->Next == NULL)
                {
                    G.Vex[k].FirstArc_pre->Next = node_pre;
                    //qDebug()<<G.Vex[k].num;
                }
                else
                {
                    AdjVexNode* t = G.Vex[k].FirstArc_pre;
                    while (t->Next!= NULL) {t = t->Next;}
                    t->Next = node_pre;
                }


                G.ArcNum++;
                d = "";
            }
        }
    }
}

VexNode::VexNode(int n, QString d, int c, int cn)
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
