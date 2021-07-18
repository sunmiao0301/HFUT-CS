#include "Roberts.h"



Roberts::Roberts()
{
}


Roberts::~Roberts() {
	
}

void Roberts::Roberts_processing(){
	int oper_y[2][2] = { { 0,-1 },{ 1,0 } };
	for (int i = 0; i < img.rows; i++) {//第 i = 1 行开始
		for (int j = 0; j < img.cols; j++) {//i = 1 扫描所有 j 列
			int temp = 0;//用来计算新的中心像素点值	
			for (int k = 0; k < 2; k++) {//程序第一次运行时，算子开始扫，并且排除最边缘点
				for (int l = 0; l < 2; l++) {
					if ((i + k < 0) || (j + l < 0) || (i + k >= img.rows) || (j + l >= img.cols))//当算子位于边缘区域时,不变，排除图像中不存在的点
						continue;
					temp += (oper_y[k][l]) * img.at<Vec3b>(i + k, j + l)[0];
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
				img_y.at<Vec3b>(i, j)[m] = temp;
			}
		}
	}

	int oper_x[2][2] = { { -1,0 },{ 0,1 } };
	for (int i = 0; i < img.rows; i++) {//第 i = 1 行开始
		for (int j = 0; j < img.cols; j++) {//i = 1 扫描所有 j 列
			int temp = 0;//用来计算新的中心像素点值	
			for (int k = 0; k < 2; k++) {//程序第一次运行时，算子开始扫，并且排除最边缘点
				for (int l = 0; l < 2; l++) {
					if ((i + k < 0) || (j + l < 0) || (i + k >= img.rows) || (j + l >= img.cols))//当算子位于边缘区域时,不变，排除图像中不存在的点
						continue;
					temp += (oper_x[k][l]) * img.at<Vec3b>(i + k, j + l)[0];
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
				img_x.at<Vec3b>(i, j)[m] = temp;
			}
		}
	}

	for (int i = 0; i < img.rows; i++) {//第 i = 1 行开始
		for (int j = 0; j < img.cols; j++) {//i = 1 扫描所有 j 列
			for (int m = 0; m < 3; m++) {
				img_temp.at<Vec3b>(i, j)[m] = max(img_x.at<Vec3b>(i, j)[0], img_y.at<Vec3b>(i, j)[0]);
			}
		}
	}
}
