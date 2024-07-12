#include"manager.h"
#include"graph.h"
#include"operation.h"

VexNode result1[100];
VexNode result2[100];
VexNode result3[100];
VexNode result4[100];
Class_arrange_Graph G;



int main() 
{
	{
		Message msg;
		G.mes = &msg;
		course_manager m;
		vector<course> cslist = m.get_course();
		op oper;
		G.read(cslist, oper);

		oper.Top_Sort(result1, 0, &m);
		oper.Top_Sort(result2, 1, &m);
		oper.Top_Sort(result3, 2, &m);
		oper.Top_Sort(result4, 3, &m);

		//ѡ��������ķ�ʽ
		oper.Print_Top_Sort_Result();
		cout << "\n\n\n��������ѡ��Ŀγ̰����Ⱥ�˳��";
		char key = getchar();

		//ѡ��ͷ
		

		//ѡ����ȷֲ������Ƚ�����
		int choice;
		cin >> choice;

		if (key == '1')
			oper.Arrange(result1, choice, &m);
		else if (key == '2')
			oper.Arrange(result2, choice, &m);
		else if (key == '3')
			oper.Arrange(result3, choice, &m);
		else if (key == '4')
			oper.Arrange(result4, choice, &m);

		/*oper.Arrange_Selete(0, &m);*/
	}


	return 0;
}
