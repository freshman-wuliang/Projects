#ifndef DATA_H
#define DATA_H


#define STU_NAME_SIZE 16   //学生姓名字符长度
#define STU_SEX_SIZE 6     //学生性别字符长度
#define STU_PHONE_SIZE 12  //学生手机字符长度



typedef struct         //学生成绩
{
	double ch;     //语文成绩
	double en;     //英语成绩
	double math;   //数学成绩
	double aver;   //平均成绩
}grade;



typedef struct    //学生信息结构体
{
	char stu_name[USER_NAME_SIZE];   //学生姓名
	char stu_sex[STU_SEX_SIZE];      //学生性别
	int stu_age;                     //学生年龄
	char stu_phone[STU_PHONE_SIZE];  //学生手机号
	grade stu_grade;                 //学生成绩
	int stu_rank;                    //学生排名
}stu_info,*pstu_info;



typedef struct ListNode   //链表
{
	stu_info data;
	struct ListNode *next;
}ListNode,*pListNode;



typedef struct    //数据结构体
{
	pListNode pHeadNode;   //链表头节点指针
	int list_length;   //链表长度
}data,*pdata;



//操作的数据的全局变量
data g_data;



//链表的操作


/*****************************
 *函数名称:
 *函数功能:
 *入口参数:
 *出口参数:
 *说明:
 *****************************/

//insertfun

/*****************************
 *函数名称:
 *函数功能:
 *入口参数:
 *出口参数:
 *说明:
 *****************************/

//locatefun

/*****************************
 *函数名称:
 *函数功能:
 *入口参数:
 *出口参数:
 *说明:
 *****************************/

//insertfun

/*****************************
 *函数名称:
 *函数功能:
 *入口参数:
 *出口参数:
 *说明:
 *****************************/

//insertfun

#endif
