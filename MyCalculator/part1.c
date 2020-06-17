#include"part1.h"

#define JINDU 0.0000000001

/******************
 *
 *
 *****************/

void part1()
{
	int option;
	int flag = 1;
	char c;

	while (flag)
	{
		menu1_1();

		scanf("%d",&option);
		while (((c = getchar()) != '\n') && (c !=EOF)) ;

		switch (option)
		{
			case 1 : ADD(); break;
			case 2 : MINUS(); break;
			case 3 : MUTIPLY(); break;
			case 4 : DIVIDE(); break;
			case 5 : MI(); break;
			case 6 : FANGGEN(); break;
			case 7 : DUISHU(); break;
			case 8 : flag = 0; break;
			default : printf("\t\t输入不合法\n");pasue();
		}
	}
}

/******************
 *
 *
 *****************/

void ADD()
{
	float a, b;

	printf("\t\t输入两个数用空格分开\n");
	printf("\t\t回车确认输入\n\t\t:");

	scanf("%f%f",&a,&b);
	printf("\t\t%f + %f = %f\n\n",a,b,a+b);
	pasue();
}

/******************
 *
 *
 *****************/

void MINUS()
{
	float a, b;

	printf("\t\t输入两个数用空格分开\n");
	printf("\t\t回车确认输入\n\t\t:");

	scanf("%f%f",&a,&b);
	printf("\t\t%f - %f = %f\n",a,b,a-b);
	pasue();
}

/******************
 *
 *
 *****************/

void MUTIPLY()
{
	double a, b;

	printf("\t\t输入两个数用空格分开\n");
	printf("\t\t回车确认输入\n\t\t:");

	scanf("%lf%lf",&a,&b);
	printf("\t\t%lf * %lf = %lf\n\n",a,b,a*b);
	pasue();
}

/******************
 *
 *
 *****************/

void DIVIDE()
{
	double a, b;

	printf("\t\t输入两个数用空格分开\n");
	printf("\t\t回车确认输入\n\t\t:");

	scanf("%lf%lf",&a,&b);

	if ((b-0.0) <= JINDU)
	{
		printf("除数为0!\n");
		pasue();
		return ;
	}

	printf("\t\t%lf / %lf = %lf\n\n",a,b,a/b);
	pasue();
}

/******************
 *
 *
 *****************/

void MI()
{
	int option;
	char c;
	double a, b;

	printf("\t\t请选择\n");
	printf("\t\t1.自然指数e为底的幂\n");
	printf("\t\t2.任意指数为底的幂\n\t\t:");

	scanf("%d",&option);
	while ((c = getchar()) != '\n' && c != EOF) ;

	if (option == 1)
	{
		printf("\t\t请输入一个数\n");
		printf("\t\t回车完成输入\n\t\t:");
		scanf("%lf",&a);
		printf("\t\te^%lf = %lf\n\n",a,exp(a));
	}
	else if (option == 2)
	{
		printf("\t\t请输入两个数空格隔开\n");
		printf("\t\t回车完成输入\n\t\t:");
		scanf("%lf%lf",&a,&b);
		printf("\t\t%lf^%lf = %lf\n\n",a,b,pow(a,b));
	}
	else
	{
		printf("输入不合法\n");
		pasue();
		return ;
	}
	pasue();
}

/******************
 *
 *
 *****************/

void FANGGEN()
{
	int option;
	double a, b;

	printf("\t\t请选择:\n");
	printf("\t\t1.平方根\n");
	printf("\t\t2.其它次方根\n\t\t:");

	scanf("%d",&option);

	if (option == 1)
	{
		printf("\t\t请输入一个数\n");
		printf("\t\t回车确认输入\n\t\t:");
		scanf("%lf",&a);
		printf("\t\t%lf的平方根为:%lf\n",a,sqrt(a));
	}
	else if (option == 2)
	{
		printf("等待开发\n");
		pasue();
		return;
	}
	else
	{
		printf("输入不合法\n");
		pasue();
		return ;
	}
	pasue();
}

/******************
 *
 *
 *****************/

void DUISHU()
{
	int option;
	double a, b;

	printf("\t\t请选择:\n");
	printf("\t\t1.以e为底的对数\n");
	printf("\t\t2.以任意数为底的对数\n\t\t:");

	scanf("%d",&option);

	if (option == 1)
	{
		printf("\t\t请输入一个数\n");
		printf("\t\t回车键确认输入\n\t\t:");
		scanf("%lf",&a);
		if ((a - 0.0) <= JINDU)
		{
			printf("error\n");
			pasue();
			return ;
		}
		else
			printf("\t\tln%lf = %lf\n",a,log(a));		
	}
	else if (option == 2)
	{
		printf("\t\t请输入两个数并用空格隔开\n");
		printf("\t\t按回车键完成输入\n\t\t:");
		scanf("%lf%lf",&a,&b);
		if (((a-0.0) <=JINDU) || a == 1 || ((b-0.0) <= JINDU))
		{
			printf("error\n");
			pasue();
			return;
		}
		else
			printf("\t\tlog(%lf)%lf = %lf\n",a,b,log10(a)/log10(b));
	}
	else 
	{
		printf("输入不合法\n");
	}
	pasue();
}


