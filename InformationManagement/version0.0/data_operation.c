#include"data_operation.h"

static void FindStudent_name();
static void FindStudent_num();
static void FindStudent_rank();
static int FloatCmp(float a,float b,float jindu);
//static int Modify_int(char *ch,int old);
//static char *Modify_string(char *ch,char *pold,int size);

/*******************
 *函数名称:loaddata()
 *函数功能:由数据文件创建链表
 *入口参数:无
 *出口参数:int
 *说明:1表示成功,0无数据
 ******************/

int loaddata()
{
  FILE *fp;
  pListNode p;
  int i;
  
  if(SYSTEM_CONFIG.STUDENT_COUNT == 0)
    return 0;
  else
  {
    fp = fopen("student_information.dat","rb");
    if(!fp)
      return 0;
    for(i=1;i<=SYSTEM_CONFIG.STUDENT_COUNT;i++)
    {
      p = (pListNode)malloc(sizeof(ListNode));
      if(!p)
        return 0;
      
      fread(p,sizeof(ListNode),1,fp);
      
      LINKLIST_END->next->next = p;
      p->next = LINKLIST_END;
      LINKLIST_END->next = p;
    }
    fclose(fp);
    
    return 1;
  }
}

/*******************
 *函数名称:AddRecord()
 *函数功能:增加学生记录
 *入口参数:无
 *出口参数:无
 *说明:无
 ******************/

void AddRecord()
{
  int flag = 1;
  char option;
  char buff;
  pListNode p;
  float average;
  
  while(flag)
  {
    system("clear");
   
    printf("\n\n\t\t*当前有%d名学生!\n",SYSTEM_CONFIG.STUDENT_COUNT);
    printf("\t\t*是否增加学生信息?(y/n)\n");
    printf("\t\t:");
    scanf("%c",&option);
    while((buff = getchar()) != '\n' && buff != EOF);
    
    if(option == 'y')
    {
      menu1_1();
      
      p = (pListNode)malloc(sizeof(ListNode));
      if(!p)
        exit(-1);
      printf("\n\t\t*输入第%d个学生的信息*\n",SYSTEM_CONFIG.STUDENT_COUNT+1);
      
      printf("\t\t*姓名:");
      scanf("%s",p->STUDENT_INFORMATION.student_name);
      
      printf("\t\t*性别:");
      scanf("%s",p->STUDENT_INFORMATION.student_sex);
      
      printf("\t\t*年龄:");
      scanf("%d",&(p->STUDENT_INFORMATION.student_age));
      while((buff = getchar()) != '\n' && buff != EOF);
      
      printf("\t\t*手机号:");
      scanf("%s",p->STUDENT_INFORMATION.student_num);
      
      printf("\t\t*语文成绩:");
      scanf("%f",&(p->STUDENT_INFORMATION.student_chinese_grade));
      while((buff = getchar()) != '\n' && buff != EOF);
      
      printf("\t\t*数学成绩:");
      scanf("%f",&(p->STUDENT_INFORMATION.student_math_grade));
      while((buff = getchar()) != '\n' && buff != EOF);
      
      printf("\t\t*英语成绩:");
      scanf("%f",&(p->STUDENT_INFORMATION.student_english_grade));
      while((buff = getchar()) != '\n' && buff != EOF);
      
      average = (p->STUDENT_INFORMATION.student_chinese_grade +
                 p->STUDENT_INFORMATION.student_math_grade +
                 p->STUDENT_INFORMATION.student_english_grade) / 3.0;
      p->STUDENT_INFORMATION.student_average_grade = average;
      
      p->STUDENT_INFORMATION.student_grade_rank = SYSTEM_CONFIG.STUDENT_COUNT + 1;
      
      LINKLIST_END->next->next = p;
      p->next = LINKLIST_END;
      LINKLIST_END->next = p;
      SYSTEM_CONFIG.STUDENT_COUNT ++;
    }
    else if(option == 'n')
      flag = 0;
    else
    {
      printf("\t\t*输入不合法!\n");
      pasue();
      AddRecord();
    }
  }
}

/*******************
 *函数名称:DisplayInformation()
 *函数功能:显示学生信息
 *入口参数:无
 *出口参数:无
 *说明:无
 ******************/

void DisplayInformation()
{
  int i;
  pListNode p;
  
  system("clear");
  
  if(SYSTEM_CONFIG.STUDENT_COUNT == 0)
    printf("\n\n\t\t*EMPTY!\n");
  else
  {
    printf("\t\t*学生信息列表*\n");
    printf("\n");
    printf("\t____________________________\n");
   
    p = LINKLIST_HEAD;
    
    for(i=1;i<=SYSTEM_CONFIG.STUDENT_COUNT;i++)
    {
      p = p->next;
      
      printf("\t\t*** 第%d个 ***\n",i);
      printf("\t\t*姓名:%s\n",p->STUDENT_INFORMATION.student_name);
      printf("\t\t*性别:%s\n",p->STUDENT_INFORMATION.student_sex);
      printf("\t\t*年龄:%d\n",p->STUDENT_INFORMATION.student_age);
      printf("\t\t*手机号:%s\n",p->STUDENT_INFORMATION.student_num);
      printf("\t\t*语文成绩:%.2f\n",p->STUDENT_INFORMATION.student_chinese_grade);
      printf("\t\t*数学成绩:%.2f\n",p->STUDENT_INFORMATION.student_math_grade);
      printf("\t\t*英语成绩:%.2f\n",p->STUDENT_INFORMATION.student_english_grade);
      printf("\t\t*平均成绩:%.2f\n",p->STUDENT_INFORMATION.student_average_grade);
      printf("\t_____________________________\n");
    }
  }
  pasue();
}

/*******************
 *函数名称:FindStudent()
 *函数功能:查找指定特点的学生
 *入口参数:无
 *出口参数:无
 *说明:无
 *******************/
void FindStudent()
{
  int flag = 1;
  int option;
  char buff;
  
  if(SYSTEM_CONFIG.STUDENT_COUNT == 0)
  {
    system("clear");
    printf("\n\n\t\t*无学生记录无法查询!\n");
    return ;
  }
  
  while(flag)
  {
    menu1_2();
    
    printf("\t\t*1.按姓名查询.\n");
    printf("\t\t*2.按电话查询.\n");
    printf("\t\t*3.按排名查询.\n");
    printf("\t\t*4.返回.\n");
    
    printf("\t\t*请选择:");
    scanf("%d",&option);
    while((buff = getchar()) != '\n' && buff != EOF);
    
    switch(option)
    {
      case 1 : FindStudent_name();break;
      case 2 : FindStudent_num();break;
      case 3 : FindStudent_rank();break;
      case 4 : flag = 0;break;
      default : printf("\t\t*输入不合法\n");
                pasue();
    }
  }
}

/*******************
 *函数名称:FindStudent_name()
 *函数功能:按姓名查找学生
 *入口参数:无
 *出口参数:无
 *说明:static 函数
 ******************/
static void FindStudent_name()
{
  char buff;
  char name[STUDENT_NAME_SIZE];
  
  system("clear");
  printf("\n\n");
  printf("\t\t*输入查询的名字:");
  scanf("%s",name);
  while((buff = getchar()) != '\n' && buff != EOF) ;
  
  system("clear");
  printf("\n");
  printf("\t\t***************\n");
  printf("\t\t*** 查询结果 ***\n");
  printf("\t\t***************\n");
  printf("\n\n");
  
  if(!FindName(name))
  {
    printf("\t\t*未查找到该学生信息!\n");
    pasue();
    return ;
  }
  PrintStudent(FindName(name));
  pasue();
}

/*******************
 *函数名称:FindStudent_num()
 *函数功能:按电话查找学生
 *入口参数:无
 *出口参数:无
 *说明:static 函数
 ******************/
static void FindStudent_num()
{
  char buff;
  char num[STUDENT_NUM_SIZE];
  
  system("clear");
  printf("\n\n");
  printf("\t\t*输入查询的号码:");
  scanf("%s",num);
  while((buff = getchar()) != '\n' && buff != EOF) ;
  
  system("clear");
  printf("\n");
  printf("\t\t***************\n");
  printf("\t\t*** 查询结果 ***\n");
  printf("\t\t***************\n");
  printf("\n\n");
  
  if(!FindNum(num))
  {
    printf("\t\t*未查找到该学生信息!\n");
    pasue();
    return ;
  }
  PrintStudent(FindNum(num));
  pasue();
}

/*******************
 *函数名称:FindStudent_rank()
 *函数功能:按排名查找学生
 *入口参数:无
 *出口参数:无
 *说明:static 函数
 ******************/
static void FindStudent_rank()
{
  char buff;
  int rank;
  //char name[STUDENT_NAME_SIZE];
  
  system("clear");
  printf("\n\n");
  printf("\t\t*输入查询的排名:");
  scanf("%d",&rank);
  while((buff = getchar()) != '\n' && buff != EOF) ;
  
  system("clear");
  printf("\n");
  printf("\t\t***************\n");
  printf("\t\t*** 查询结果 ***\n");
  printf("\t\t***************\n");
  printf("\n\n");
  
  if(!FindRank(rank))
  {
    printf("\t\t*未查找到该学生信息!\n");
    pasue();
    return ;
  }
  PrintStudent(FindRank(rank));
  pasue();
}

/*******************
 *函数名称:FindName()
 *函数功能:按名字查找
 *入口参数char ch[]
 *出口参数:pListNode 
 *说明:无
 ******************/
 
pListNode FindName(char ch[])
{
  pListNode p;
  int i;
  
  if(SYSTEM_CONFIG.STUDENT_COUNT == 0)
    return NULL;
  
  p = LINKLIST_HEAD->next;
  for(i=1;i<=SYSTEM_CONFIG.STUDENT_COUNT;i++)
  {
    if(!strcmp(ch,p->STUDENT_INFORMATION.student_name))
      break;
    p = p->next;
  }
  if(i == SYSTEM_CONFIG.STUDENT_COUNT+1)
    p = NULL;
  
  return p;
}

/*******************
 *函数名称:FindNum()
 *函数功能:按名字查找
 *入口参数char ch[]
 *出口参数:pListNode 
 *说明:无
 ******************/
 
pListNode FindNum(char ch[])
{
  pListNode p;
  int i;
  
  if(SYSTEM_CONFIG.STUDENT_COUNT == 0)
    return NULL;
  
  p = LINKLIST_HEAD->next;
  for(i=1;i<=SYSTEM_CONFIG.STUDENT_COUNT;i++)
  {
    if(!strcmp(ch,p->STUDENT_INFORMATION.student_num))
      break;
    p = p->next;
  }
  if(i == SYSTEM_CONFIG.STUDENT_COUNT+1)
    p = NULL;
  
  return p;
}

/*******************
 *函数名称:FindRank()
 *函数功能:按名字查找
 *入口参数int rank
 *出口参数:pListNode 
 *说明:无
 ******************/
 
pListNode FindRank(int rank)
{
  pListNode p;
  int i;
  
  if(SYSTEM_CONFIG.STUDENT_COUNT == 0)
    return NULL;
  
  p = LINKLIST_HEAD->next;
  for(i=1;i<=SYSTEM_CONFIG.STUDENT_COUNT;i++)
  {
    if(p->STUDENT_INFORMATION.student_grade_rank == rank)
      break;
    p = p->next;
  }
  if(i == SYSTEM_CONFIG.STUDENT_COUNT+1)
    p = NULL;
  
  return p;
}

/*
 *函数名称:ModifyRecord()
 *函数功能:修改记录
 *入口参数:无
 *出口参数:无
 *说明:无
 *
 */
 
void ModifyRecord()
{
  pListNode p;
  int option;
  int flag = 1;
  //int a;
  char buff;
  char tag;
  char *str;
  char name[STUDENT_NAME_SIZE];
  
   if(SYSTEM_CONFIG.STUDENT_COUNT == 0)
  {
    system("clear");
    printf("\n\n\t\t*无学生记录无法修改!\n");
    return ;
  }
  
  while(flag)
  {
    menu1_4();
    
    printf("\t\t*输入修改学生的姓名:");
    scanf("%s",name);
    while((buff = getchar()) != '\n' && buff != EOF);
    
    p = FindName(name);
    if(!p)
    { 
      printf("\t\t*未找到!\n");
      printf("\t\t*是否退出?(y/n):");
      scanf("%c",&tag);
      while((buff = getchar()) != '\n' && buff != EOF);
      if(tag == 'y')
        return;
    }
    else
    {
      PrintStudent(p);
      printf("\t\t*1.修改姓名.\n");
      printf("\t\t*2.修改性别.\n");
      printf("\t\t*3.修改年龄.\n");
      printf("\t\t*4.修改手机号.\n");
      printf("\t\t*5.修改语文成绩.\n");
      printf("\t\t*6.修改数学成绩.\n");
      printf("\t\t*7.修改英语.\n");
      printf("\t\t*8.返回.\n");
    
      printf("\t\t*请选择:");
      scanf("%d",&option);
      while((buff = getchar()) != '\n' && buff != EOF);
      
      switch(option)
      {
        case 1 :
               system("clear");
               printf("\n\n");
               printf("\t\t*原学生姓名:%s\n",name);
               printf("\t\t*修改为(不超过%d个字符):",STUDENT_NAME_SIZE);
               scanf("%s",name);
               strcpy(p->STUDENT_INFORMATION.student_name,name);
               printf("\t\t*已修改!\n");
               pasue();
               break;
        case 2 : printf("\t\t*未开发!\n");pasue();break;
        case 3 : printf("\t\t*未开发!\n");pasue();break;
        case 4 : printf("\t\t*未开发!\n");pasue();break;
        case 5 : printf("\t\t*未开发!\n");pasue();break;
        case 6 : printf("\t\t*未开发!\n");pasue();break;
        case 7 : printf("\t\t*未开发!\n");pasue();break;
        case 8 : flag = 0;break;
        default : printf("\t\t*输入不合法\n");
                  pasue();
      }
    }
  }
}

/*******************
 *函数名称:SaveData()
 *函数功能:将内存数据存入文件
 *入口参数:无
 *出口参数:无
 *说明:无
 ******************/

void SaveData()
{
  int i;
  FILE *fp,*fq;
  pListNode p, q;
  
  fp = fopen("user_password.dat","wb");
  if(!fp)
  {
    printf("\t\t*数据写入失败!\n");
    exit(-1);
  }
  fprintf(fp,"%s",SYSTEM_CONFIG.USER_PASSWORD);
  fclose(fp);
  
  fp = fopen("user_name.dat","wb");
  if(!fp)
  {
    printf("\t\t*数据写入失败!\n");
    exit(-1);
  }
  fprintf(fp,"%s",SYSTEM_CONFIG.USER_NAME);
  fclose(fp);
  
  fp = fopen("student_information.dat","wb");
  if(!fp)
  {
    printf("\t\t*数据写入失败!\n");
    exit(-1);
  }
  fq = fopen("student_count.dat","wb");
  if(!fq)
  {
    printf("\t\t*数据写入失败!\n");
    exit(-1);
  }
  
  if(SYSTEM_CONFIG.STUDENT_COUNT == 0)
  {
    p = LINKLIST_HEAD;
    q = p->next;
    free(p);
    free(q);
    fprintf(fq,"%d",SYSTEM_CONFIG.STUDENT_COUNT);
    fclose(fq);
    fprintf(fp,"%d",0);
    fclose(fp);
    
    return ;
  }
  
  p = LINKLIST_HEAD;
  q = p->next;
  free(p);
  p = NULL;
  
  for(i=1;i<=SYSTEM_CONFIG.STUDENT_COUNT;i++)
  {
    p = q;
    q = p->next;
    fwrite(p,sizeof(ListNode),1,fp);
    free(p);
  }
  free(q);
  fclose(fp);
  fprintf(fq,"%d",SYSTEM_CONFIG.STUDENT_COUNT);
  fclose(fq);
}

/*******************
 *函数名称:DeleteRecord()
 *函数功能:删除某项记录
 *入口参数:无
 *出口参数:无
 *说明:无
 ******************/

void DeleteRecord()
{
  int i;
  int count = 0;
  int flag = 1;
  char option;
  char buff;
  pListNode p,q;
  char student_name[STUDENT_NAME_SIZE];
  
  if(SYSTEM_CONFIG.STUDENT_COUNT == 0)
  {
    printf("\t\t*无学生信息，无法删除!\n");
    pasue();
    return ;
  }
  
  menu1_3();
  
  printf("\t\t*输入删除学生的姓名:");
  scanf("%s",student_name);
  while((buff = getchar()) != '\n' && buff != EOF) ;
  
  p = LINKLIST_HEAD->next;
  q = LINKLIST_HEAD;
  for(i=1;i<=SYSTEM_CONFIG.STUDENT_COUNT;i++)
  {
    if(!strcmp(student_name,p->STUDENT_INFORMATION.student_name))
      count++;
    p = p->next;
    q = q->next;
  }
  
  if(count == 0)
  {
    printf("\t\t*未找到%s的信息!\n",student_name);
    pasue();
    printf("\t\t*是否退出?(y/n):");
    scanf("%c",&option);
    while((buff = getchar()) != '\n' && buff != EOF) ;
    
    if(option == 'y')
      return ;
    DeleteRecord();
  }
  else if(count == 1)
  {
    while(flag)
    {
      p = LINKLIST_HEAD->next;
      q = LINKLIST_HEAD;
      for(i=1;i<=SYSTEM_CONFIG.STUDENT_COUNT;i++)
      {
        if(!strcmp(student_name,p->STUDENT_INFORMATION.student_name))
          break;
        p = p->next;
        q = q->next;
      }
    
      PrintStudent(p);
    
      printf("\t\t*是否删除该学生信息?(y/n):");
      scanf("%c",&option);
      while((buff = getchar()) != '\n' && buff != EOF) ;
    
      if(option == 'y')
      {
        q->next = p->next;
        free(p);
        p = NULL;
        printf("\t\t*已删除!\n");
        SYSTEM_CONFIG.STUDENT_COUNT--;
        flag = 0;
        pasue();
      }
      else if(option == 'n')
      {
        printf("\t\t*未删除!\n");
        flag = 0;
        pasue();
      }
      else
      {
        printf("\t\t*输入不合法,请重新输入!\n");
        pasue();
      }
    }
  }
  else
  {
    //有重名的情况暂不考虑!
  }
}

/*******************
 *函数名称:PrintStudent()
 *函数功能:打印单个学生信息
 *入口参数:pListNode 
 *出口参数:无
 *说明:无
 ******************/

void PrintStudent(pListNode pstudent)
{
  if(!pstudent)
  {
    printf("\n\t\t*EMPTU!*\n");
    return ;
  }
  else
  {
    //system("clear");
    printf("\n");
    printf("\t\t_______________\n");
    printf("\t\t*姓名:%s\n",pstudent->STUDENT_INFORMATION.student_name);
    printf("\t\t*性别:%s\n",pstudent->STUDENT_INFORMATION.student_sex);
    printf("\t\t*年龄:%d\n",pstudent->STUDENT_INFORMATION.student_age);
    printf("\t\t*手机号:%s\n",pstudent->STUDENT_INFORMATION.student_num);
    printf("\t\t*语文成绩:%.2f\n",pstudent->STUDENT_INFORMATION.student_chinese_grade);
    printf("\t\t*数学成绩:%.2f\n",pstudent->STUDENT_INFORMATION.student_math_grade);
    printf("\t\t*英语成绩:%.2f\n",pstudent->STUDENT_INFORMATION.student_english_grade);
    printf("\t\t*平均成绩:%.2f\n",pstudent->STUDENT_INFORMATION.student_average_grade);
    printf("\t\t_______________\n");
    printf("\n");
  }
}

/*
 *函数名称:SummaryRecord()
 *函数功能:统计记录
 *入口参数:无
 *出口参数:无
 *说明:无
 *
 */

void SummaryRecord()
{
  int boy_count = 0,girl_count = 0;
  float chinese_aver,math_aver,english_aver;
  int ch_fail_count = 0,ma_fail_count = 0,en_fail_count = 0;
  float ch_per,ma_per,en_per;
  float ch_sum = 0.0,ma_sum = 0.0,en_sum = 0.0;
  pListNode p;
  int i;
  
  if (SYSTEM_CONFIG.STUDENT_COUNT == 0)
  {
    system("clear");
    printf("\t\t*无记录!\n");
    pasue();
    return ;
  }
  
  p = LINKLIST_HEAD->next;
  for(i=1;i<=SYSTEM_CONFIG.STUDENT_COUNT;i++)
  {
    if(!strcmp("男",p->STUDENT_INFORMATION.student_sex))
      boy_count++;
    else
      girl_count++;
    
    if((FloatCmp(JIGE,p->STUDENT_INFORMATION.student_chinese_grade,JINDU)) == 1)
      ch_fail_count++;
    if((FloatCmp(JIGE,p->STUDENT_INFORMATION.student_math_grade,JINDU)) == 1)
      ma_fail_count++;
    if((FloatCmp(JIGE,p->STUDENT_INFORMATION.student_english_grade,JINDU)) == 1)
      en_fail_count++;
      
    ch_sum += p->STUDENT_INFORMATION.student_chinese_grade;
    ma_sum += p->STUDENT_INFORMATION.student_math_grade;
    en_sum += p->STUDENT_INFORMATION.student_english_grade;
    
    chinese_aver = ch_sum / (float)SYSTEM_CONFIG.STUDENT_COUNT;
    math_aver = ma_sum / (float)SYSTEM_CONFIG.STUDENT_COUNT;
    english_aver = en_sum / (float)SYSTEM_CONFIG.STUDENT_COUNT;
    
    ch_per = ((float)SYSTEM_CONFIG.STUDENT_COUNT - (float)ch_fail_count) / (float)SYSTEM_CONFIG.STUDENT_COUNT;
    ch_per = ch_per * 100.0;
    ma_per = ((float)SYSTEM_CONFIG.STUDENT_COUNT - (float)ma_fail_count) / (float)SYSTEM_CONFIG.STUDENT_COUNT;
    ma_per = ma_per * 100.0;
    en_per = ((float)SYSTEM_CONFIG.STUDENT_COUNT - (float)en_fail_count) / (float)SYSTEM_CONFIG.STUDENT_COUNT;
    en_per = en_per * 100.0;
    
    p = p->next;
  }
  
  menu1_5();
  
  printf("\t__________________________________\n");
  printf("  总人数:%3d   男:%2d   女:%2d\n"
          ,SYSTEM_CONFIG.STUDENT_COUNT,boy_count,girl_count);
  printf("  语文平均成绩:%2.1f 不及格人数:%2d 及格率:%2.1f%%\n"
          ,chinese_aver,ch_fail_count,ch_per);
  printf("  数学平均成绩:%2.1f 不及格人数:%2d 及格率:%2.1f%%\n"
          ,math_aver,ma_fail_count,ma_per);
  printf("  英语平均成绩:%2.1f 不及格人数:%2d 及格率:%2.1f%%\n"
          ,english_aver,en_fail_count,en_per);
  printf("\t__________________________________\n\n");
  pasue();
  //printf("\t%11s %2.2f %11s %2d %7s %2.2f\n",);
  //printf("\t%11s %2.2f %11s %2d %7s %2.2f\n",);
}

/*
 *函数名称:FloatCmp()
 *函数功能:按指定精度比较浮点数大小
 *入口参数:float,float,float
 *出口参数:int
 *说明:无
 *
 */
 
int FloatCmp(float a,float b,float jindu)
{
  if((a - b) < 0.0)
    return -1;
  if((a - b) <= jindu)
    return 0;
  if((a - b) > jindu)
    return 1;
}
