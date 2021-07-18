#include "Smoothing.h"



Smoothing::Smoothing()
{
}


Smoothing::~Smoothing()
{
}

void Smoothing::Smoothing_processing(){
	int oper[3][3];//平滑算子 n = 3
	memset(oper, 0, sizeof(oper));//全部初始化为0
	for (int i = 0; i < img.rows; i++) {//第 i = 1 行开始
		for (int j = 0; j < img.cols; j++) {//i = 1 扫描所有 j 列 
			int temp = 0;//用来计算新的中心像素点值
			for (int k = 0; k < 3; k++) {//程序第一次运行时，算子开始扫，并且排除最边缘点
				for (int l = 0; l < 3; l++){
					if ((i - 1 + k < 0) || (j - 1 + l < 0) || (i - 1 + k >= img.rows) || (j - 1 + l >= img.cols))//当算子位于边缘区域时，排除图像中不存在的点
						continue;
					temp += (oper[k][l] + 1) *img.at<Vec3b>(i - 1 + k, j - 1 + l)[0];
				}
			}
			temp /= (3 * 3);//之所以放后面是因为1 / 9 的影响
			//将计算结果赋给dstimg中心像素点的三通道值
			for (int m = 0; m < 3; m++) {
				img_temp.at<Vec3b>(i, j)[m] = temp;
			}
		}
	}
}
