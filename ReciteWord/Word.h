/*
*��ͷ�ļ����������ڼ�¼���ʴ����Ļ������ݽṹWord
*���������ڵ��ʵĲ���
*/

#ifndef WORD_H
#define WORD_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_END_WORD_LEN 50   //Ӣ�ﵥ�ʵ���󳤶�
#define MAX_CH_WORD_LEN 100   //�����������󳤶�

typedef struct
{
	char eng_word[MAX_END_WORD_LEN+1];   //Ӣ�ﵥ��
	char ch_word[MAX_CH_WORD_LEN+1];   //��������
	char *pexm_sentence;   //����
}Word,*pWord;

/*
*��ӡ����
*���ض���ʽ��ӡ����
*/
void printWord(Word w);

/*���뵥��
*���뵥�ʵ�Ӣ�ģ����ģ�������
*/
void changeWord(pWord pw,char *peng_word,char *pch_word,char *pexm_sentence);

/*
*�ͷſռ�
*�ͷ�Ϊexm_sentence����Ŀռ�
*/
void freeWordRoom(pWord pw);

#endif