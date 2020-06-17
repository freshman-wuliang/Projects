#ifndef _HEAD_H_
#define _HEAD_H_

#define USER_NAME_SIZE 26   //用户名长度
#define USER_PASSWORD_SIZE 7   //密码长度
#define STUDENT_NAME_SIZE 16   //学生姓名长度
#define STUDENT_SEX_SIZE 4   //学生性别长度
#define STUDENT_NUM_SIZE 12   //学生手机号长度

//char USER_NAME[USER_NAME_SIZE];   //用户名全局变量
//char USER_PASSWORD[USER_PASSWORD_SIZE];   //密码全局变量
//int FALSE_COUNT;   //记录错误次数

typedef struct
{
  char USER_NAME[USER_NAME_SIZE];   //用户名全局变量
  char USER_PASSWORD[USER_PASSWORD_SIZE];   //用户密码全局变量 
  int FALSE_COUNT;   //错误次数全局变量
  int STUDENT_COUNT;   //学生数量全局变量
}system_config;

system_config SYSTEM_CONFIG;   //系统配置结构体

typedef struct 
{
  char student_name[STUDENT_NAME_SIZE];
  char student_sex[STUDENT_SEX_SIZE];
  int student_age;
  char student_num[STUDENT_NUM_SIZE];
  float student_chinese_grade;
  float student_english_grade;
  float student_math_grade;
  float student_average_grade;
  int student_grade_rank;
}student_information;

student_information STUDENT_INFORMATION;

#endif
