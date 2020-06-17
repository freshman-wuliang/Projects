#include<stdio.h>
#include"menu.h"
#include"data.h"

int main(void)
{
	int flag = 1;

	/*InitBoard(g_board,ROW,COL);
	while(flag)
	{		
		DisplayBoard(g_board,ROW,COL);
	}*/

	for(int i=0;i<5;i++)
		printf("%d ",FlipCoin());
	putchar('\n');

	return 0;
}
