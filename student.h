#ifndef ___STUDENT_H___
#define ___STUDENT_H___

typedef int datatype;
typedef struct Info
{
	datatype id;
	char name[20];
	datatype score;
}Info;

typedef struct Node
{
	union{
		datatype total; //头结点数据域记录总人数
		Info stu; 		//普通节点数据域
	};
	struct Node* next; //指针域
}studentlist;

//创建
studentlist* create();
//判空
int empty(studentlist* S);
//申请节点
studentlist* node_apply(Info stu);
//尾插
int tail_insert(studentlist* S,Info stu);
//遍历
void show(studentlist* S);
//根据位置查找返回节点
studentlist* node_find(studentlist* S,int pos);
//任意删
int delete_pos(studentlist* S,int pos);
//按姓名删除
int delete_name(studentlist* S,char name[20]);
//按姓名查找
int search_name(studentlist* S,char name[20]);
//按成绩降序排序
void sort(studentlist* S);
//找出成绩最高的学生
void findbest(studentlist* S);
//修改学生信息
void update(studentlist* S);
#endif
