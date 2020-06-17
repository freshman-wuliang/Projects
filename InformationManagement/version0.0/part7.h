#ifndef _PART7_H_
#define _PART7_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<conio.h>
#include"config.h"
#include"menu.h"
#include"data_operation.h"

/*******************
 *
 *
 *******************/
 
int checkfirst();   //检查是否第一次登录系统

/********************
 *
 *
 *******************/
void setsystem();  //设置系统函数

/*******************
 *
 *
 ******************/

int initsystem(system_config *SYSTEM_CONFIG);   //系统初始化函数

/*******************
 *
 *
 ******************/
 
void loginsystem();   //登录系统函数

/*******************
 *
 *
 ******************/

void recoverysystem();  //恢复系统

/*******************
 *
 *
 ******************/

void ChangePassword();   //修改系统密码

#endif
