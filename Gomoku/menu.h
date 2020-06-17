#ifndef MENU_H
#define MENU_H

#include<stdio.h>
#include<stdlib.h>

#define ROW 10   //棋盘行数
#define COL 10   //棋盘列数
#define BLACK '*'   //黑棋子字符表示
#define WHITE 'o'   //白棋子表示
#define ZERO '\0'   //空白状态字符
#define GMNAME "wuziqi"   //游戏名称

char g_board[ROW][COL];   //全局变量存储棋盘状态 

void PrintChar(char ch,int n);   //打印n个ch字符

void ScreenClear(void);   //清空屏幕

void InitBoard(char board[ROW][COL],int row,int col);   //初始化棋盘数组

void DisplayBoard(char board[ROW][COL],int row,int col);   //打印棋盘

void PrintTitle(char *gmname);   //打印游戏名称

#endif
