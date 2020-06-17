/*****************************
************  
File name: menu.h
Description: 用于输出界面
Author: Wiliang
version: 0.0
Date : 2018年6月14日
History: 
******************************
***********/

#ifndef MENU_H_
#define MENU_H_

#include<stdlib.h>
#include<stdio.h>

#define GAP_NUM 16
#define SIGN '*'


/*****************************
 ***
Function: print_sign        //函数名称
Description: 打印特定字符   //描述
Calls:                      //调用什么函数
Called By:                  //被什么函数调用
Input: 1.char ,2.unsigned short  //输入参数
Output: Nothing                     //输出参数
Return: void                     //返回值
******************************
**/

void print_sign(char sign,int num);

/*****************************
 ***
Function: print_tab        //函数名称
Description: 制表          //描述
Calls:                      //调用什么函数
Called By:                  //被什么函数调用
Input: unsigned short //输入参数
Output: Nothing                     //输出参数
Return: void                     //返回值
******************************
**/

void print_tab(int num);

/*****************************
 ***
Function: print_end        //函数名称
Description: 换行          //描述
Calls:                      //调用什么函数
Called By:                  //被什么函数调用
Input: unsigned short //输入参数
Output: Nothing                     //输出参数
Return: void                     //返回值
******************************
**/

void print_end(int num);

/*****************************
 ***
Function: print_sign        //函数名称
Description: 打印特定字符   //描述
Calls:                      //调用什么函数
Called By:                  //被什么函数调用
Input: 1.char ,2.unsigned short  //输入参数
Output: Nothing                     //输出参数
Return: void                     //返回值
******************************
**/

void menu0_0();

/*****************************
 ***
Function: print_tab        //函数名称
Description: 制表          //描述
Calls:                      //调用什么函数
Called By:                  //被什么函数调用
Input: unsigned short //输入参数
Output: Nothing                     //输出参数
Return: void                     //返回值
******************************
**/

void menu0_1();

/*****************************
 ***
Function: print_end        //函数名称
Description: 换行          //描述
Calls:                      //调用什么函数
Called By:                  //被什么函数调用
Input: unsigned short //输入参数
Output: Nothing                     //输出参数
Return: void                     //返回值
******************************
**/

void menu0_2();

void menu1_x(unsigned short menu_num);
void menu1_1();

void menu1_2();

void menu1_3();

void menu1_4();

void menu1_5();

void menu_end();


#endif

