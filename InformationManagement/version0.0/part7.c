#include"part7.h"

/********************
 *函数名称:checkfirst()
 *函数功能:检查程序是否第一次执行
 *入口参数:无
 *出口参数:返回检查结果 1表示是第一次 0表示不是第一次
 *说明:无
 *******************/
 
int checkfirst()
{
  FILE *fp;
  
  fp = fopen("check_first.conf","rb");
  if(!fp)
    return 1;
  else
    return 0;
}

/******************
 *函数名称:setsystem()
 *函数功能:首次配置程序
 *入口参数:无
 *出口参数:无
 *说明:无
 *****************/
 
void setsystem()
{
  int i;
  char option;
  char buff;
  char user_name[USER_NAME_SIZE];
  char user_password[USER_PASSWORD_SIZE];
  FILE *fp;
  
  system("clear");
  printf("\n\n");
  printf("\t\t*程序检测到你是第一次登录系统\n");
  printf("\t\t*是否添加用户(y/n):\n\t\t:");
  scanf("%c",&option);
  while((buff = getchar()) != '\n' && buff != EOF);
  if(option == 'y')
  {
    
    menu0_0();
  
    printf("\t\t1-> 请输入用户名:\n");
    printf("\t\tps:不超过%d个字符\n",USER_NAME_SIZE-1);
    printf("\t\t");
    for(i=0;i<USER_NAME_SIZE-1;i++)
    { 
      scanf("%c",&user_name[i]);
      if(user_name[i] == '\n')
      break;
    }
    user_name[i] = '\0';
    //while((buff = getchar()) != '\n' && buff != EOF);
    //printf("%s\n",user_name);
    printf("\t\t2-> 设置6位用户密码:\n\t\t");
    for(i=0;i<USER_PASSWORD_SIZE-1;i++)
      scanf("%c",&user_password[i]);
    user_password[i] = '\0';
    //while((buff = getchar()) != '\n' && buff != EOF);
    //printf("%s\n",user_password);
    
    fp = fopen("user_name.dat","wb");
    if(!fp)
    {
      printf("\t\t*系统配置文件创建失败退出系统!\n");
      exit(-1) ;
    }
    fprintf(fp,"%s",user_name);
    fclose(fp);
    
    fp = fopen("user_password.dat","wb");
    if(!fp)
    {
      printf("\t\t*系统配置文件创建失败!\n");
      exit(-1) ;
    }
    fprintf(fp,"%s",user_password);
    fclose(fp);
    
    fp = fopen("check_first.conf","wb");
    if(!fp)
    {
      printf("\t\t*系统配置文件创建失败!\n");
      exit(-1) ;
    }
    fclose(fp);
    
    fp = fopen("student_count.dat","wb");
    if(!fp)
    {
      printf("\t\t*系统配置文件创建失败!\n");
      exit(-1);
    }
    fprintf(fp,"%d",0);
    fclose(fp);
    
    fp = fopen("student_information.dat","wb");
    if(!fp)
    {
      printf("\t\t*系统配置文件创建失败!\n");
      exit(-1);
    }
    fclose(fp);
    
    printf("\t\t*系统配置完成重启后生效!\n");
  }
  else if(option == 'n')
    exit(-1) ;
  else
  {
    printf("\t\t输入不合法\n");
    pasue();
    setsystem();
  }
}

/*******************
 *函数名称:initsystem()
 *函数功能:初始化系统
 *入口参数:system_config *
 *出口参数:int 
 *说明:成功返回1,失败返回0.
 *******************/

int initsystem(system_config *SYSTEM_CONFIG)
{
  FILE *fp;
  
  SYSTEM_CONFIG->FALSE_COUNT = 0;
  
  LINKLIST_HEAD = (pListNode)malloc(sizeof(ListNode));
  if(!LINKLIST_HEAD)
  {
    printf("\t\t*系统初始化失败!\n");
    return 0;
  }
  LINKLIST_HEAD->next = NULL;
  
  LINKLIST_END = (pListNode)malloc(sizeof(ListNode));
  if(!LINKLIST_END)
  {
    printf("\t\t*系统初始化失败!\n");
    return 0;
  }
  LINKLIST_END->next = LINKLIST_HEAD;
  LINKLIST_HEAD->next = LINKLIST_END;
  
  
  fp = fopen("user_name.dat","rb");
  if(!fp)
  {
    printf("\t\t*系统数据文件打开失败!\n");
    return 0;
  }
  fscanf(fp,"%s",SYSTEM_CONFIG->USER_NAME);
  fclose(fp);
  
  fp = fopen("user_password.dat","rb");
  if(!fp)
  {
    printf("\t\t*系统数据文件打开失败!\n");
    return 0;
  }
  fscanf(fp,"%s",SYSTEM_CONFIG->USER_PASSWORD);
  fclose(fp);
  
  fp = fopen("student_count.dat","rb");
  if(!fp)
  {
    printf("\t\t*系统数据文件打开失败!\n");
    return 0;
  }
  fscanf(fp,"%d",&SYSTEM_CONFIG->STUDENT_COUNT);
  fclose(fp);
  
  return 1;
}

/*******************
 *函数名称:loginsystem()
 *函数功能:系统登录
 *入口参数:无
 *出口参数:无
 *说明:无
 ******************/
void loginsystem()
{
  char user_name[USER_NAME_SIZE];
  char user_password[USER_PASSWORD_SIZE];
  int i;
  
  menu0_2();
  
  printf("\n\n");
  printf("\t\t*用户名:");
  for(i=0;i<USER_NAME_SIZE-1;i++)
  { 
    scanf("%c",&user_name[i]);
    if(user_name[i] == '\n')
      break;
  }
  user_name[i] = '\0';
  
  printf("\t\t*密码:");
  for(i=0;i<USER_PASSWORD_SIZE-1;i++)
  { 
    user_password[i] = getchar();   //会回显
    if(user_password[i] == '\n')
      break;
    else
      putchar('*');
  }
  user_password[i] = '\0';
  printf("\n");
  
  //printf("%s\n",user_name);
  //printf("%s\n",user_password);
  
  if(strcmp(user_name,SYSTEM_CONFIG.USER_NAME) || strcmp(user_password,SYSTEM_CONFIG.USER_PASSWORD))
  {
    printf("\t\t*用户名或密码输入不正确!\n");
    SYSTEM_CONFIG.FALSE_COUNT++;
    if(SYSTEM_CONFIG.FALSE_COUNT >= 3)
    {
      printf("\t\t*你已输入错误三次\n");
      printf("\t\t*程序已自动关闭!\n\t\t*ending!\n");
      exit(-1);
    }
    pasue();
    loginsystem();
  }
}

/********************
 *函数名称:recoverysystem()
 *函数功能:恢复系统至初始状态
 *入口参数:无
 *出口参数:无
 *说明:无
 *******************/

void recoverysystem()
{
  char option;
  char buff;
  
  printf("\t\t*该操作会删除账号信息!!!\n");
  printf("\t\t*请谨慎操作!!!\n");
  printf("\t\t*是否恢复系统(y/n)\n\t\t:");
  
  scanf("%c",&option);
  while((buff = getchar()) != '\n' && buff != EOF);
  
  if(option == 'y')
    system("rm check_first.conf");
  else if(option == 'n')
     return ;
  else 
    printf("\t\t*输入不合法!\n");
  printf("\t\t*系统恢复完成，请重启!\n");
}

/*
 *函数名称:ChangePassword()
 *函数功能:修改系统密码
 *入口参数:无
 *出口参数:无
 *说明:无
 */

void ChangePassword()
{
  int i;
  char password[USER_NAME_SIZE];
  
  system("clear");
  printf("\n\n");
  printf("\t\t*输入旧密码:");
  for(i=0;i<USER_PASSWORD_SIZE-1;i++)
  {
    password[i] = getchar();
    if(password[i] != '\n')
      putchar('*');
    else
      break;
  }
  password[i] = '\0';
  
  if(strcmp(password,SYSTEM_CONFIG.USER_PASSWORD))
  {
    printf("\n\t\t*密码输入错误!\n");
    pasue();
    return ;
  }
  
  printf("\n\t\t*输入新密码(最多%d位):",USER_PASSWORD_SIZE);
  for(i=0;i<USER_PASSWORD_SIZE-1;i++)
    scanf("%c",&password[i]);
  password[i] = '\0';
  strcpy(SYSTEM_CONFIG.USER_PASSWORD,password);
  printf("\t\t*密码已修改!\n");
  pasue();
}
