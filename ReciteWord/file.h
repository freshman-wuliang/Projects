/*
*该头文件主要是用来对各种程序文件进行操作
*/

#ifndef FILE_H
#define FILE_H

#define DATE_FILE_NAME "word.dat"   //数据文件名

/*
*写入单词
*将单词写入到date文件中
*/
void writeWord(Word w,FILE * pf);

#endif