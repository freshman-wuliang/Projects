#include"part4.h"

#define PI 3.1415926

/******************
 *
 *
 *****************/

void part4()
{
	int option;
	int flag;
	char c;

	while (flag)
	{
		menu1_4();

		scanf("%d",&option);
		while (((c = getchar()) != '\n') && (c != EOF)) ;


		switch (option)
		{
			case 1 : ZHENGXIAN(); break;
			case 2 : YUXIAN(); break;
			case 3 : ZHENGQIE(); break;
			case 4 : FZHENGXIAN(); break;
			case 5 : FYUXIAN(); break;
			case 6 : FZHENGQIE(); break;
			case 7 : AandR(); break;
			case 8 : flag = 0; break;
			default : printf("\t\t输入不合法\n");pasue();
		}
	}
}

/******************
 *
 *
 *****************/

void ZHENGXIAN()
{
	double a;

	printf("\t\t请输入一个角度\n");
	printf("\t\t回车键确认输入\n\t\t:");
	scanf("%lf",&a);
	printf("\t\tsin(%lf) = %.3lf\n\n",a,sin(AtoR(a)));
	pasue();
}

/******************
 *
 *
 *****************/

void YUXIAN()
{
	double a;

	printf("\t\t请输入一个角度\n");
	printf("\t\t回车键确认输入\n\t\t:");
	scanf("%lf",&a);
	printf("\t\tcos(%lf) = %.3lf\n\n",a,cos(AtoR(a)));
	pasue();
}

/******************
 *
 *
 *****************/

void ZHENGQIE()
{
	double a;

	printf("\t\t请输入一个角度\n");
	printf("\t\t回车确认输入\n\t\t:");
	scanf("%lf",&a);
	printf("\t\ttan(%lf) = %.3lf\n\n",a,tan(AtoR(a)));
	pasue();
}

/******************
 *
 *
 *****************/

void FZHENGXIAN()
{
	double a;

	printf("\t\t请输入一个弧度\n");
	printf("\t\t回车键确认输入\n\t\t:");
	scanf("%lf",&a);
	printf("\t\tarcsin(%lf) = %.3lf\n\n",a,RtoA(asin(a)));
	pasue();
}

/******************
 *
 *
 *****************/

void FYUXIAN()
{
	double a;

	printf("\t\t请输入一个弧度\n");
	printf("\t\t回车键确认输入\n\t\t:");
	scanf("%lf",&a);
	printf("\t\tarccos(%lf) = %.3lf\n\n",a,RtoA(acos(a)));
	pasue();
}

/******************
 *
 *
 *****************/

void FZHENGQIE()
{
	double a;

	printf("\t\t请输入一个弧度\n");
	printf("\t\t回车键确认输入\n\t\t:");
	scanf("%lf",&a);
	printf("\t\tarctan(%lf) = %.3lf\n\n",a,RtoA(atan(a)));
	pasue();
}

/******************
 *
 *
 *****************/

void AandR()
{
	int option;
	double a;

	printf("\t\t请选择:\n");
	printf("\t\t1.角化弧度\n");
	printf("\t\t2.弧度化角\n\t\t:");
	scanf("%d",&option);
	if (option == 1)
	{
		printf("\t\t请输入角度:\n");
		printf("\t\t回车键完成输入\n\t\t:");
		scanf("%lf",&a);
		printf("\t\t%lf du = %.3lf rad.\n\n",a,AtoR(a));
	}
	else if (option == 2)
	{
		printf("\t\t请输入弧度\n");
		printf("\t\t回车键完成输入\n\t\t:");
		scanf("%lf",&a);
		printf("\t\t%lf rad = %.3lf du\n\n",a,RtoA(a));
	}
	else
	{
		printf("输入不合法\n");
		pasue();
	}
	pasue();
}

/******************
 *
 *
 *****************/

double AtoR(double A)
{
	double y;

	y = (A/180.0)*PI;
	return y;
}

/******************
 *
 *
 *****************/

double RtoA(double R)
{
	double y;

	y = R*180.0/PI;
	return y;
}

