/*
*该头文件定义了用于记录单词词条的基本数据结构Word
*和其它对于单词的操作
*/

#ifndef WORD_H
#define WORD_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_END_WORD_LEN 50   //英语单词的最大长度
#define MAX_CH_WORD_LEN 100   //中文释义的最大长度

typedef struct
{
	char eng_word[MAX_END_WORD_LEN+1];   //英语单词
	char ch_word[MAX_CH_WORD_LEN+1];   //中文释义
	char *pexm_sentence;   //例句
}Word,*pWord;

/*
*打印单词
*按特定格式打印单词
*/
void printWord(Word w);

/*输入单词
*输入单词的英文，中文，和例句
*/
void changeWord(pWord pw,char *peng_word,char *pch_word,char *pexm_sentence);

/*
*释放空间
*释放为exm_sentence分配的空间
*/
void freeWordRoom(pWord pw);

#endif