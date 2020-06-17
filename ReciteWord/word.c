#include"Word.h"

//��ӡ����
void printWord(Word w)
{
	printf("%s\t",w.eng_word);
	printf("%s\n\n",w.ch_word);
	printf("����:%s\n",w.pexm_sentence);
}


//�ı䵥��
void changeWord(pWord pw,char *peng_word,char *pch_word,char *pexm_sentence)
{
	strcpy(pw->eng_word,peng_word);
	strcpy(pw->ch_word,pch_word);
	pw->pexm_sentence = pexm_sentence;
}

//�ͷſռ�
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