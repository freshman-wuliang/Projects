#ifndef DATA_H
#define DATA_H

#include<stdlib.h>
#include<time.h>

#define COIN_HEAD 1
#define COIN_TAIL 0

int g_first;   //记录先手的变量，1代表白方，2代表黑方

int FlipCoin(void);   //掷硬币函数

#endif
