#include <stdlib.h> 

#include<stdio.h>
#include<windows.h>

/*
头文件
*/
#include"D:/OS_EXPL/Os_Kernal/Os_Kernal/Resource_Allocation_Chart.h"

/*
调用静态链接库
*/
#pragma comment (lib, "D:/OS_EXPL/Os_Kernal/x64/Debug/Os_Kernal.lib")

int main() {
	/*
	或是
	struct Resourece_Allocation_Chart chart =
	{
	{ 1,2,3,4,5,6 } ,

	{
	{ 1,0,0,0,0,0 },
	{ 0,2,0,0,0,0 },
	{ 0,0,3,0,0,0 },
	{ 0,0,0,4,0,0 },
	{ 0,0,0,0,5,0 },
	{0,0,0,0,0,6}
	},
	{
	{ 0,1,0,0,0,0 },
	{ 0,0,1,0,0,0 },
	{ 0,0,0,1,0,0 },
	{ 0,0,0,0,1,0 },
	{ 0,0,0,0,0,1 },
	{ 1,0,0,0,0,0 }
	}
	};
	*/
	struct Resourece_Allocation_Chart chart;

	/*
	c语言中将结构体对象指针作为函数的参数实现对结构体成员的修改!
	以下是我设计的算例：
	1）初始化一个死锁状态（可选 因为后面还有一次读取文件的初始化 可以覆盖这次）
	2）把文件中预存的资源分配图数据结构 读取到结构体中（可选 因为前面还有一次调用函数的初始化 可以取代这次）
	3）增加资源->进程的分配边
	4）增加进程->资源的请求边
	5）删除资源结点（删除两个矩阵中与其相关的所有边信息）
	6）删除进程结点（删除两个矩阵中与其相关的所有边信息）
	7）删除资源->进程的分配边
	8）删除进程->资源的请求边
	9）输出结构体的三个矩阵信息（作为检验，内核中不能有）
	10）把结构体中的数据结构信息 写入到文件中
	*/

	/*
	初始化函数init() 该初始化函数调用的初始化结果是一个死锁状态
	*/
	init(&chart);

	/*
	把文件中的数据结构读到结构体中
	*/
	//Chart_Read_From_File(&chart);

	/*
	以下六个函数全部经过单个实验 功能保证完全正确
	*/

	//Add_Edge_Resource_To_Process(&chart, 1, 1);
	
	//Delete_Resource_Node(&chart, 2);
	//Delete_Process_Node(&chart, 1);
	//printf("开始删除资源6给进程6的一个资源");
	//Delete_Allocation_Edge(&chart, 6, 6);
	//printf("删除完毕");
	//Delete_Allocation_Edge(&chart, 1, 1);
	//Delete_Request_Edge(&chart, 2, 3);
	//Add_Edge_Process_To_Resource(&chart, 2, 3);
	printf("开始检测死锁");
	Judge_DeadLock(&chart);
	printf("检查完毕");
	/*
	资源结点类内的资源数
	*/
	printf("我是main.cpp\n");
	printf("资源结点类内的资源数\n");
	for (int i = 0; i < Resource_Node_Num; i++) {
		printf("%d ", chart.Resource_Node_Array[i]);
		if (i == Process_Node_Num - 1)
			printf("\n");
	}
	/*
	输出资源->进程图
	*/
	printf("资源->进程图\n");
	for (int i = 0; i < Process_Node_Num; i++) {
		for (int j = 0; j < Resource_Node_Num; j++) {
			printf("%d ", chart.Resource_To_Process_Allocation_Edge[i][j]);
			if (j == Process_Node_Num - 1)
				printf("\n");
		}
	}
	/*
	输出进程->资源图
	*/
	printf("进程->资源图\n");
	for (int i = 0; i < Resource_Node_Num; i++) {
		for (int j = 0; j < Process_Node_Num; j++) {
			printf("%d ", chart.Process_To_Resource_Request_Edge[i][j]);
			if (j == Process_Node_Num - 1)
				printf("\n");
		}
	}

	/*
	把结构体中的数据结构写到文件中
	*/
	Chart_Write_To_File(&chart);

	system("pause");
}