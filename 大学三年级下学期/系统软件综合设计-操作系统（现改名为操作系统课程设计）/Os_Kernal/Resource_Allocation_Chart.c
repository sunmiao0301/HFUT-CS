#include <stdlib.h> 

#include<stdio.h>
#include<windows.h>
#include"Resource_Allocation_Chart.h"

//在此，建议统一使用UTF-8（无bom）编码格式

//限定是6 是为了画图方便 如果要改成可变的也很简单 只需要多加两个参数rows cols即可
#define	Resource_Node_Num 6	/*资源结点类的最大值*/
#define Resource_Max_Num 6	/*每个资源结点类内资源个数的最大值*/
#define Process_Node_Num 6	/*进程结点的最大值*/

/*
typedef struct Resourece_Allocation_Chart
{
int	Resource_Node_Array[Resource_Node_Num]; //资源结点类数组，数组内的值是该资源类的资源个数，个数不能超过Resource_Max_Num
int Resource_To_Process_Allocation_Edge[Resource_Max_Num][Process_Node_Num];  //资源到进程的分配边，横着是资源，竖着是进程
int Process_To_Resource_Request_Edge[Process_Node_Num][Resource_Node_Num];	  //进程到资源的分配边，横着是进程，竖着是资源

}Resourece_Allocation_Chart;
*/

void init(Resourece_Allocation_Chart *chart) /*资源分配图初始化*/
{
	/*
	资源->进程 矩阵初始化（横轴资源 竖轴进程）

	进程
资源1 0 0 0 0 0
	0 2 0 0 0 0
	0 0 3 0 0 0
	0 0 0 4 0 0
	0 0 0 0 5 0
	0 0 0 0 0 6

	进程->资源 矩阵初始化（横轴进程 竖轴资源）我认为同时只能申请一个 所以初始化矩阵是

	资源
进程0 1 0 0 0 0
	0 0 1 0 0 0
	0 0 0 1 0 0
	0 0 0 0 1 0
	0 0 0 0 0 1
	1 0 0 0 0 0
	*/
	//Resourece_Allocation_Chart chart;
	//但是这个没用上，感觉用处不大
	for (int i = 0; i < Resource_Node_Num; i++) {//数组除了初始化不能直接赋值的，你要给这个数组赋值就得循环一个个赋值了。
		(*chart).Resource_Node_Array[i] = 0;
		if (i + 1 <= Resource_Max_Num)
			(*chart).Resource_Node_Array[i] = i + 1;//{1，2，3，4，5，6}

	}
	for (int i = 0; i < Resource_Node_Num; i++) {
		for (int j = 0; j < Process_Node_Num; j++) {
			(*chart).Resource_To_Process_Allocation_Edge[i][j] = 0;
			if (i == j)
				(*chart).Resource_To_Process_Allocation_Edge[i][j] = i + 1;
		}
	}
	for (int i = 0; i < Process_Node_Num; i++) {
		for (int j = 0; j < Resource_Node_Num; j++) {
			(*chart).Process_To_Resource_Request_Edge[i][j] = 0;
			if (j == (i + 1) % 6)
				(*chart).Process_To_Resource_Request_Edge[i][j] = 1;
		}
	}
}

void Add_Edge_Resource_To_Process(Resourece_Allocation_Chart *chart, int Resource_index, int Process_index) {//一次只允许加一条边 前提是没有超出资源结点的能力范围
	int temp = 0;
	for (int i = 0; i < Process_Node_Num; i++) {
		temp += (*chart).Resource_To_Process_Allocation_Edge[Resource_index - 1][i];
		//if ((*chart).Resource_To_Process_Allocation_Edge[Resource_index - 1][Process_index - 1] + (*chart).Process_To_Resource_Request_Edge[Process_index - 1][Resourece_index - 1] < (*chart).Resource_Node_Array[Resourece_index - 1])
		//	(*chart).Resource_To_Process_Allocation_Edge[Resource_index - 1][Process_index - 1] += 1;
		//else
		//	;
	}
	if (temp < (*chart).Resource_Node_Array[Resource_index - 1])
		(*chart).Resource_To_Process_Allocation_Edge[Resource_index - 1][Process_index - 1] += 1;
	else
		;
}

void Add_Edge_Process_To_Resource(Resourece_Allocation_Chart *chart, int Process_index, int Resource_index) {//一次只允许加一条边
	int temp = 0;
	for (int i = 0; i < Resource_Node_Num; i++) {
		temp += (*chart).Process_To_Resource_Request_Edge[Process_index - 1][i];
	}
	if (temp == 0)
		(*chart).Process_To_Resource_Request_Edge[Process_index - 1][Resource_index - 1] = 1;
	else
		;

}

void Delete_Resource_Node(Resourece_Allocation_Chart*chart, int Resource_index) {
	//用sizeof试试 好玩
	int rows = sizeof((*chart).Resource_To_Process_Allocation_Edge) / sizeof((*chart).Resource_To_Process_Allocation_Edge[0]);
	int cols = sizeof((*chart).Resource_To_Process_Allocation_Edge[1]) / sizeof((*chart).Resource_To_Process_Allocation_Edge[1][1]);
	//对资源->进程图 操作
	for (int j = 0; j < cols; j++) {
		(*chart).Resource_To_Process_Allocation_Edge[Resource_index - 1][j] = 0;
	}
	//对进程->资源图 操作
	for (int i = 0; i < rows; i++) {
		(*chart).Process_To_Resource_Request_Edge[i][Resource_index - 1] = 0;
	}
}

void Delete_Process_Node(Resourece_Allocation_Chart*chart, int Process_index) {
	//对资源->进程图 操作
	for (int m = 0; m < Resource_Node_Num; m++) {
		(*chart).Resource_To_Process_Allocation_Edge[m][Process_index - 1] = 0;
	}
	//对进程->资源图 操作
	for (int n = 0; n < Process_Node_Num; n++) {
		(*chart).Process_To_Resource_Request_Edge[Process_index - 1][n] = 0;
	}
}

void Delete_Allocation_Edge(Resourece_Allocation_Chart *chart, int Resource_index, int Process_index) {//资源 分配 给 进程
																									   //对资源->进程图 操作
	if ((*chart).Resource_To_Process_Allocation_Edge[Resource_index - 1][Process_index - 1] > 0)
		(*chart).Resource_To_Process_Allocation_Edge[Resource_index - 1][Process_index - 1] -= 1;

	//对进程->资源图 操作
	//if (chart.Process_To_Resource_Request_Edge[Process_index - 1][Resource_index - 1] > 0)
	//	chart.Process_To_Resource_Request_Edge[Process_index - 1][Resource_index - 1] -= 1;

}

void Delete_Request_Edge(Resourece_Allocation_Chart *chart, int Process_index, int Resource_index) {//进程 向 资源 发出请求 
																									//对资源->进程图 操作
																									//if (chart.Process_To_Resource_Request_Edge[Process_index - 1][Resource_index - 1] > 0)
																									//	chart.Process_To_Resource_Request_Edge[Process_index - 1][Resource_index - 1] -= 1;

																									//对进程->资源图 操作
	//for (int i = 0; i < Resource_Node_Num; i++) {
		(*chart).Process_To_Resource_Request_Edge[Process_index - 1][Resource_index - 1] = 0;
	//}
	//if ((*chart).Process_To_Resource_Request_Edge[Resource_index - 1][Process_index - 1] > 0;	
}

/*
FILE* file = fopen("st.bin", "wb");
fwrite(&s, sizeof(char), sizeof(struct st), file);
fclose(file);
*/

void Chart_Write_To_File(Resourece_Allocation_Chart *chart) {
	//注意最后要把这些print去掉 因为指导书要求不能有

	FILE *stream;
	errno_t err;
	err = fopen_s(&stream, "D:\\data.txt", "w+");//使用w+ 如果你的路径文件不存在 自动建个新的 可读可写 不会乱码
												 /*
												 if (err == 0) {
												 printf("was opened");
												 }
												 else
												 printf("not opened");
												 */
	for (int i = 0; i < 3; i++) {
		if (i == 0) {
			for (int j = 0; j < Resource_Max_Num; j++) {
				fprintf(stream, "%d ", chart->Resource_Node_Array[j]);
				if (j == Process_Node_Num - 1)
					fprintf(stream, "\n");
			}
		}
		if (i == 1) {
			for (int m = 0; m < Resource_Max_Num; m++) {
				for (int n = 0; n < Process_Node_Num; n++) {
					fprintf(stream, "%d ", chart->Resource_To_Process_Allocation_Edge[m][n]);
					if (n == Process_Node_Num - 1)
						fprintf(stream, "\n");
				}
			}
		}
		if (i == 2) {
			for (int k = 0; k < Process_Node_Num; k++) {
				for (int l = 0; l < Resource_Max_Num; l++) {
					fprintf(stream, "%d ", chart->Process_To_Resource_Request_Edge[k][l]);
					if (l == Resource_Max_Num - 1)
						fprintf(stream, "\n");
				}
			}
		}
	}
	//fwrite(&student[i], sizeof(student), 1, fp);
	//fprintf(stream, "%d\n", chart->Resource_Node_Array);//, pa->num, pa->age, pa->score %d %f%s
	err = fclose(stream);
	/*
	if (err == 0) {
	printf("was not close");
	}
	else
	printf("was close");
	*/

}

void Chart_Read_From_File(Resourece_Allocation_Chart *chart) {
	//注意最后要把这些print去掉 因为指导书要求不能有

	FILE *stream;
	errno_t err;
	err = fopen_s(&stream, "D:\\data.txt", "r");
	//使用w+ 如果你的路径文件不存在 自动建个新的 如果该文件存在，其内容将被销毁可读可写 不会乱码 
												/*
												if (err == 0) {
												printf("was opened");
												}
												else
												printf("not opened");
												*/
	for (int i = 0; i < 3; i++) {
		if (i == 0) {
			for (int j = 0; j < Resource_Max_Num; j++) {
				/*
				需要注意区别 fscanf_s的第三个参数是地址 与fprintf 不同
				区别如下
				fprintf(fp,"%d,",ss[i]);
				fscanf(fp,"%d,",&new[i]);
				*/
				fscanf_s(stream, "%d ", &chart->Resource_Node_Array[j]);
				if (j == Process_Node_Num - 1)
					fscanf_s(stream, "\n");
			}
		}
		if (i == 1) {
			for (int m = 0; m < Resource_Max_Num; m++) {
				for (int n = 0; n < Process_Node_Num; n++) {
					fscanf_s(stream, "%d ", &chart->Resource_To_Process_Allocation_Edge[m][n]);
					if (n == Process_Node_Num - 1)
						fscanf_s(stream, "\n");
				}
			}
		}
		if (i == 2) {
			for (int k = 0; k < Process_Node_Num; k++) {
				for (int l = 0; l < Resource_Max_Num; l++) {
					fscanf_s(stream, "%d ", &chart->Process_To_Resource_Request_Edge[k][l]);
					if (l == Resource_Max_Num - 1)
						fscanf_s(stream, "\n");
				}
			}
		}
	}
	//for (i = 0; i<N; i++, pb++) {
	//	fscanf(fp, "%s %d %d %f\n", pb->name, &pb->num, &pb->age, &pb->score);
	//}
	err = fclose(stream);
	/*
	if (err == 0) {
	printf("was not close");
	}
	else
	printf("was close");
	*/
}

void Judge_DeadLock(Resourece_Allocation_Chart *chart) {
	int Process_Array[6] = { 1,1,1,1,1,1 };
	int break_flag = 1;
	int process_0_request_resource_index = 0;
	int resource_allocated = 0;
	int deadlock = 0;
	while (break_flag == 1) {//i = 0
		if (deadlock >= 6)
			break;
		/*
		进程1
		*/
		for (process_0_request_resource_index = 0; process_0_request_resource_index < Resource_Node_Num; process_0_request_resource_index++) {
			if ((*chart).Process_To_Resource_Request_Edge[0][process_0_request_resource_index] == 1) {// j 是进程0正在申请的资源的数组下标
				break;
			}
		}
		resource_allocated = 0;
		for (int i = 0; i < Process_Node_Num; i++) {
			resource_allocated += (*chart).Resource_To_Process_Allocation_Edge[process_0_request_resource_index][i];
		}
		if ((*chart).Resource_Node_Array[process_0_request_resource_index] > resource_allocated) {//该资源类还有剩余的资源数 进程0可以完成
			//该进程结点可以释放 删除两个表里与其有关的
			for (int m = 0; m < Resource_Node_Num; m++) {
				(*chart).Resource_To_Process_Allocation_Edge[m][0] = 0;
			}
			for (int n = 0; n < Process_Node_Num; n++) {
				(*chart).Process_To_Resource_Request_Edge[0][n] = 0;
			}
			Process_Array[0] = 0;
			deadlock = 0;
		}
		for (int i = 0; i <= Process_Node_Num; i++) {
			if (i == 6)
				break_flag = 0;
			if (Process_Array[i] == 1) {
				deadlock++;
				break;
			}
		}
		if (break_flag == 0)
			break;

		/*
		Process 2
		*/
		for (process_0_request_resource_index = 0; process_0_request_resource_index < Resource_Node_Num; process_0_request_resource_index++) {
			if ((*chart).Process_To_Resource_Request_Edge[1][process_0_request_resource_index] == 1) {// j 是进程0正在申请的资源的数组下标
				break;
			}
		}
		resource_allocated = 0;
		for (int i = 0; i < Process_Node_Num; i++) {
			resource_allocated += (*chart).Resource_To_Process_Allocation_Edge[process_0_request_resource_index][i];
		}
		if ((*chart).Resource_Node_Array[process_0_request_resource_index] > resource_allocated) {//该资源类还有剩余的资源数 进程0可以完成
			//该进程结点可以释放 删除两个表里与其有关的
			for (int m = 0; m < Resource_Node_Num; m++) {
				(*chart).Resource_To_Process_Allocation_Edge[m][1] = 0;
			}
			for (int n = 0; n < Process_Node_Num; n++) {
				(*chart).Process_To_Resource_Request_Edge[1][n] = 0;
			}
			Process_Array[1] = 0;
			deadlock = 0;
		}
		for (int i = 0; i <= Process_Node_Num; i++) {
			if (i == 6)
				break_flag = 0;
			if (Process_Array[i] == 1) {
				deadlock++;
				break;
			}

		}
		if (break_flag == 0)
			break;
	
		/*
		Process 3
		*/
		for (process_0_request_resource_index = 0; process_0_request_resource_index < Resource_Node_Num; process_0_request_resource_index++) {
			if ((*chart).Process_To_Resource_Request_Edge[2][process_0_request_resource_index] == 1) {// j 是进程0正在申请的资源的数组下标
				break;
			}
		}
		resource_allocated = 0;
		for (int i = 0; i < Process_Node_Num; i++) {
			resource_allocated += (*chart).Resource_To_Process_Allocation_Edge[process_0_request_resource_index][i];
		}
		if ((*chart).Resource_Node_Array[process_0_request_resource_index] > resource_allocated) {//该资源类还有剩余的资源数 进程0可以完成
			//该进程结点可以释放 删除两个表里与其有关的
			for (int m = 0; m < Resource_Node_Num; m++) {
				(*chart).Resource_To_Process_Allocation_Edge[m][2] = 0;
			}
			for (int n = 0; n < Process_Node_Num; n++) {
				(*chart).Process_To_Resource_Request_Edge[2][n] = 0;
			}
			Process_Array[2] = 0;
			deadlock = 0;
		}
		for (int i = 0; i <= Process_Node_Num; i++) {
			if (i == 6)
				break_flag = 0;
			if (Process_Array[i] == 1) {
				deadlock++;
				break;
			}

		}
		if (break_flag == 0)
			break;

		/*
		Process 4
		*/
		for (process_0_request_resource_index = 0; process_0_request_resource_index < Resource_Node_Num; process_0_request_resource_index++) {
			if ((*chart).Process_To_Resource_Request_Edge[3][process_0_request_resource_index] == 1) {// j 是进程0正在申请的资源的数组下标
				break;
			}
		}
		resource_allocated = 0;
		for (int i = 0; i < Process_Node_Num; i++) {
			resource_allocated += (*chart).Resource_To_Process_Allocation_Edge[process_0_request_resource_index][i];
		}
		if ((*chart).Resource_Node_Array[process_0_request_resource_index] > resource_allocated) {//该资源类还有剩余的资源数 进程0可以完成
			//该进程结点可以释放 删除两个表里与其有关的
			for (int m = 0; m < Resource_Node_Num; m++) {
				(*chart).Resource_To_Process_Allocation_Edge[m][3] = 0;
			}
			for (int n = 0; n < Process_Node_Num; n++) {
				(*chart).Process_To_Resource_Request_Edge[3][n] = 0;
			}
			Process_Array[3] = 0;
			deadlock = 0;
		}
		for (int i = 0; i <= Process_Node_Num; i++) {
			if (i == 6)
				break_flag = 0;
			if (Process_Array[i] == 1) {
				deadlock++;
				break;
			}

		}
		if (break_flag == 0)
			break;

		/*
		Process 5
		*/
		for (process_0_request_resource_index = 0; process_0_request_resource_index < Resource_Node_Num; process_0_request_resource_index++) {
			if ((*chart).Process_To_Resource_Request_Edge[4][process_0_request_resource_index] == 1) {// j 是进程0正在申请的资源的数组下标
				break;
			}
		}
		resource_allocated = 0;
		for (int i = 0; i < Process_Node_Num; i++) {
			resource_allocated += (*chart).Resource_To_Process_Allocation_Edge[process_0_request_resource_index][i];
		}
		if ((*chart).Resource_Node_Array[process_0_request_resource_index] > resource_allocated) {//该资源类还有剩余的资源数 进程0可以完成
			//该进程结点可以释放 删除两个表里与其有关的
			for (int m = 0; m < Resource_Node_Num; m++) {
				(*chart).Resource_To_Process_Allocation_Edge[m][4] = 0;
			}
			for (int n = 0; n < Process_Node_Num; n++) {
				(*chart).Process_To_Resource_Request_Edge[4][n] = 0;
			}
			Process_Array[4] = 0;
			deadlock = 0;
		}
		for (int i = 0; i <= Process_Node_Num; i++) {
			if (i == 6)
				break_flag = 0;
			if (Process_Array[i] == 1) {
				deadlock++;
				break;
			}

		}
		if (break_flag == 0)
			break;

		/*
		Process 6
		*/
		for (process_0_request_resource_index = 0; process_0_request_resource_index < Resource_Node_Num; process_0_request_resource_index++) {
			if ((*chart).Process_To_Resource_Request_Edge[5][process_0_request_resource_index] == 1) {// j 是进程0正在申请的资源的数组下标
				break;
			}
		}
		resource_allocated = 0;
		for (int i = 0; i < Process_Node_Num; i++) {
			resource_allocated += (*chart).Resource_To_Process_Allocation_Edge[process_0_request_resource_index][i];
		}
		if ((*chart).Resource_Node_Array[process_0_request_resource_index] > resource_allocated) {//该资源类还有剩余的资源数 进程0可以完成
			//该进程结点可以释放 删除两个表里与其有关的
			for (int m = 0; m < Resource_Node_Num; m++) {
				(*chart).Resource_To_Process_Allocation_Edge[m][5] = 0;
			}
			for (int n = 0; n < Process_Node_Num; n++) {
				(*chart).Process_To_Resource_Request_Edge[5][n] = 0;
			}
			Process_Array[5] = 0;
			deadlock = 0;
		}
		for (int i = 0; i <= Process_Node_Num; i++) {
			if (i == 6)
				break_flag = 0;
			if (Process_Array[i] == 1) {
				deadlock++;
				break;
			}

		}
		if (break_flag == 0)
			break;
	}
}

