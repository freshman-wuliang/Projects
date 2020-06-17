#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INTPUT_FILE_AD "admissData_3.txt"
#define INTPUT_FILE_RE "retrialData_1.txt"
#define OUTPUT_FILE_AD "admissList.txt"
#define OUTPUT_FILE_WEED "weedList.txt"
#define MAX_NAME_LEN 20
#define MAX_NUM_LEN 20
#define AD_NUM 82
#define RE_NUM 174

typedef struct
{
	char num[MAX_NUM_LEN+1];
	char name[MAX_NAME_LEN+1];
	int pre_sum;
	double aft_sum;
	double all_sum;
}Record_ad,*PRecord_ad;

typedef struct
{
	int order;
	char name[MAX_NAME_LEN+1];
	char num[MAX_NUM_LEN+1];
	int politic;
	int english;
	int math;
	int major;
	int sum;
}Record_re,*PRecord_re;

typedef struct
{
	char name[MAX_NAME_LEN+1];
	char num[MAX_NUM_LEN+1];
	int politic;
	int english;
	int math;
	int major;
	int sum;
	double aft_sum;
	double all_sum;
}Record_all,*PRecord_all;

int findRecord(Record_re re_rc,Record_ad ad_rc[]);

void copyAllRecord(Record_all *prc_all,Record_ad ad_rc,Record_re re_rc);

void copyWeedRecord(Record_re *pweed_list,Record_re re_rc);

int main(void)
{
	Record_ad ad_rc[AD_NUM];
	Record_re re_rc[RE_NUM];
	FILE *pif_ad,*pif_re,*pof_ad,*pof_weed;
	Record_all ad_list[RE_NUM];
	Record_re weed_list[RE_NUM];
	int ad_count = 0;
	int weed_count = 0;
	
	pif_ad = fopen(INTPUT_FILE_AD,"r");
	if(!pif_ad)
	{
		printf("open file1 failded\n");
		exit(1);
	}
	
	pif_re = fopen(INTPUT_FILE_RE,"r");
	if(!pif_re)
	{
		printf("open file2 failded\n");
		exit(1);
	}
	
	for(int i=1;i<=AD_NUM;i++)
	{
		fscanf(pif_ad,"%s",ad_rc[i-1].num);
		fscanf(pif_ad,"%s",ad_rc[i-1].name);
		fscanf(pif_ad,"%d",&ad_rc[i-1].pre_sum);
		fscanf(pif_ad,"%lf",&ad_rc[i-1].aft_sum);
		fscanf(pif_ad,"%lf",&ad_rc[i-1].all_sum);
	}
	
	for(int i=1;i<=RE_NUM;i++)
	{
		fscanf(pif_re,"%d",&re_rc[i-1].order);
		fscanf(pif_re,"%s",re_rc[i-1].name);
		fscanf(pif_re,"%s",re_rc[i-1].num);
		fscanf(pif_re,"%d",&re_rc[i-1].politic);
		fscanf(pif_re,"%d",&re_rc[i-1].english);
		fscanf(pif_re,"%d",&re_rc[i-1].math);
		fscanf(pif_re,"%d",&re_rc[i-1].major);
		fscanf(pif_re,"%d",&re_rc[i-1].sum);
	}
	
	for(int i=1;i<=RE_NUM;i++)
	{
		int tmp;
		
		tmp = findRecord(re_rc[i-1],ad_rc);
		if(tmp == 0)
		{
			copyWeedRecord(&weed_list[weed_count],re_rc[i-1]);
			weed_count++;
		}
		else
		{
			copyAllRecord(&ad_list[ad_count],ad_rc[tmp-1],re_rc[i-1]);
			ad_count++;
		}
	}
	
	pof_ad = fopen(OUTPUT_FILE_AD,"w");
	if(!pof_ad)
	{
		printf("file1 write failed\n");
		exit(1);
	}
	
	pof_weed = fopen(OUTPUT_FILE_WEED,"w");
	if(!pof_weed)
	{
		printf("file2 write failed\n");
		exit(1);
	}
	
	for(int i=1;i<=ad_count;i++)
	{
		fprintf(pof_ad,"%-2d: ",i);
		fprintf(pof_ad,"%-8s %s ",ad_list[i-1].name,ad_list[i-1].num);
		fprintf(pof_ad,"%-3d %-3d %-3d ",ad_list[i-1].politic,ad_list[i-1].english,ad_list[i-1].math);
		fprintf(pof_ad,"%-3d %-3d ",ad_list[i-1].major,ad_list[i-1].sum);
		fprintf(pof_ad,"%.2lf %.2lf\n",ad_list[i-1].aft_sum,ad_list[i-1].all_sum);
	}
	
	for(int i=1;i<=weed_count;i++)
	{
		fprintf(pof_weed,"%-2d : ",i);
		fprintf(pof_weed,"%-8s %s ",weed_list[i-1].name,weed_list[i-1].num);
		fprintf(pof_weed,"%-3d %-3d %-3d ",weed_list[i-1].politic,weed_list[i-1].english,weed_list[i-1].math);
		fprintf(pof_weed,"%-3d %-3d\n",weed_list[i-1].major,weed_list[i-1].sum);
	}
	
	fclose(pif_ad);
	fclose(pif_re);
	fclose(pof_ad);
	fclose(pof_weed);
	
	printf("re_rc:%s\tad_rc:%s\n",re_rc[0].num,ad_rc[0].num);
	printf("%d\n",findRecord(re_rc[0],ad_rc));
	printf("deal finished\n");
	
	return 0;
}

int findRecord(Record_re re_rc,Record_ad ad_rc[])
{
	int flag = 0;
	
	for(int i=1;i<=AD_NUM;i++)
	{
		if(!strcmp(re_rc.num,ad_rc[i-1].num))
		{
			flag = i;
			break;
		}
	}
	
	return flag;
}

void copyAllRecord(Record_all *prc_all,Record_ad ad_rc,Record_re re_rc)
{
	strcpy(prc_all->name,ad_rc.name);
	strcpy(prc_all->num,ad_rc.num);
	prc_all->aft_sum = ad_rc.aft_sum;
	prc_all->all_sum = ad_rc.all_sum;
	prc_all->politic = re_rc.politic;
	prc_all->english = re_rc.english;
	prc_all->math = re_rc.math;
	prc_all->major = re_rc.major;
	prc_all->sum = re_rc.sum;
}

void copyWeedRecord(Record_re *pweed_list,Record_re re_rc)
{
	pweed_list->order = re_rc.order;
	strcpy(pweed_list->name,re_rc.name);
	strcpy(pweed_list->num,re_rc.num);
	pweed_list->politic = re_rc.politic;
	pweed_list->english = re_rc.english;
	pweed_list->math = re_rc.math;
	pweed_list->major = re_rc.major;
	pweed_list->sum = re_rc.sum;
	
}