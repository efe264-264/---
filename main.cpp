/*#include <QCoreApplication>
#include<QString>
#include<QSql>
#include<QSqlQuery>
#include<QsqlError>
#include<QDebug>
#include"manager.h"
#include"graph.h"
#include"operation.h"
using namespace std;

VexNode result1[100];
VexNode result2[100];
VexNode result3[100];
VexNode result4[100];
Class_arrange_Graph G;

int ID;

int main()
{

    {
        Message msg;
        G.mes = &msg;
        course_manager m;
        vector<course> cslist = m.get_course();
        op oper;
        G.read(cslist);

        oper.Top_Sort(result1, 0, &m);//结果写到数据库里
        oper.Top_Sort(result2, 1, &m);
        oper.Top_Sort(result3, 2, &m);
        oper.Top_Sort(result4, 3, &m);

        top_result tr;
        for(int i=0;i<5;i++)//课程总数最后需要修改
        {
            tr.result1+=result1[i].data+",";
            tr.result2+=result2[i].data+",";
            tr.result3+=result3[i].data+",";
            tr.result4+=result4[i].data+",";
        }

        m.update_top_result(tr);


        //选拓扑排序的方式
        oper.Print_Top_Sort_Result();
        //cout << "\n\n\n请输入你选择的课程安排先后顺序：";
        char key = '1';

        //选课头


        //选择均匀分布(1)还是先紧后松(0)
        int choice=1;
        //cin >> choice;

        if (key == '1')
            oper.Arrange(result1, choice, &m);
        else if (key == '2')
            oper.Arrange(result2, choice, &m);
        else if (key == '3')
            oper.Arrange(result3, choice, &m);
        else if (key == '4')
            oper.Arrange(result4, choice, &m);

        /*oper.Arrange_Selete(0, &m);*/
/*    }

    return 0;
}*/

#include "window01.h"
#include "window02.h"
#include "window03.h"
#include <QApplication>
#include"manager.h"
#include"graph.h"
#include"operation.h"

//用来存四个拓扑排序的数据
int choice_num;
VexNode result1[100];
VexNode result2[100];
VexNode result3[100];
VexNode result4[100];
VexNode result[4][100];
Class_arrange_Graph G;


int main(int argc, char *argv[])
{
    //完成拓扑排序和拓扑排序结果放到数据库里的操作，第一个界面完成展示
    Message msg;
    G.mes = &msg;

    op oper;
    course_manager m;

    //把数据库的course传到cslist中
    vector<course>cslist=m.get_course("");
    G.read(cslist);

    //四个拓扑排序先存到四个全局变量数组中
    oper.Top_Sort(result1,0,&m);
    oper.Top_Sort(result2,1,&m);
    oper.Top_Sort(result3,2,&m);
    oper.Top_Sort(result4,3,&m);
    for(int j=0;j<100;j++)
    {
        result[0][j]=result1[j];
        result[1][j]=result2[j];
        result[2][j]=result3[j];
        result[3][j]=result4[j];
    }
    //构造完四个数组之后，把四个数组的数据传到topresult数据库里
    QSqlQuery query;
    for(int i=0;i<100;i++)
    {
        query.exec("insert into topresult('result1','result2','result3',result4') value('result1[i]','reault2[i]','result3[i]','result4[i]')");
    }
    //至此完成拓扑排序的四种情况的排序，以及将结果放到数据库中，
    QApplication a(argc, argv);
    Window01 w;
    w.show();

    return a.exec();
}

