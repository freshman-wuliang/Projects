#include"menu.h"
#include"part7.h"
#include<stdio.h>

int main()
{
  int option;
  int flag = 1;
  char buff;
  
  if (checkfirst())
      setsystem();
  else if (!initsystem(&SYSTEM_CONFIG))
       {
         pasue();
         recoverysystem();
       }
       else
       {
         loginsystem();
         if(!loaddata())
           printf("\t\t*暂无数据等待添加!\n");
         else
          	 printf("\t\t*数据加载完成!\n");
        	pasue();
          
         while(flag)
         {
           menu0_1();
            
           printf("\t\t*请选择:");
           scanf("%d",&option);
           while((buff = getchar()) != '\n' && buff != EOF) ;
            
           switch(option)
           {
             case 1 : AddRecord();break;
             case 2 : FindStudent();break;
             case 3 : DisplayInformation();break;
             case 4 : ModifyRecord();break;
             case 5 : DeleteRecord();break;
             case 6 : SummaryRecord();break;
             case 7 : ChangePassword();break;
             case 8 : flag = 0;break;
             default : printf("\t\t*输入不合法!\n");
                       pasue();
           }
         }
         SaveData();
         end_menu();
       }
  return 0;
}
