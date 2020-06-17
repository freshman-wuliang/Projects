#include"menu.h"


/*****************************/

void print_tab(int num)
{
	int i;

	for (i=0;i<num;i++)
	{
		printf(" ");
	}
}

/*****************************/

void print_sign(char sign,int num)
{
	int i;

	for (i=0;i<num;i++)
	{
		printf("%c",sign);
	}
}

/*****************************/

void print_end(int num)
{
	int i;
	for (i=0;i<num;i++)
	{
		printf("\n");
	}
}

/*****************************/

void menu0_0()
{
	unsigned short sign_num = 14;

	system("clear");

	print_end(2);
	print_tab(GAP_NUM);
	print_sign(SIGN,sign_num);
	print_end(1);
	print_tab(GAP_NUM);
	print_sign(SIGN,3);
	printf("用户设置");
	print_sign(SIGN,3);
	print_end(1);
	print_tab(GAP_NUM);
	print_sign(SIGN,sign_num);
	print_end(1);
}

/*****************************/
 
void menu0_1()
{
	unsigned short sign_num = 22;   //边框的字符数
	unsigned short opt_num = 7;     //菜单选项数目
	char *p_opt_word[opt_num];      //存储选项内容
	p_opt_word[0] = "1.输入学生信息";
	p_opt_word[1] = "2.查询学生信息";
	p_opt_word[2] = "3.显示学生信息";
	p_opt_word[3] = "4.修改学生信息";
	p_opt_word[4] = "5.删除学生信息";
	p_opt_word[5] = "6.统计学生信息";
	p_opt_word[opt_num - 1] = "7.修改学生信息";

	system("clear");

	print_end(2);

	print_tab(GAP_NUM);       //1 line
	print_sign(SIGN,sign_num);
	print_end(1);

	print_tab(GAP_NUM);       //2 line
	print_sign(SIGN,3);
	printf("学生信息管理系统");
	print_sign(SIGN,3);
	print_end(1);

	print_tab(GAP_NUM);        //3 line
	print_sign(SIGN,sign_num);
	print_end(1);          

	print_tab(GAP_NUM);        //4 line
	print_sign(SIGN,3);
	print_sign(' ',3);
	printf("请选择1-7");
	print_sign(' ',4);
	print_sign(SIGN,3);
	print_end(1);

	for (int i=0;i<opt_num;i++)   //5 to 11 line
	{
		print_tab(GAP_NUM);
		print_sign(SIGN,3);
		print_sign(' ',1);
		printf("%s",p_opt_word[i]);
		print_sign(' ',1);
		print_sign(SIGN,3);
		print_end(1);
	}

	/*print_tab(GAP_NUM);       //5 line
	print_sign(SIGN,3);
	print_sign(' ',1);
	printf("1.输入员工信息");
	print_sign(' ',1);
	print_sign(SIGN,3);
	print_end(1);

	print_tab(GAP_NUM);       //6 line
	print_sign(SIGN,3);
	print_sign(' ',1);
	printf("2.查询员工信息");
	print_sign(' ',1);
	print_sign(SIGN,3);
	print_end(1);
        
        print_tab(GAP_NUM);       //7 line
	print_sign(SIGN,3);
	print_sign(' ',1);
	printf("3.显示员工信息");
	print_sign(' ',1);
	print_sign(SIGN,3);
	print_end(1);

        print_tab(GAP_NUM);       //8 line
	print_sign(SIGN,3);
	print_sign(' ',1);
	printf("4.修改员工信息");
	print_sign(' ',1);
	print_sign(SIGN,3);
	print_end(1);

        print_tab(GAP_NUM);       //9 line
	print_sign(SIGN,3);
	print_sign(' ',1);
	printf("5.删除员工信息");
	print_sign(' ',1);
	print_sign(SIGN,3);
	print_end(1);

        print_tab(GAP_NUM);       //10 line
	print_sign(SIGN,3);
	print_sign(' ',1);
	printf("6.统计员工信息");
	print_sign(' ',1);
	print_sign(SIGN,3);
	print_end(1);

        print_tab(GAP_NUM);       //11 line
	print_sign(SIGN,3);
	print_sign(' ',1);
	printf("7.修改员工信息");
	print_sign(' ',1);
	print_sign(SIGN,3);
	print_end(1);*/
        
        print_tab(GAP_NUM);       //12 line
	print_sign(SIGN,3);
	print_sign(' ',1);
	printf("8.退出系统");
	print_sign(' ',5);
	print_sign(SIGN,3);
	print_end(1);

        print_tab(GAP_NUM);
        print_sign(SIGN,sign_num);
        print_end(1);

}

/*****************************/

void menu0_2()
{
	unsigned short sign_num = 14;

	system("clear");

	print_end(2);
	print_tab(GAP_NUM);
	print_sign(SIGN,sign_num);
	print_end(1);
	print_tab(GAP_NUM);
	print_sign(SIGN,3);
	printf("用户登录");
	print_sign(SIGN,3);
	print_end(1);
	print_tab(GAP_NUM);
	print_sign(SIGN,sign_num);
	print_end(1);
}

/*****************************
  *****
Function:menu1_x         //函数名称
Description: 通过传入的参数menu_num决定打印的菜单内容。
Input: unsigned short   //传入无符号整数
Output: void
return: void
******************************
*****/

void menu1_x(unsigned short menu_num)
{
	unsigned short sign_num = 14;   //边框字符数
	unsigned short menu_maxnum = 5;   //菜单的数目，此处有5个
	char *p_menu_title[menu_maxnum];   //指向菜单标题的字符指针数组
	p_menu_title[0] = "输入学生信息";
	p_menu_title[1] = "查询学生信息";
	p_menu_title[2] = "删除学生信息";
	p_menu_title[3] = "修改学生信息";
	p_menu_title[menu_maxnum - 1] = "统计学生信息";

	if (menu_num <= 0 || menu_num > menu_maxnum)
	{
		return;
	}

	system("clear");

	print_end(2);
	print_tab(GAP_NUM);
	print_sign(SIGN,sign_num);
	print_end(1);
	print_tab(GAP_NUM);
	print_sign(SIGN,1);
	printf("%s",p_menu_title[menu_num - 1]);
        print_sign(SIGN,1);
        print_end(1);
        print_tab(GAP_NUM);
        print_sign(SIGN,sign_num);
        print_end(1);	
}

void menu1_1()
{
	unsigned short sign_num = 14;

	system("clear");

	print_end(2);
	print_tab(GAP_NUM);
	print_sign(SIGN,sign_num);
	print_end(1);
	print_tab(GAP_NUM);
	print_sign(SIGN,1);
	printf("输入学生信息");
	print_sign(SIGN,1);
	print_end(1);
	print_tab(GAP_NUM);
	print_sign(SIGN,sign_num);
	print_end(1);
}

/*****************************/

void menu1_2()
{
	unsigned short sign_num = 14;

	system("clear");

	print_end(2);
	print_tab(GAP_NUM);
	print_sign(SIGN,sign_num);
	print_end(1);
	print_tab(GAP_NUM);
	print_sign(SIGN,1);
	printf("查询学生信息");
	print_sign(SIGN,1);
	print_end(1);
	print_tab(GAP_NUM);
	print_sign(SIGN,sign_num);
	print_end(1);
}

/*****************************/

void menu1_3()
{
	unsigned short sign_num = 14;

	system("clear");

	print_end(2);
	print_tab(GAP_NUM);
	print_sign(SIGN,sign_num);
	print_end(1);
	print_tab(GAP_NUM);
	print_sign(SIGN,1);
	printf("删除学生信息");
	print_sign(SIGN,1);
	print_end(1);
	print_tab(GAP_NUM);
	print_sign(SIGN,sign_num);
	print_end(1);
}

/*****************************/

void menu1_4()
{
	unsigned short sign_num = 14;

	system("clear");

	print_end(2);
	print_tab(GAP_NUM);
	print_sign(SIGN,sign_num);
	print_end(1);
	print_tab(GAP_NUM);
	print_sign(SIGN,1);
	printf("修改学生信息");
	print_sign(SIGN,1);
	print_end(1);
	print_tab(GAP_NUM);
	print_sign(SIGN,sign_num);
	print_end(1);
}

/*****************************/

void menu1_5()
{
	unsigned short sign_num = 14;

	system("clear");

	print_end(2);
	print_tab(GAP_NUM);
	print_sign(SIGN,sign_num);
	print_end(1);
	print_tab(GAP_NUM);
	print_sign(SIGN,1);
	printf("统计学生信息");
	print_sign(SIGN,1);
	print_end(1);
	print_tab(GAP_NUM);
	print_sign(SIGN,sign_num);
	print_end(1);
}

/*****************************/

void menu_end()
{
	system("clear");

	print_end(2);
	print_tab(GAP_NUM);
	printf("*end!!!");
	print_end(1);
}
