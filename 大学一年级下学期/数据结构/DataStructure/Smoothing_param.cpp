#include "Smoothing_param.h"



Smoothing_param::Smoothing_param()
{
}


Smoothing_param::~Smoothing_param()
{
}

void Smoothing_param::Smoothing_param_processing(int n) {
	int * oper;
	oper = new int[n * n]() ;
	int x = (n - 1) / 2;
	for (int i = 0; i < img.rows; i++) {//第 i = 1 行开始
		for (int j = 0; j < img.cols; j++) {//i = 1 扫描所有 j 列 
			int temp = 0;//用来计算新的中心像素点值
			for (int k = 0; k < n; k++) {//程序第一次运行时，算子开始扫，并且排除最边缘点
				for (int l = 0; l < n; l++) {
					if ((i - x + k < 0) || (j - x + l < 0) || (i - x + k >= img.rows) || (j - x + l >= img.cols))//当算子位于边缘区域时，排除图像中不存在的点
						continue;
					temp += (oper[k * n + l] + 1) *img.at<Vec3b>(i - x + k, j - x + l)[0];
				}
			}
			temp /= (n * n);//之所以放后面是因为1 / 9 的影响
							//将计算结果赋给dstimg中心像素点的三通道值
			for (int m = 0; m < 3; m++) {
				img_temp.at<Vec3b>(i, j)[m] = temp;
			}
		}
	}
	delete oper;
}