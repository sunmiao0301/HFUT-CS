#include "Rgb2Gray_param.h"



Rgb2Gray_param::Rgb2Gray_param()
{
}


Rgb2Gray_param::~Rgb2Gray_param()
{
}

void Rgb2Gray_param::Rgb2Gray_param_processing(String way){
	if (way.compare("avr") == 0) {
		for (int i = 0; i < img.rows; i++) {
			for (int j = 0; j < img.cols; j++) {
				for (int k = 0; k < 3; k++) {
					img.at<Vec3b>(i, j)[k] = (img.at<Vec3b>(i, j)[0] + img.at<Vec3b>(i, j)[1] + img.at<Vec3b>(i, j)[2]) / 3;
				}
			}
		}
	}
	else if (way.compare("max") == 0) {
		for (int i = 0; i < img.rows; i++) {
			for (int j = 0; j < img.cols; j++) {
				for (int k = 0; k < 3; k++) {
					img.at<Vec3b>(i, j)[k] = max(max(img.at<Vec3b>(i, j)[0], img.at<Vec3b>(i, j)[1]), img.at<Vec3b>(i, j)[2]);
				}
			}
		}
	}
	else if (way.compare("weighting") == 0) {
		for (int i = 0; i < img.rows; i++) {
			for (int j = 0; j < img.cols; j++) {
				for (int k = 0; k < 3; k++) {
					img.at<Vec3b>(i, j)[k] = img.at<Vec3b>(i, j)[0] * 0.30 + img.at<Vec3b>(i, j)[1] * 0.59 + img.at<Vec3b>(i, j)[2] * 0.11;
				}
			}
		}
	}
	else {
		cout << "wrong input param";
	}
}
