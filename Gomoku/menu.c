#include"menu.h"

void PrintChar(char ch,int n)
{
	for(int i=1;i<=n;i++)
	{
		printf("%c",ch);
	}
}

void ScreenClear(void)
{
	system("clear");
}

void InitBoard(char board[ROW][COL],int row,int col)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			board[i][j] = ZERO;
		}
	}
}

void DisplayBoard(char board[ROW][COL],int row,int col)
{
	int i,j;

	ScreenClear();
	PrintTitle(GMNAME);

	PrintChar('\t',2);
	PrintChar(' ',2);
	for(i=1;i<=col;i++)
	{
		printf(" %2d",i);
	}
	putchar('\n');

	for(i=0;i<row;i++)
	{
		PrintChar('\t',2);
		for(j=0;j<col;j++)
		{
			printf("———");
		}   //画上框线
		printf("———");
		putchar('\n');

		PrintChar('\t',2);
		printf("%2d",i+1);
		for(j=0;j<col;j++)
		{
			if(board[i][j] == BLACK)
			{
				printf("| %c",BLACK);
			}
			else if(board[i][j] == WHITE)
			{
				printf("| %c",WHITE);
			}
			else
			{
				printf("|  ");
			}
		}
		printf("|\n");
	}

	PrintChar('\t',2);
	for(i=0;i<col;i++)
	{
		printf("———");
	}
	printf("———");
	putchar('\n');
}

void PrintTitle(char *gmname)
{
	PrintChar('\t',2);
	PrintChar(' ',COL*3/2);
	printf("%s",gmname);
	putchar('\n');
}
