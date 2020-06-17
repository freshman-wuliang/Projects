#include"menu.h"

/******************
 *
 *
 *
 *
 *
 *****************/

void menu0()//一级菜单
{
	system("clear");
        printf("\n\n");
	printf("\t\t***********************\n");
	printf("\t\t***     *计算器*    ***\n");
	printf("\t\t***********************\n");
	printf("\t\t**      请选择1-6    **\n");
	printf("\t\t*** 1.简单运算       **\n");
        printf("\t\t*** 2.    运算       **\n");
        printf("\t\t*** 3.    运算       **\n");
        printf("\t\t*** 4.三角运算       **\n");
	printf("\t\t*** 5.其他           **\n");
	printf("\t\t*** 6.退出           **\n");
        printf("\t\t***********************\n"); 
        printf("\n\t\t* 你的选择是：");
	return;
}

/******************
 *
 *
 *
 *
 *
 *****************/

void menu1_1()//一级菜单1
{
	system("clear");
	printf("\n\n");
	printf("\t\t**********************\n");
	printf("\t\t***   请选择 1-8 *****\n");
	printf("\t\t***   1.加法运算   ***\n");
	printf("\t\t***   2.减法运算   ***\n");
	printf("\t\t***   3.乘法运算   ***\n");
	printf("\t\t***   4.除法运算   ***\n");
	printf("\t\t***   5.幂与指数运算**\n");
	printf("\t\t***   6.求方根运算  **\n");
	printf("\t\t***   7.对数运算   ***\n");
	printf("\t\t***   8.返回     *****\n");
	printf("\n\t\t* 你的选择是: ");
}

/******************
 *
 *
 *
 *
 *
 *****************/

void menu1_2()//一级菜单2
{
	system("clear");
	printf("\n\n");
	printf("\t\t**********************\n");
	printf("\t\t***  请选择 1-6 ******\n");
	printf("\t\t***  1.     运算   ***\n");
	printf("\t\t***  2.     运算   ***\n");
	printf("\t\t***  3.     运算   ***\n");
	printf("\t\t***  4.     运算   ***\n");
	printf("\t\t***  5.     运算   ***\n");
	printf("\t\t***  6.返回      *****\n");
	printf("\n\t\t* 你的选择是: ");
}

/******************
 *
 *
 *
 *
 *
 *****************/

void menu1_3()//一级菜单3
{
	system("clear");
	printf("\n\n");
	printf("\t\t**********************\n");
	printf("\t\t*** 请选择 1-6 *******\n");
	printf("\t\t*** 1.     运算    ***\n");
	printf("\t\t*** 2.     运算    ***\n");
	printf("\t\t*** 3.     运算    ***\n");
	printf("\t\t*** 4.     运算    ***\n");
	printf("\t\t*** 5.     运算    ***\n");
	printf("\t\t*** 6.返回       *****\n");
	printf("\n\t\t你的选择是: ");
}

/******************
 *
 *
 *
 *
 *
 *****************/

void menu1_4()//一级菜单4
{
	system("clear");
	printf("\n\n");
	printf("\t\t**********************\n");
	printf("\t\t*** 请选择 1-8 *******\n");
	printf("\t\t*** 1.正弦运算     ***\n");
	printf("\t\t*** 2.余弦运算     ***\n");
	printf("\t\t*** 3.正切运算     ***\n");
	printf("\t\t*** 4.反正弦运算   ***\n");
	printf("\t\t*** 5.反余弦运算   ***\n");
	printf("\t\t*** 6.反正切运算   ***\n");
	printf("\t\t*** 7.弧度角度运算 ***\n");
	printf("\t\t*** 8.返回       *****\n");
	printf("\n\t\t你的选择是: ");
}

/******************
 *
 *
 *
 *
 *
 *****************/

void menu1_5()//一级菜单5
{
	system("clear");
	printf("\n\n");
	printf("\t\t**********************\n");
	printf("\t\t*** 请选择 1-6 *******\n");
	printf("\t\t*** 1.   问题      ***\n");
	printf("\t\t*** 2.             ***\n");
	printf("\t\t*** 3.             ***\n");
	printf("\t\t*** 4.             ***\n");
	printf("\t\t*** 5.             ***\n");
	printf("\t\t*** 6.返回       *****\n");
	printf("\n\t\t你的选择是: ");
}

/******************
 *
 *
 *
 *
 *
 *****************/

void pasue()
{
	char a, b;

	printf("按任意键继续\n\t\t:");
	scanf("%c",&a);
	while ((b = getchar()) != '\n' && b != EOF) ;
}
