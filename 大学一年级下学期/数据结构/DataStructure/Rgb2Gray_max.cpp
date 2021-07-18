#include "Rgb2Gray_max.h"



Rgb2Gray_max::Rgb2Gray_max()
{
}


Rgb2Gray_max::~Rgb2Gray_max()
{
}

void Rgb2Gray_max::Rgb2Gray_max_processing(){
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			for (int k = 0; k < 3; k++) {
				img.at<Vec3b>(i, j)[k] = max(max(img.at<Vec3b>(i, j)[0], img.at<Vec3b>(i, j)[1]), img.at<Vec3b>(i, j)[2]);
			}
		}
	}
}
