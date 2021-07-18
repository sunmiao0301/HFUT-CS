#pragma once
#ifndef RESOURCE_ALLOCATION_CHART
#define RESOURCE_ALLOCATION_CHART

#define	Resource_Node_Num 6	/*资源结点类的最大值*/
#define Resource_Max_Num 6	/*每个资源结点类内资源个数的最大值*/
#define Process_Node_Num 6	/*进程结点的最大值*/

typedef struct Resourece_Allocation_Chart
{
    int	Resource_Node_Array[Resource_Node_Num]; /*资源结点类数组，数组内的值是该资源类的资源个数，个数不能超过Resource_Max_Num*/
    int Resource_To_Process_Allocation_Edge[Resource_Max_Num][Process_Node_Num];  /*资源到进程的分配边，横着是资源，竖着是进程*/
    int Process_To_Resource_Request_Edge[Process_Node_Num][Resource_Node_Num];	  /*进程到资源的分配边，横着是进程，竖着是资源*/

}Resourece_Allocation_Chart;

/*
注意：将函数声明写在头文件中，比如这里的pch.h。
这样在需要使用的静态库的源文件中通过#include“…/pch.h”(绝对路径或相对路径)，
就可以将函数声明包含进来。否则编译器无法识别你在静态库中写的函数
*/
#ifdef __cplusplus
extern "C" {
    void init(Resourece_Allocation_Chart *chart);
    void Chart_Read_From_File(Resourece_Allocation_Chart *chart);
    void Add_Edge_Resource_To_Process(Resourece_Allocation_Chart *chart, int Resourece_index, int Process_index);
    void Add_Edge_Process_To_Resource(Resourece_Allocation_Chart *chart, int Process_index, int Resource_index);
    void Delete_Resource_Node(Resourece_Allocation_Chart*chart, int Resource_index);
    void Delete_Process_Node(Resourece_Allocation_Chart*chart, int Process_index);
    void Delete_Allocation_Edge(Resourece_Allocation_Chart *chart, int Resource_index, int Process_index);
    void Delete_Request_Edge(Resourece_Allocation_Chart *chart, int Resource_index, int Process_index);
    void Chart_Write_To_File(Resourece_Allocation_Chart *chart);
}
#endif
#endif
