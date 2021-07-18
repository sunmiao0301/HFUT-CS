#include "Smoothing_5.h"



Smoothing_5::Smoothing_5()
{
}


Smoothing_5::~Smoothing_5()
{
}

void Smoothing_5::Smoothing_5_processing(){
	int oper[5][5];//平滑算子 n = 3
	memset(oper, 0, sizeof(oper));//全部初始化为0
	for (int i = 0; i < img.rows; i++) {//第 i = 1 行开始
		for (int j = 0; j < img.cols; j++) {//i = 1 扫描所有 j 列 
			int temp = 0;//用来计算新的中心像素点值
			for (int k = 0; k < 5; k++) {//程序第一次运行时，算子开始扫，并且排除最边缘点
				for (int l = 0; l < 5; l++) {
					if ((i - 2 + k < 0) || (j - 2 + l < 0) || (i - 2 + k >= img.rows) || (j - 2 + l >= img.cols))//当算子位于边缘区域时，排除图像中不存在的点
						continue;
					temp += (oper[k][l] + 1) *img.at<Vec3b>(i - 2 + k, j - 2 + l)[0];
				}
			}
			temp /= (5 * 5);//之所以放后面是因为1 / 9 的影响
							//将计算结果赋给dstimg中心像素点的三通道值
			for (int m = 0; m < 3; m++) {
				img_temp.at<Vec3b>(i, j)[m] = temp;
			}
		}
	}
}
