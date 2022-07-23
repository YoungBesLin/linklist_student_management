#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
//创建
studentlist* create()
{
	studentlist* S = (studentlist*)malloc(sizeof(studentlist));
	if(NULL == S)
	{
		printf("创建失败!\n");
		return NULL;
	}
	//初始化
	S->total = 0; //总人数
	S->next = NULL;
	//printf("创建成功!\n");
	return S;
}
//判空
int empty(studentlist* S)
{
	if(NULL == S)
	{
		printf("表不合法!\n");
		return -1;
	}
	return S->next==NULL?1:0; //1表示空 0表示非空
}
//申请节点函数
studentlist* node_apply(Info stu)
{
	//申请节点
	studentlist* p = (studentlist*)malloc(sizeof(studentlist));
	if(NULL == p)
	{
		printf("申请失败!\n");
		return NULL;
	}
	//将数据存入节点
	p->stu = stu;
	p->next = NULL;
	return p;
}
//尾插
int tail_insert(studentlist* S,Info stu)
{
	//判断逻辑
	if(NULL==S)
	{
		printf("所给链表不合法\n");
		return -1;
	}
	//调用申请节点函数
	studentlist* p = node_apply(stu);
	//遍历指针指向最后一个节点
	studentlist* q = S;
	while(q->next != NULL)
	{
		q=q->next;
	}
	//插入逻辑
	q->next = p;
	//表的变化
	S->total++;
//	printf("尾插成功!\n");
	return 0;
}
//遍历 
void show(studentlist* S)
{
	if(NULL == S)
	{
		printf("遍历失败!\n");
		return;
	}
	if(empty(S))
	{
		printf("暂无信息!请添加!\n");
		return;
	}
	printf("****************学生信息****************\n");
	//遍历指针 
	studentlist* p = S->next;
	while(p!=NULL)
	{
		printf("ID:%d\t姓名:%s\t\t成绩:%d",p->stu.id,p->stu.name,p->stu.score);
		printf("\n");
		p=p->next;
	}
	printf("\n");
}
//根据位置查找返回节点
studentlist* node_find(studentlist* S,int pos)
{
	if(NULL == S||pos<0||pos>S->total)
	{
		printf("返回节点失败!\n");
		return NULL;
	}
	//查找节点
	studentlist* p = S;
	for(int i=1;i<=pos;i++)
	{
		p=p->next;
	}
	return p;
}

//任意删
int delete_pos(studentlist* S,int pos)
{
	//判断逻辑
	if(NULL==S||empty(S))
	{
		printf("删除失败!\n");
		return -1;
	}
	//调用按位查找返回节点
	//找到要删除位置的前驱节点
	studentlist* q = node_find(S,pos-1);
	//删除逻辑
	studentlist* p = q->next; 	//标记
	q->next = p->next; 			//孤立
	free(p); 					//删除
	p=NULL;
	//表的变化
	S->total--;
	//printf("任意删除成功!\n");
	return 0;
}
//按姓名删除,返回第一个删除成功的位置
int delete_name(studentlist* S,char name[20])
{
	//判断逻辑
	if(NULL==S || empty(S))
	{
		//printf("查找失败!\n");
		return -1;
	}
	//查找删除逻辑
	studentlist* p = S->next;
	
	for(int i=1;i<=S->total;i++)
	{
		if(strcmp(p->stu.name,name)==0)
		{
			delete_pos(S,i);
			printf("%s信息删除成功!\n",name);
			return i;
		}
		p=p->next;
	}
	printf("%s学生信息不存在!\n",name);
	return 0;
}
//按姓名查找
int search_name(studentlist* S,char name[20])
{
	//判断逻辑
	if(NULL==S || empty(S))
	{
		//printf("查找失败!\n");
		return -1;
	}
	//查找逻辑
	studentlist* p = S->next;
	for(int i=1;i<=S->total;i++)
	{
		if(strcmp(p->stu.name,name)==0)
		{
			printf("%s信息如下\n",name);
			printf("ID:%d\t姓名:%s\t\t成绩:%d\n",p->stu.id,p->stu.name,p->stu.score);
			printf("\n");
			return 0;
		}
		p=p->next;
	}
	printf("%s学生信息不存在!\n",name);
	return -1;
}
//按成绩降序排序
void sort(studentlist* S)
{
	if(NULL == S||empty(S))
	{
		printf("排序失败!\n");
		return;
	}
	//遍历指针 
	studentlist* p = S->next;
	//临时变量
	Info temp;
	//冒泡排序结构
	for(int i=1;i<S->total;i++)
	{
		for(int j=1;j<S->total;j++)
		{
			if(node_find(S,j)->stu.score<node_find(S,j+1)->stu.score)
			{
				temp = node_find(S,j)->stu;node_find(S,j)->stu = node_find(S,j+1)->stu;node_find(S,j+1)->stu=temp;
			}
		}
	}
}
//找出成绩最高的学生
void findbest(studentlist* S)
{
	if(NULL==S||empty(S))
	{
		printf("表不合法!\n");
		return ;
	}
	studentlist* p = S->next;
	int max = p->stu.score;
	int id = p->stu.id;
	char name[20]="";
	strcpy(name,p->stu.name);
	while(p->next!=NULL)
	{
		if(max<p->next->stu.score)
		{
			max = p->next->stu.score;
			id = p->next->stu.id;
			strcpy(name,p->next->stu.name);
		}
		p=p->next;
	}
	printf("成绩最高学生:\n");
	printf("ID:%d\t姓名:%s\t\t成绩:%d\n",id,name,max);
	printf("\n");
}
//修改学生信息
void update(studentlist* S)
{
	int id,score;
	char old_name[20];
	char new_name[20];
	printf("请输入你要修改的学生的姓名：");
	scanf("%s",old_name);
	getchar();
	//判断逻辑
	if(NULL==S || empty(S))
	{
		//printf("查找失败!\n");
		return;
	}
	//查找逻辑
	studentlist* p = S->next;
	for(int i=1;i<=S->total;i++)
	{
		if(strcmp(p->stu.name,old_name)==0)
		{
			printf("请输入新的ID：");
			scanf("%d",&id);
			printf("请输入新的姓名：");
			scanf("%s",new_name);
			getchar();
			printf("请输入新的成绩：");
			scanf("%d",&score);
			p->stu.id = id;
			strcpy(p->stu.name,new_name);
			p->stu.score = score;
			printf("修改成功!\n");
			printf("\n");
			return;
		}
		p=p->next;
	}
	printf("%s学生信息不存在!\n",old_name);
	return ;
}
