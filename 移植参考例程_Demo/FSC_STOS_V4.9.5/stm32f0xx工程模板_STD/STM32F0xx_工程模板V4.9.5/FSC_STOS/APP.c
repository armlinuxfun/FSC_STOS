#include "fsc_stos.h"  //使用多任务内核
#include "led.h"
#include "USART1.h"

/******************************创建任务参数*************************/
void Task1(void); //任务1声明
void Task2(void); //任务2声明
void Task3(void); //任务3声明
void Task4(void); //任务4声明
void Task5(void); //任务5声明

//静态建创任务所需要的栈内存
//#define Task1_StkSize 128  //任务1堆栈大小
//#define Task2_StkSize 128  //任务2堆栈大小 
//#define Task3_StkSize 128  //任务3堆栈大小 
//#define Task4_StkSize 128  //任务4堆栈大小
//#define Task5_StkSize 128  //任务5堆栈大小

//OSSTK Task1_Stk[Task1_StkSize]; //任务1堆栈
//OSSTK Task2_Stk[Task2_StkSize]; //任务2堆栈
//OSSTK Task3_Stk[Task3_StkSize]; //任务3堆栈
//OSSTK Task4_Stk[Task4_StkSize]; //任务4堆栈
//OSSTK Task5_Stk[Task5_StkSize]; //任务5堆栈
//静态建创任务所需要的栈内存

void OS_MAIN(void)
{
	 /*-------------------全局变量及宏定义区------------------------*/
   USART1_Init(9600);


   /*-------------------------------------------------------------*/
	 /************************************************************************************/	
	 OSInit(); //系统初使化
	 /********************************在系统中创建任务***********************************/
	 //任务优先级(越大越高，范围：0-OS_MAX_TASKS-1)
	
	 //静态创建(需要用户提供内存空间)
	 /*                  任务名  任务函数名   栈地址     栈大小      时间片  优先级     任务状态*/
//	 OSTaskCreateStatic("Task1", Task1,  Task1_Stk, Task1_StkSize, 10,     1,     TASK_RUNNING); //OS创建任务1
//	 OSTaskCreateStatic("Task2", Task2,  Task2_Stk, Task2_StkSize, 10,     2,     TASK_RUNNING); //OS创建任务2
//	 OSTaskCreateStatic("Task3", Task3,  Task3_Stk, Task3_StkSize, 10,     5,     TASK_RUNNING); //OS创建任务3
//	 OSTaskCreateStatic("Task4", Task4,  Task4_Stk, Task4_StkSize, 10,     4,     TASK_RUNNING); //OS创建任务4
//	 OSTaskCreateStatic("Task5", Task5,  Task5_Stk, Task5_StkSize, 10,     5,     TASK_RUNNING); //OS创建任务5
	
	 
	 //动态创建(系统自动根据栈参数生成空间,注意设置好内存池的大小)
	 /*            任务名  任务函数名  栈大小  时间片  任务优先级   任务状态*/
	 OSTaskCreate("Task1",  Task1,    128,     10,       4,    TASK_RUNNING); //OS创建任务1
	 OSTaskCreate("Task2",  Task2,    64,     10,       6,    TASK_RUNNING); //OS创建任务2
	 OSTaskCreate("Task3",  Task3,    32,     10,       5,    TASK_RUNNING); //OS创建任务3
	 OSTaskCreate("Task4",  Task4,    32,     10,       5,    TASK_RUNNING); //OS创建任务4
	 OSTaskCreate("Task5",  Task5,    32,     10,       3,    TASK_RUNNING); //OS创建任务5
	 /***********************************************************************************/
	 OSStartUp();//OS开始运行
}
/********************************************************************************************************************/
/*-------------------全局变量及宏定义区------------------------*/


/*-----------------------------------------------------------*/

void Task1(void)  //任务1
{ 	
  LED_Init();
  while (1)
  {	
		LED_ON();
		OS_delayMs(500);
		LED_OFF();
		OS_delayMs(500);
		OSprintf("Task1 is running  \r\n");
  } 	
}

void Task2(void) //任务2
{
	while(1) 
	 {
		 OSprintf("Task2 is running  \r\n");
		 OS_delayMs(2000);
	 }			
}

void Task3(void) //任务3
{	
	while(1) 
	 {
	 
		 OS_delayMs(0);
	 }			
}

void Task4(void) //任务4
{
	while(1) 
	 {		
		
		 OS_delayMs(0);
	 }
}

void Task5(void) //任务5
{
	while(1) 
	 {	
	
		 OS_delayMs(0);
	 }
}
/********************************************************************************************************************/

