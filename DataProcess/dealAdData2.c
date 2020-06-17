#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define INTPUT_FILE "admissData_2.txt"
#define OUTPUT_FILE "admissData_3.txt"
#define MAX_NAME_LEN 20
#define MAX_NUM_LEN 20
#define RECORD_NUM 82

typedef struct
{
	char num[MAX_NUM_LEN+1];
	char name[MAX_NAME_LEN+1];
	int pre_sum;
	double aft_sum;
	double all_sum;
}Record,*PRecord;

void sort(Record rc[],int n);

void swap(Record *pa,Record *pb);

int main(void)
{
	Record rc[RECORD_NUM];
	FILE *pif,*pof;
	
	pif = fopen(INTPUT_FILE,"r");
	if(!pif)
	{
		printf("open failded\n");
		exit(1);
	}
	
	for(int i=1;i<=RECORD_NUM;i++)
	{
		fscanf(pif,"%s",rc[i-1].num);
		fscanf(pif,"%s",rc[i-1].name);
		fscanf(pif,"%d",&rc[i-1].pre_sum);
		fscanf(pif,"%lf",&rc[i-1].aft_sum);
		fscanf(pif,"%lf",&rc[i-1].all_sum);
	}
	
	sort(rc,RECORD_NUM);
	
	pof = fopen(OUTPUT_FILE,"w");
	if(!pof)
	{
		printf("write failed\n");
		exit(1);
	}
	
	for(int i=1;i<=RECORD_NUM;i++)
	{
		fprintf(pof,"%s ",rc[i-1].num);
		fprintf(pof,"%s ",rc[i-1].name);
		fprintf(pof,"%d ",rc[i-1].pre_sum);
		fprintf(pof,"%.2lf %.2lf\n",rc[i-1].aft_sum,rc[i-1].all_sum);
	}
	
	fclose(pif);
	fclose(pof);
	
	printf("deal finished\n");
	
	return 0;
}

void sort(Record rc[],int n)
{
	Record tmp;
	
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			if(rc[j-1].pre_sum < rc[j].pre_sum)
			{
				swap(&rc[j-1],&rc[j]);
			}
		}
	}
}

void swap(Record *pa,Record *pb)
{
	Record tmp;
	
	strcpy(tmp.num,pa->num);
	strcpy(tmp.name,pa->name);
	tmp.pre_sum = pa->pre_sum;
	tmp.aft_sum = pa->aft_sum;
	tmp.all_sum = pa->all_sum;
	
	strcpy(pa->num,pb->num);
	strcpy(pa->name,pb->name);
	pa->pre_sum = pb->pre_sum;
	pa->aft_sum = pb->aft_sum;
	pa->all_sum = pb->all_sum;
	
	strcpy(pb->num,tmp.num);
	strcpy(pb->name,tmp.name);
	pb->pre_sum = tmp.pre_sum;
	pb->aft_sum = tmp.aft_sum;
	pb->all_sum = tmp.all_sum;
}