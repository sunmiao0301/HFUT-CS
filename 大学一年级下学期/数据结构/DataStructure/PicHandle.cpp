#include <iostream>
#include <highgui.hpp>
#include <core.hpp>
//#include <cv.hpp>
#include <cstring>

using namespace std;
using namespace cv;

class PicHandle {
public:
	Mat img;
	Mat dstimg;// = img.clone();//存储用
	PicHandle();//无参构造函数
	~PicHandle();
	void colorToGray(Mat img);//彩色图像转化为灰度图像
	void avrSmooth();//邻域平均法
	void Sharpen();//算子锐化
						  //void smooth_5();//平滑5x5
						  //void smooth_3();//平滑3x3
						  //void midSmooth(int n);//中值滤波法
	
	void colorToGray_Max(Mat img);
	void colorToGray_Best(Mat img);
	void Smooth_5();
	void midSmooth();

	void Sharpen_5();
	void Sharpen_3();
	int max(int a,int b){
	(a > b) || (a = b);
	return a;
	}

	//下面为选做部分的函数

	//void roberts();//roberts算子

	void prewitt_x();//水平prewitt
	void prewitt_y();//垂直prewitt
};

PicHandle::PicHandle()
{
}

PicHandle::~PicHandle() 
{
}
/*
* img.at<Vec3b>(i, j)[0]的作用是读出图片（i，j）点的第0个通道的值
*/
void PicHandle::colorToGray(Mat img) {
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			int sum = img.at<Vec3b>(i, j)[0] + img.at<Vec3b>(i, j)[1] + img.at<Vec3b>(i, j)[2];
			sum /= 3;
			for (int k = 0; k < 3; k++) {
				img.at<Vec3b>(i, j)[k] = sum;
			}
		}
	}
}

void PicHandle::colorToGray_Max(Mat img) {
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {

			
				//return maxnum;//返回最大值下标
			int sum = max(max(img.at<Vec3b>(i, j)[0] , img.at<Vec3b>(i, j)[1] ), img.at<Vec3b>(i, j)[2]);
			//sum /= 3;
			for (int k = 0; k < 3; k++) {
				img.at<Vec3b>(i, j)[k] = sum;
			}
		}
	}
}

void PicHandle::colorToGray_Best(Mat img) {
		for (int i = 0; i < img.rows; i++) {
			for (int j = 0; j < img.cols; j++) {
				int sum = img.at<Vec3b>(i, j)[0]*0.30 + img.at<Vec3b>(i, j)[1]*0.59 + img.at<Vec3b>(i, j)[2]*0.11;
				for (int k = 0; k < 3; k++) {
					img.at<Vec3b>(i, j)[k] = sum;
				}
			}
		}
	}

void PicHandle::avrSmooth() {
	const int n = 3;//注意n需为奇数
	int x = 1;//n = 3时x = 1
	int oper[3][3];//平滑算子 n = 3
	memset(oper, 0, sizeof(oper));//全部初始化为0
	for (int i = 0; i < img.rows; i++) {//第 i = 1 行开始
		for (int j = 0; j < img.cols; j++) {//i = 1 扫描所有 j 列 
			int temp = 0;//用来计算新的中心像素点值

						 //程序第一次运行时，算子开始扫，并且排除最边缘点
			for (int k = 0; k < n; k++) {
				for (int l = 0; l < n; l++)
				{
					//当算子位于边缘区域时，排除图像中不存在的点
					if ((i - x + k < 0) || (j - x + l < 0) || (i - x + k >= img.rows) || (j - x + l >= img.cols))
						//continue使直到
						continue;
					//
					temp += (oper[k][l] + 1) *img.at<Vec3b>(i - x + k, j - x + l)[0];

				}
			}

			temp /= (n*n);
			//将计算结果赋给dstimg中心像素点的三通道值
			for (int m = 0; m < 3; m++) {
				img.at<Vec3b>(i, j)[m] = temp;
			}
		}
	}
}

void PicHandle::Sharpen() {
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			int temp = 0;//用来计算新的中心像素点值
			int oper[3][3] = { { -1,-1,-1 },{ -1,9,-1 },{ -1,-1,-1 } };//锐化
			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 3; l++) {
					//当算子位于边缘区域时，排除图像中不存在的点
					if ((i - 1 + k < 0) || (j - 1 + l < 0) || (i - 1 + k >= img.rows) || (j - 1 + l >= img.cols))
						continue;
					temp += oper[k][l] * img.at<Vec3b>(i - 1 + k, j - 1 + l)[0];
				}
			}
			//当计算结果超出255，就把它置为255
			if (temp > 255) {
				temp = 255;
			}
			//当计算结果小于0，就把它置为0
			if (temp < 0) {
				temp = 0;
			}
			//将计算结果赋给中心像素点的三通道值
			for (int m = 0; m < 3; m++) {
				img.at<Vec3b>(i, j)[m] = temp;
			}
		}
	}
}

void PicHandle::Sharpen_5() {
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			int temp = 0;//用来计算新的中心像素点值
			int oper[5][5] = { { -1,-1,-1,-1,-1 },{ -1,-1,-1,-1,-1 },{ -1,-1,9,-1 ,-1},{ -1,-1,-1,-1,-1 },{ -1,-1,-1,-1,-1 } };//锐化
			for (int k = 0; k < 5; k++) {
				for (int l = 0; l < 5; l++) {
					//当算子位于边缘区域时，排除图像中不存在的点
					if ((i - 2 + k < 0) || (j - 2 + l < 0) || (i - 2 + k >= img.rows) || (j - 2 + l >= img.cols))
						continue;
					temp += oper[k][l] * img.at<Vec3b>(i - 2 + k, j - 2 + l)[0];
				}
			}
			//当计算结果超出255，就把它置为255
			if (temp > 255) {
				temp = 255;
			}
			//当计算结果小于0，就把它置为0
			if (temp < 0) {
				temp = 0;
			}
			//将计算结果赋给中心像素点的三通道值
			for (int m = 0; m < 3; m++) {
				dstimg.at<Vec3b>(i, j)[m] = temp;
			}
		}
	}
}

void PicHandle::Sharpen_3(){
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			int temp = 0;//用来计算新的中心像素点值
			int oper[3][3] = { { -2,-2,-2 },{ -2,18,-2},{ -2 ,-2 ,-2 } };//锐化
			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 3; l++) {
					//当算子位于边缘区域时，排除图像中不存在的点
					if ((i - 1 + k < 0) || (j - 1 + l < 0) || (i - 1 + k >= img.rows) || (j - 1 + l >= img.cols))
						continue;
					temp += oper[k][l] * img.at<Vec3b>(i - 1 + k, j - 1 + l)[0];
				}
			}
			//当计算结果超出255，就把它置为255
			if (temp > 255) {
				temp = 255;
			}
			//当计算结果小于0，就把它置为0
			if (temp < 0) {
				temp = 0;
			}
			//将计算结果赋给中心像素点的三通道值
			for (int m = 0; m < 3; m++) {
				dstimg.at<Vec3b>(i, j)[m] = temp;
			}
		}
	}
}

void PicHandle::Smooth_5() {
	const int n = 5;//注意n需为奇数
	int x = 2;//n = 3时x = 1

	int oper[5][5];//平滑算子 n = 3
	memset(oper, 0, sizeof(oper));//全部初始化为0
	for (int i = 0; i < img.rows; i++) {//第 i = 1 行开始
		for (int j = 0; j < img.cols; j++) {//i = 1 扫描所有 j 列 
			int temp = 0;//用来计算新的中心像素点值

						 //程序第一次运行时，算子开始扫，并且排除最边缘点
			for (int k = 0; k < n; k++) {
				for (int l = 0; l < n; l++)
				{
					//当算子位于边缘区域时，排除图像中不存在的点
					if ((i - x + k < 0) || (j - x + l < 0) || (i - x + k >= img.rows) || (j - x + l >= img.cols))
						//continue使直到
						continue;
					//
					temp += (oper[k][l] + 1) *img.at<Vec3b>(i - x + k, j - x + l)[0];
				}
			}

			temp /= (n*n);
			//将计算结果赋给中心像素点的三通道值
			for (int m = 0; m < 3; m++) {
				dstimg.at<Vec3b>(i, j)[m] = temp;
			}
		}
	}
}

void PicHandle::midSmooth(){ 
int n = 3;
int oper[9];//用来存放模板对应的9个像素点的值
	memset(oper, 0, sizeof(oper));//初始化为0
	int x = 1;
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			int count = 0;//标记共有多少个合法点
			for (int k = 0; k < n; k++) {
				for (int l = 0; l < n; l++) {
					//当算子位于边缘区域时，排除图像中不存在的点
					if ((i - x + k < 0) || (j - x + l < 0) || (i - x + k >= img.rows) || (j - x + l >= img.cols))
						continue;
					oper[count] = img.at<Vec3b>(i - x + k, j - x + l)[0];
					count++;
				}
			}
			//将temp数组中的像素值从小到大排序
			for (int p = 0; p < count; p++) {
				for (int q = count - 1; q > p; q--) {
					if (oper[q] < oper[q - 1]) {
						swap(oper[q], oper[q - 1]);
					}
				}
			}

			//将temp数组的中值赋给中心像素点的三通道
			for (int m = 0; m < 3; m++) {
				dstimg.at<Vec3b>(i, j)[m] = oper[count / 2 + 1];
			}
		}
	}
}

void PicHandle::prewitt_x() {
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			int temp = 0;//用来计算新的中心像素点值
			int oper[3][3] = { { -1,0,1 },{ -1,0,1 },{ -1,0,1 } };//prewitt_x
			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 3; l++) {
					//当算子位于边缘区域时，排除图像中不存在的点
					if ((i - 1 + k < 0) || (j - 1 + l < 0) || (i - 1 + k >= img.rows) || (j - 1 + l >= img.cols))
						continue;
					temp += oper[k][l] * img.at<Vec3b>(i - 1 + k, j - 1 + l)[0];
				}
			}
			//当计算结果超出255，就把它置为255
			if (temp > 255) {
				temp = 255;
			}
			//当计算结果小于0，就把它置为0
			if (temp < 0) {
				temp = 0;
			}
			//将计算结果赋给中心像素点的三通道值
			for (int m = 0; m < 3; m++) {
				dstimg.at<Vec3b>(i, j)[m] = temp;
			}
		}
	}
}

void PicHandle::prewitt_y() {
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			int temp = 0;//用来计算新的中心像素点值
			int oper[3][3] = { { -1,-1,-1 },{ 0,0,0 },{ 1,1,1} };//
			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 3; l++) {
					//当算子位于边缘区域时，排除图像中不存在的点
					if ((i - 1 + k < 0) || (j - 1 + l < 0) || (i - 1 + k >= img.rows) || (j - 1 + l >= img.cols))
						continue;
					temp += oper[k][l] * img.at<Vec3b>(i - 1 + k, j - 1 + l)[0];
				}
			}
			//当计算结果超出255，就把它置为255
			if (temp > 255) {
				temp = 255;
			}
			//当计算结果小于0，就把它置为0
			if (temp < 0) {
				temp = 0;
			}
			//将计算结果赋给中心像素点的三通道值
			for (int m = 0; m < 3; m++) {
				dstimg.at<Vec3b>(i, j)[m] = temp;
			}
		}
	}
}

/*void PicHandle::roberts()
{
	//cv::Mat dstImage = srcImage.clone();
	//int nRows = dstImage.rows;
	//int nCols = dstImage.cols;
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			int t1 = (img.at<Vec3b>(i, j) - img.at<Vec3b>(i + 1, j + 1)) * (img.at<Vec3b>(i, j) - img.at<Vec3b>(i + 1, j + 1));
			int t2 = (img.at<Vec3b>(i + 1, j) - img.at<Vec3b>(i, j + 1)) * (img.at<Vec3b>(i + 1, j) - img.at<Vec3b>(i, j + 1));
			int temp = sqrt(t1 + t2);
			for (int m = 0; m < 3; m++) {
				img.at<Vec3b>(i, j)[m] = temp;
			}
		}
	}
	//return dstImage;
}*/

int main(int argc, char** argv)
{
	String filename = "D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\模糊.jpg";
	String filename_Gray = "D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\模糊_gray.jpg";
	String filename_Smooth = "D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\模糊_smooth.jpg";
	String filename_Sharpen = "D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\模糊_sharpen.jpg";

	String filename_Gray_Max = "D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\模糊_gray_Max.jpg";
	String filename_Gray_Best = "D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\模糊_gray_Best.jpg";

	String filename_smooth_5 = "D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\模糊_smooth_5.jpg";
	String filename_midSmooth = "D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\模糊_smooth_mid.jpg";

	String filename_Sharpen_5 = "D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\模糊_sharpen_5.jpg";
	String filename_Sharpen_3 = "D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\模糊_sharpen_3.jpg";


	String filename_prewitt_x = "D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\模糊_prewitt_x.jpg";
	String filename_prewitt_y = "D:\\大学作业\\3 下\\课程课程\\数据结构课程设计\\模糊_prewitt_y.jpg";
	//灰度
	PicHandle Gray;
	Gray.img = imread(filename, IMREAD_COLOR); // Read the file
	Gray.colorToGray(Gray.img);
	imwrite(filename_Gray, Gray.img);//

	//平滑
	PicHandle Smooth;
	Smooth.img =  imread(filename, IMREAD_COLOR); // Read the file
	Smooth.colorToGray(Smooth.img);
	Smooth.colorToGray(Smooth.dstimg);
	Smooth.avrSmooth();
	imwrite(filename_Smooth, Smooth.dstimg);//
	

	//锐化
	PicHandle Sharpen;
	Sharpen.img = imread(filename, IMREAD_COLOR); // Read the file
	Sharpen.colorToGray(Sharpen.img);//灰度
	Sharpen.Sharpen();//锐化操作
	imwrite(filename_Sharpen, Sharpen.dstimg);//

	//最大值灰度
	PicHandle Gray_Max;
	Gray_Max.img = imread(filename, IMREAD_COLOR); // Read the file
	Gray_Max.colorToGray_Max(Gray_Max.img);
	imwrite(filename_Gray_Max, Gray_Max.dstimg);//

    //加权平均灰度
	PicHandle Gray_Best;
	Gray_Best.img = imread(filename, IMREAD_COLOR); // Read the file
	Gray_Best.colorToGray_Best(Gray_Best.img);
	imwrite(filename_Gray_Best, Gray_Best.dstimg);//

	//5*5平滑
	PicHandle smooth_5;
	smooth_5.img = imread(filename, IMREAD_COLOR); // Read the file
	smooth_5.colorToGray(smooth_5.img);//灰度
	smooth_5.Smooth_5();//5*5平滑
	imwrite(filename_smooth_5, smooth_5.dstimg);//
	
	//中值平滑
	PicHandle midSmooth;
	midSmooth.img = imread(filename, IMREAD_COLOR); // Read the file
	midSmooth.colorToGray(midSmooth.img);//灰度
	midSmooth.midSmooth();//5*5平滑
	imwrite(filename_midSmooth, midSmooth.dstimg);//

    //5*5锐化
	PicHandle Sharpen_5;
	Sharpen_5.img = imread(filename, IMREAD_COLOR); // Read the file
	Sharpen_5.colorToGray(Sharpen_5.img);//灰度
	Sharpen_5.Sharpen_5();//锐化操作
	imwrite(filename_Sharpen_5, Sharpen_5.dstimg);//

	//对算子内部值加倍后的3*3锐化
	PicHandle Sharpen_3;
	Sharpen_3.img = imread(filename, IMREAD_COLOR); // Read the file
	Sharpen_3.colorToGray(Sharpen_3.img);//灰度
	Sharpen_3.Sharpen_3();//锐化操作
	imwrite(filename_Sharpen_3, Sharpen_3.dstimg);//

	//下面为选做部分相关代码

	//拉普拉斯算子模板
	
	PicHandle prewitt_x;
	prewitt_x.img = imread(filename, IMREAD_COLOR); // Read the file
	prewitt_x.colorToGray(prewitt_x.img);//灰度
	prewitt_x.prewitt_x();//锐化操作
	imwrite(filename_prewitt_x, prewitt_x.dstimg);//

	//离散拉普拉斯算子模板
	
	PicHandle prewitt_y;
	prewitt_y.img = imread(filename, IMREAD_COLOR); // Read the file
	prewitt_y.colorToGray(prewitt_y.img);//灰度
	prewitt_y.prewitt_y();//锐化操作
	imwrite(filename_prewitt_y, prewitt_y.dstimg);//
	
	waitKey(10000); // Wait for a keystroke in the window
	return 0;
}


	