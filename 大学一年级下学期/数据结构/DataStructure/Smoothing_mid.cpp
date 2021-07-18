#include "Smoothing_mid.h"



Smoothing_mid::Smoothing_mid()
{
}


Smoothing_mid::~Smoothing_mid()
{
}

void Smoothing_mid::Smoothing_mid_processing(){
	int oper[9];//用来存放模板对应的9个像素点的值
	memset(oper, 0, sizeof(oper));//初始化为0
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			int count = 0;//标记共有多少个合法点
			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 3; l++) {
					//当算子位于边缘区域时，排除图像中不存在的点
					if ((i - 1 + k < 0) || (j - 1 + l < 0) || (i - 1 + k >= img.rows) || (j - 1 + l >= img.cols))
						continue;
					oper[count] = img.at<Vec3b>(i - 1 + k, j - 1 + l)[0];
					count++;
				}
			}
			//将temp数组中的像素值从小到大排序
			sort(oper, oper + count);
			//将temp数组的中值赋给中心像素点的三通道
			for (int m = 0; m < 3; m++) {
				img_temp.at<Vec3b>(i, j)[m] = oper[(count - 1) / 2];//求得中位数
			}
		}
	}
}
