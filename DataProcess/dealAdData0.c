#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INTPUT_FILE "admissData_0.txt"
#define OUTPUT_FILE "admissData_1.txt"
#define MAX_NAME_LEN 20
#define MAX_NUM_LEN 20
#define MAX_TMP_LEN 50
#define RECORD_NUM 124

typedef struct
{
	char num[MAX_NUM_LEN+1];
	char tmp1[MAX_TMP_LEN+1];
	char tmp2[MAX_TMP_LEN+1];
	char tmp3[MAX_TMP_LEN+1];
	char tmp4[MAX_TMP_LEN+1];
	double aft_sum;
	double all_sum;
	char tmp5[MAX_TMP_LEN+1];
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
		fscanf(pif,"%s",rc[i-1].tmp1);
		fscanf(pif,"%s",rc[i-1].tmp2);
		fscanf(pif,"%s",rc[i-1].tmp3);
		fscanf(pif,"%s",rc[i-1].tmp4);
		fscanf(pif,"%lf",&rc[i-1].aft_sum);
		fscanf(pif,"%lf",&rc[i-1].all_sum);
		fscanf(pif,"%s",rc[i-1].tmp5);
	}
	
	/*for(int i=1;i<=3;i++)
	{
		printf("%s %s %s\n",rc[i-1].num,rc[i-1].tmp1,rc[i-1].tmp2);
		printf("%s %s\n",rc[i-1].tmp3,rc[i-1].tmp4);
		printf("%.2lf %.2lf\n",rc[i-1].pre_sum,rc[i-1].aft_sum);
		printf("%.2lf %s\n",rc[i-1].all_sum,rc[i-1].tmp5);
	}*/
	
	//sort(rc,RECORD_NUM);
	
	pof = fopen(OUTPUT_FILE,"w");
	if(!pof)
	{
		printf("write failed\n");
		exit(1);
	}
	
	for(int i=1;i<=RECORD_NUM;i++)
	{
		fprintf(pof,"%d ",i);
		fprintf(pof,"%s %s ",rc[i-1].num,rc[i-1].tmp1);
		fprintf(pof,"%s ",rc[i-1].tmp4);
		fprintf(pof,"%.2lf %.2lf\n",rc[i-1].aft_sum,rc[i-1].all_sum);
	}
	
	fclose(pif);
	fclose(pof);
	
	printf("deal finished\n");
	
	return 0;
}

/*void sort(Record rc[],int n)
{
	Record tmp;
	
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			if(rc[j-1].sum < rc[j].sum)
			{
				swap(&rc[j-1],&rc[j]);
			}
		}
	}
}*/

/*void swap(Record *pa,Record *pb)
{
	Record tmp;
	
	strcpy(tmp.name,pa->name);
	strcpy(tmp.num,pa->num);
	strcpy(tmp.tmp1,pa->tmp1);
	tmp.politic = pa->politic;
	tmp.english = pa->english;
	tmp.math = pa->math;
	tmp.major = pa->major;
	tmp.sum = pa->sum;
	strcpy(tmp.tmp2,pa->tmp2);
	strcpy(tmp.tmp3,pa->tmp3);
	
	strcpy(pa->name,pb->name);
	strcpy(pa->num,pb->num);
	strcpy(pa->tmp1,pb->tmp1);
	pa->politic = pb->politic;
	pa->english = pb->english;
	pa->math = pb->math;
	pa->major = pb->major;
	pa->sum = pb->sum;
	strcpy(pa->tmp2,pb->tmp2);
	strcpy(pa->tmp3,pb->tmp3);
	
	strcpy(pb->name,tmp.name);
	strcpy(pb->num,tmp.num);
	strcpy(pb->tmp1,tmp.tmp1);
	pb->politic = tmp.politic;
	pb->english = tmp.english;
	pb->math = tmp.math;
	pb->major = tmp.major;
	pb->sum = tmp.sum;
	strcpy(pb->tmp2,tmp.tmp2);
	strcpy(pb->tmp3,tmp.tmp3);
}*/