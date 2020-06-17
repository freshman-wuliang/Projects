#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define INTPUT_FILE "admissData_3.txt"
#define OUTPUT_FILE "admissData_result.txt"
#define MAX_NAME_LEN 20
#define MAX_NUM_LEN 20
#define RECORD_NUM 82
#define LEVEL_NUM 9
#define LEVEL_BASE 330
#define LEVEL_ADD 10

typedef struct
{
	char num[MAX_NUM_LEN+1];
	char name[MAX_NAME_LEN+1];
	int pre_sum;
	double aft_sum;
	double all_sum;
}Record,*PRecord;

int main(void)
{
	Record rc[RECORD_NUM];
	FILE *pif,*pof;
	double re_ave = 0.0;
	double re_var = 0.0;
	double re_low;
	double re_high;
	int level[LEVEL_NUM] = {0,0,0,0,0,0,0,0,0};
	
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
	
	for(int i=1;i<=RECORD_NUM;i++)
	{
		re_ave += rc[i-1].aft_sum;
	}
	re_ave /= RECORD_NUM;
	
	for(int i=1;i<=RECORD_NUM;i++)
	{
		re_var += (rc[i-1].aft_sum - re_ave)*(rc[i-1].aft_sum - re_ave);
	}
	re_var /= RECORD_NUM;
	re_var = sqrt(re_var);
	
	re_low = rc[0].aft_sum;
	re_high = rc[0].aft_sum;
	
	for(int i=1;i<=RECORD_NUM;i++)
	{
		if(rc[i-1].aft_sum > re_high)
		{
			re_high = rc[i-1].aft_sum;
		}
		
		if(rc[i-1].aft_sum < re_low)
		{
			re_low = rc[i-1].aft_sum;
		}
	}
	
	for(int i=1;i<=RECORD_NUM;i++)
	{
		switch (rc[i-1].pre_sum / 10)
		{
			case 33 : level[0]++;break;
			case 34 : level[1]++;break;
			case 35 : level[2]++;break;
			case 36 : level[3]++;break;
			case 37 : level[4]++;break;
			case 38 : level[5]++;break;
			case 39 : level[6]++;break;
			case 40 : level[7]++;break;
			case 41 : level[8]++;break;
		}
	}
	
	pof = fopen(OUTPUT_FILE,"w");
	if(!pof)
	{
		printf("write failed\n");
		exit(1);
	}
	
	int base = LEVEL_BASE;
	fprintf(pof,"num:%d\tre_ave:%.2lf\tre_var:%.2lf\n",RECORD_NUM,re_ave,re_var);
	fprintf(pof,"re_low:%.2lf\tre_high:%.2lf\n",re_low,re_high);
	fprintf(pof,"level:\n");
	for(int i=1;i<=LEVEL_NUM;i++)
	{
		fprintf(pof,"[%d,%d]:\tnum:%d\t",base,base+LEVEL_ADD,level[i-1]);
		fprintf(pof,"percent:%.2lf\n",(double)level[i-1] / (double)RECORD_NUM);
		base += LEVEL_ADD;
	}
	fprintf(pof,"exp_low:%.2lf\texp_high:%.2lf\n",re_ave - re_var,re_ave + re_var);
	
	fclose(pif);
	fclose(pof);
	
	printf("deal finished\n");
	
	return 0;
}