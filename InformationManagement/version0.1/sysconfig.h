#ifndef SYSCONFIG_H
#define SYSCONFIG_H

#define TRUE 1
#define FALSE 0
#define ERROR -1
#define USER_NAME_SIZE 26
#define USER_PASSWORD_SIZE 7

typedef int status;

typedef struct 
{
	char user_name[USER_NAME_SIZE];   //用户名
	char user_password[USER_PASSWORD_SIZE];   //用户密码
	int false_count;   //密码错误次数
	int first_flag;    //系统第一次登录标志
}sys_conf;

sys_conf g_sysconfig;   //系统配置全局变量

#endif

/*****************************
 *函数名称:checkfirst()
 *函数功能:检查系统是否第一次运行
 *入口参数:void
 *出口参数:status;第一次运行返回TRUE，否则返回FALSE
 *说明:函数通过sys_conf.first_flag标志位判断是否第一次登录系统
 *****************************/

status checkFirst(void);

/*****************************
 *函数名称:setsystem()
 *函数功能:初始配置系统
 *入口参数:void
 *出口参数:void
 *说明:初始设置系统用户名、密码等
 *****************************/

void setSystem(void);

/*****************************
 *函数名称:initsystem()
 *函数功能:初始化系统
 *入口参数:void
 *出口参数:int;初始化成功返回1，否则返回0
 *说明:读取usercount.dat,username.dat等文件初始化系统
 *****************************/

status initSystem(void);

/*****************************
 *函数名称:loginsystem()
 *函数功能:登录系统
 *入口参数:void
 *出口参数:status;成功返回TRUE,失败返回FALSE
 *说明:
 *****************************/

void loginSystem(void);

/*****************************
 *函数名称:recoversystem()
 *函数功能:恢复系统至未配置状态
 *入口参数:void
 *出口参数:void
 *说明:删除系统配置文件，恢复空白状态
 *****************************/

void recoverSystem(void);

/*****************************
 *函数名称:changepassword()
 *函数功能:修改用户密码
 *入口参数:void
 *出口参数:void
 *说明:
 *****************************/

void changePassword(void);

/*****************************
 *函数名称:loaddata()
 *函数功能:加载数据
 *入口参数:void
 *出口参数:status;加载成功返回TRUE，否则返回FALSE
 *说明:由数据文件建立链表
 *****************************/

status loadData(void);

/*****************************
 *函数名称:saveData()
 *函数功能:存储数据
 *入口参数:void
 *出口参数:status;成功返回TRUE，失败返回FALSE
 *说明:将数据写入文件存储
 *****************************/

status saveData(void);
