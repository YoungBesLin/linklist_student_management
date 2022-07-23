#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
int main(int argc, const char *argv[])
{
	//创建学生表
	studentlist* S = create();
	if(NULL == S)
	{
		return -1;
	}
	while(1)
	{
		printf("*****************************************\n");
		printf("*\t欢迎进入学生管理系统\t 	*\n");
		printf("*\t0.退出系统\t\t 	*\n");
		printf("*\t1.增加学生信息\t\t 	*\n");
		printf("*\t2.删除学生信息\t\t 	*\n");
		printf("*\t3.修改学生信息\t\t 	*\n");
		printf("*\t4.按姓名查找信息\t\t*\n");
		printf("*\t5.按成绩降序排列学生信息\t*\n");
		printf("*\t6.输出成绩最高的学生信息\t*\n");
		printf("*\t7.输出系统内所有学生信息\t*\n");
		printf("*****************************************\n");
		printf("请选择操作：");
		int choose;
		scanf("%d",&choose);
		printf("\n");
		int n,pos;
		char name[20]="";
		int id,score;
		char old_name[20]="";
		char new_name[20]="";
		switch(choose)
		{
		case 1:
			printf("请输入学生个数：");
			scanf("%d",&n);
			printf("正在录入学生信息...\n");
			Info stu;
			for(int i=1;i<=n;i++)
			{
				printf("请输入第%d位学生ID：",i);
				scanf("%d",&stu.id);
				printf("请输入第%d位学生姓名：",i);
				scanf("%s",stu.name);
				getchar();
				printf("请输入第%d位学生成绩：",i);
				scanf("%d",&stu.score);
				tail_insert(S,stu);
				printf("\n");
			}
			show(S);
			break;
		case 2:
			printf("请输入要删除的学生姓名：");
			scanf("%s",name);
			getchar();
			delete_name(S,name);
			show(S);
			break;
		case 3:
			update(S);
			break;
		case 4:
			printf("请要查找的学生姓名：");
			scanf("%s",name);
			getchar();
			search_name(S,name);
			break;
		case 5:
			printf("按成绩降序学生信息\n");
			sort(S);
			show(S);
			break;
		case 6:
			findbest(S);
			break;
		case 7:
			show(S);
			break;
		case 0:
			exit(0);
		}
	}
	return 0;
}
