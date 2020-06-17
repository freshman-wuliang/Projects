#ifndef _DATA_OPERATION_H_
#define _DATA_OPERATION_H_

#include<stdlib.h>
#include"config.h"
#include<stdio.h>
#include"menu.h"
#include<string.h>

#define JIGE 60.000
#define JINDU 0.000001

typedef struct Node
{
  student_information STUDENT_INFORMATION;
  struct Node *next;
}ListNode,* pListNode;

pListNode LINKLIST_HEAD;   //声明链表表头的全局变量
pListNode LINKLIST_END;   //声明链表表尾的全局变量

/*******************
 *
 *
 ******************/

int loaddata();  //加载数据函数

/*******************
 *
 *
 ******************/

void AddRecord();   //增加学生记录函数

/*******************
 *
 *
 ******************/

void DisplayInformation();   //显示所有学生信息

/*******************
 *
 *
 ******************/

void FindStudent();   //查找学生函数

/*******************
 *
 *
 ******************/

pListNode FindName(char ch[]);

/*******************
 *
 *
 ******************/

pListNode FindNum(char ch[]);

/*******************
 *
 *
 ******************/

pListNode FindRank(int rank);

/*******************
 *
 *
 ******************/

void DeleteRecord();   //删除记录

/*******************
 *
 *
 ******************/
 
void ModifyRecord();  //修改记录

/*******************
 *
 *
 ******************/
 
void SummaryRecord();   //统计记录

/*******************
 *
 *
 ******************/

void SaveData();   //存数据到文件

/*******************
 *
 *
 ******************/

void PrintStudent(pListNode pstudent);   //打印单个学生信息

#endif
