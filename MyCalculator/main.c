#include<stdio.h>
#include"menu.h"
#include"part1.h"
#include"part2.h"
#include"part3.h"
#include"part4.h"
#include"part5.h"
#include<stdlib.h>

int main()
{
	int option;
	int flag=1;
	char c;
	
	while (flag)
	{
		menu0();

		scanf("%d",&option);
		while (((c = getchar()) != '\n') && (c != EOF));//清除输入缓冲区

		switch (option)
		{
			case 1 : part1(); break;
			case 2 : part2(); break;
			case 3 : part3(); break;
			case 4 : part4(); break;
			case 5 : part5(); break;
			case 6 : flag = 0; break;
			default : printf("\t\t输入不合法\n");pasue();
		}
	}

	printf("end!!!\n");
	return 0;
}
