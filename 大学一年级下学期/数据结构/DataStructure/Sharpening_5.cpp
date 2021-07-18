#include "Sharpening_5.h"



Sharpening_5::Sharpening_5()
{
}


Sharpening_5::~Sharpening_5()
{
}

void Sharpening_5::Sharpening_5_processing(){
	//由于n = 3 所以 x = 1
	int oper[5][5] = { { -1,-1,-1,-1,-1 },{ -1,-1,-1,-1,-1 },{ -1,-1,21,-1,-1 },{ -1,-1,-1,-1,-1 },{ -1,-1,-1,-1,-1 } };
	for (int i = 0; i < img.rows; i++) {//第 i = 1 行开始
		for (int j = 0; j < img.cols; j++) {//i = 1 扫描所有 j 列
			int temp = 0;//用来计算新的中心像素点值	
			for (int k = 0; k < 5; k++) {//程序第一次运行时，算子开始扫，并且排除最边缘点
				for (int l = 0; l < 5; l++) {
					if ((i - 2 + k < 0) || (j - 2 + l < 0) || (i - 2 + k >= img.rows) || (j - 2 + l >= img.cols))//当算子位于边缘区域时,不变，排除图像中不存在的点
						continue;
					temp += (oper[k][l]) * img.at<Vec3b>(i - 2 + k, j - 2 + l)[0];
				}
			}
			if (temp > 255) {
				temp = 255;
			}
			//当计算结果小于0，就把它置为0
			if (temp < 0) {
				temp = 0;
			}
			for (int m = 0; m < 3; m++) {
				img_temp.at<Vec3b>(i, j)[m] = temp;
			}
		}
	}
}
