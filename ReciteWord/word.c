#include"Word.h"

//打印单词
void printWord(Word w)
{
	printf("%s\t",w.eng_word);
	printf("%s\n\n",w.ch_word);
	printf("例句:%s\n",w.pexm_sentence);
}


//改变单词
void changeWord(pWord pw,char *peng_word,char *pch_word,char *pexm_sentence)
{
	strcpy(pw->eng_word,peng_word);
	strcpy(pw->ch_word,pch_word);
	pw->pexm_sentence = pexm_sentence;
}

//释放空间
void freeWordRoom(pWord pw)
{
	if(pw->pexm_sentence == NULL)
		return;
	else
	{
		free(pw->pexm_sentence);
		pw->pexm_sentence = NULL;
	}
}