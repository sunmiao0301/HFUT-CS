#include <iostream>
#include <highgui.hpp>
#include <core.hpp>
#include <cstring>
#include "Rgb2Gray.h"
#include "Rgb2Gray_avr.h"
#include "Rgb2Gray_max.h"
#include "Rgb2Gray_weighting.h"
#include "Smoothing.h"
#include "Sharpening.h"
#include "Smoothing_5.h"
#include "Sharpening_5.h"
#include "Sharpening_double.h"

#include "Rgb2Gray_param.h"
#include "Sharpening_param.h"
#include "Smoothing_param.h"

#include "Smoothing_mid.h"
#include "Smoothing_Gauss_3.h"
#include "Smoothing_Gauss_5.h"

#include "Prewitt.h"
#include "Sobel.h"
#include "Roberts.h"

using namespace std;
using namespace cv;
int main(int argc, char** argv)
{
	String filename = "D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\Lenna.jpg";

	//平均值灰度图
	String filename_Rgb2Gray_avr = "D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\Rgb2Gray_avr.jpg";
	Rgb2Gray_avr rgb2Gray_avr;//创建类的对象
	rgb2Gray_avr.img = imread(filename, IMREAD_COLOR);//将类的img属性读取到值
	rgb2Gray_avr.Rgb2Gray_avr_processing();//对img处理——平均值灰度值
	imwrite(filename_Rgb2Gray_avr, rgb2Gray_avr.img);//将img读出 到"D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\Lenna_Rgb2Gray_avr.jpg"中存着


	//最大值得到灰度
	String filename_Rgb2Gray_max = "D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\Rgb2Gray_max.jpg";
	Rgb2Gray_max rgb2Gray_max;
	rgb2Gray_max.img = imread(filename, IMREAD_COLOR);
	rgb2Gray_max.Rgb2Gray_max_processing();
	imwrite(filename_Rgb2Gray_max, rgb2Gray_max.img);

	//加权法得到灰度
	String filename_Rgb2Gray_weighting = "D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\Rgb2Gray_weighting.jpg";
	Rgb2Gray_weighting rgb2Gray_weighting;
	rgb2Gray_weighting.img = imread(filename, IMREAD_COLOR);
	rgb2Gray_weighting.Rgb2Gray_weighting_processing();
	imwrite(filename_Rgb2Gray_weighting, rgb2Gray_weighting.img);

	/*
	考虑到加权灰度法得到的结果比较好 我们后续都使用加权法得到的灰度图进行后续实验
	*/

	/*
	平滑
	1/9 1/9 1/9
	1/9 1/9 1/9
	1/9 1/9 1/9
	*/
	String filename_Smoothing = "D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\Smoothing.jpg";
	Smoothing smoothing;
	smoothing.img = imread(filename_Rgb2Gray_weighting, IMREAD_COLOR);
	smoothing.img_temp = imread(filename_Rgb2Gray_weighting, IMREAD_COLOR);
	smoothing.Smoothing_processing();
	imwrite(filename_Smoothing, smoothing.img_temp);

	/*
	锐化
	-1 -1 -1
	-1  9 -1
	-1 -1 -1
	*/
	String filename_Sharpening = "D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\Sharpening.jpg";
	Sharpening sharpening;
	sharpening.img = imread(filename_Rgb2Gray_weighting, IMREAD_COLOR);
	sharpening.img_temp = imread(filename_Rgb2Gray_weighting, IMREAD_COLOR);
	sharpening.Sharpening_processing();
	imwrite(filename_Sharpening, sharpening.img_temp);

	/*
	平滑 5
	1/25 1/25 1/25 1/25 1/25
	1/25 1/25 1/25 1/25 1/25
	1/25 1/25 1/25 1/25 1/25
	1/25 1/25 1/25 1/25 1/25
	1/25 1/25 1/25 1/25 1/25
	*/
	String filename_Smoothing_5 = "D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\Smoothing_5.jpg";
	Smoothing_5 smoothing_5;
	smoothing_5.img = imread(filename_Rgb2Gray_weighting, IMREAD_COLOR);
	smoothing_5.img_temp = imread(filename_Rgb2Gray_weighting, IMREAD_COLOR);
	smoothing_5.Smoothing_5_processing();
	imwrite(filename_Smoothing_5, smoothing_5.img_temp);

	/*
	锐化 5 尝试在 23 时候效果最好
	-1 -1 -1 -1 -1
	-1 -1 -1 -1 -1
	-1 -1 23 -1 -1
	-1 -1 -1 -1 -1
	-1 -1 -1 -1 -1
	*/
	String filename_Sharpening_5 = "D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\Sharpening_5.jpg";
	Sharpening_5 sharpening_5;
	sharpening_5.img = imread(filename_Rgb2Gray_weighting, IMREAD_COLOR);
	sharpening_5.img_temp = imread(filename_Rgb2Gray_weighting, IMREAD_COLOR);
	sharpening_5.Sharpening_5_processing();
	imwrite(filename_Sharpening_5, sharpening_5.img_temp);

	/*
	锐化 double
	-2 -2 -2
	-2 18 -2
	-2 -2 -2
	*/
	String filename_Sharpening_double = "D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\Sharpening_double.jpg";
	Sharpening_double sharpening_double;
	sharpening_double.img = imread(filename_Rgb2Gray_weighting, IMREAD_COLOR);
	sharpening_double.img_temp = imread(filename_Rgb2Gray_weighting, IMREAD_COLOR);
	sharpening_double.Sharpening_double_processing();
	imwrite(filename_Sharpening_double, sharpening_double.img_temp);

	//参数灰度 
	String filename_Rgb2Gray_param = "D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\Rgb2Gray_param.jpg";
	Rgb2Gray_param rgb2Gray_param;
	rgb2Gray_param.img = imread(filename, IMREAD_COLOR);
	rgb2Gray_param.Rgb2Gray_param_processing("max");//此处参数可选：avr max weight valid_input等
	imwrite(filename_Rgb2Gray_param, rgb2Gray_param.img);

	//参数锐化
	String filename_Sharpening_param = "D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\Sharpening_param.jpg";
	Sharpening_param sharpening_param;
	sharpening_param.img = imread(filename_Rgb2Gray_weighting, IMREAD_COLOR);
	sharpening_param.img_temp = imread(filename_Rgb2Gray_weighting, IMREAD_COLOR);
	int oper[3][3] = { { -1,-1,-1 },{ -1,9,-1 },{ -1,-1,-1 } };
	sharpening_param.Sharpening_param_processing(oper);
	imwrite(filename_Sharpening_param, sharpening_param.img_temp);

	//参数平滑
	String filename_Smoothing_param = "D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\Smoothing_param.jpg";
	Smoothing_param smoothing_param;
	smoothing_param.img = imread(filename_Rgb2Gray_weighting, IMREAD_COLOR);
	smoothing_param.img_temp = imread(filename_Rgb2Gray_weighting, IMREAD_COLOR);
	smoothing_param.Smoothing_param_processing(3);
	imwrite(filename_Smoothing_param, smoothing_param.img_temp);

	//以下为选做部分代码
	//中值平滑
	String filename_Smoothing_mid = "D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\Smoothing_mid.jpg";
	Smoothing_mid smoothing_mid;
	smoothing_mid.img = imread(filename_Rgb2Gray_weighting, IMREAD_COLOR);
	smoothing_mid.img_temp = imread(filename_Rgb2Gray_weighting, IMREAD_COLOR);
	smoothing_mid.Smoothing_mid_processing();
	imwrite(filename_Smoothing_mid, smoothing_mid.img_temp);

	//Gauss_3平滑
	String filename_Smoothing_Gauss_3 = "D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\Smoothing_Gauss_3.jpg";
	Smoothing_Gauss_3 smoothing_Gauss_3;
	smoothing_Gauss_3.img = imread(filename_Rgb2Gray_weighting, IMREAD_COLOR);
	smoothing_Gauss_3.img_temp = imread(filename_Rgb2Gray_weighting, IMREAD_COLOR);
	smoothing_Gauss_3.Smoothing_Gauss_3_processing();
	imwrite(filename_Smoothing_Gauss_3, smoothing_Gauss_3.img_temp);

	//Gauss_5平滑
	String filename_Smoothing_Gauss_5 = "D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\Smoothing_Gauss_5.jpg";
	Smoothing_Gauss_5 smoothing_Gauss_5;
	smoothing_Gauss_5.img = imread(filename_Rgb2Gray_weighting, IMREAD_COLOR);
	smoothing_Gauss_5.img_temp = imread(filename_Rgb2Gray_weighting, IMREAD_COLOR);
	smoothing_Gauss_5.Smoothing_Gauss_5_processing();
	imwrite(filename_Smoothing_Gauss_5, smoothing_Gauss_5.img_temp);

	//prewitt
	String filename_Prewitt = "D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\Prewitt.jpg";
	String filename_Prewitt_x = "D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\Prewitt_x.jpg";
	String filename_Prewitt_y = "D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\Prewitt_y.jpg";
	Prewitt prewitt;
	prewitt.img = imread(filename_Rgb2Gray_weighting, IMREAD_COLOR);
	prewitt.img_temp = imread(filename_Rgb2Gray_weighting, IMREAD_COLOR);
	prewitt.img_x = imread(filename_Rgb2Gray_weighting, IMREAD_COLOR);
	prewitt.img_y = imread(filename_Rgb2Gray_weighting, IMREAD_COLOR);
	prewitt.Prewitt_processing();
	imwrite(filename_Prewitt, prewitt.img_temp);
	imwrite(filename_Prewitt_x, prewitt.img_x);
	imwrite(filename_Prewitt_y, prewitt.img_y);


	//sobel
	String filename_Sobel = "D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\Sobel.jpg";
	String filename_Sobel_x = "D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\Sobel_x.jpg";
	String filename_Sobel_y = "D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\Sobel_y.jpg";
	Sobel sobel;
	sobel.img = imread(filename_Rgb2Gray_weighting, IMREAD_COLOR);
	sobel.img_temp = imread(filename_Rgb2Gray_weighting, IMREAD_COLOR);
	sobel.img_x = imread(filename_Rgb2Gray_weighting, IMREAD_COLOR);
	sobel.img_y = imread(filename_Rgb2Gray_weighting, IMREAD_COLOR);
	sobel.Sobel_processing();
	imwrite(filename_Sobel, sobel.img_temp);
	imwrite(filename_Sobel_x, sobel.img_x);
	imwrite(filename_Sobel_y, sobel.img_y);

	//roberts
	String filename_Roberts = "D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\Roberts.jpg";
	String filename_Roberts_x = "D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\Roberts_x.jpg";
	String filename_Roberts_y = "D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\Roberts_y.jpg";
	Roberts roberts;
	roberts.img = imread(filename_Rgb2Gray_weighting, IMREAD_COLOR);
	roberts.img_temp = imread(filename_Rgb2Gray_weighting, IMREAD_COLOR);
	roberts.img_x = imread(filename_Rgb2Gray_weighting, IMREAD_COLOR);
	roberts.img_y = imread(filename_Rgb2Gray_weighting, IMREAD_COLOR);
	roberts.Roberts_processing();
	imwrite(filename_Roberts, roberts.img_temp);
	imwrite(filename_Roberts_x, roberts.img_x);
	imwrite(filename_Roberts_y, roberts.img_y);
	waitKey(10000); // Wait for a keystroke in the window
	return 0;
}
