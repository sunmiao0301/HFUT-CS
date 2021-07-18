#include "Rgb2Gray_weighting.h"



Rgb2Gray_weighting::Rgb2Gray_weighting()
{
}


Rgb2Gray_weighting::~Rgb2Gray_weighting()
{
}

void Rgb2Gray_weighting::Rgb2Gray_weighting_processing(){
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			for (int k = 0; k < 3; k++) {
				img.at<Vec3b>(i, j)[k] = img.at<Vec3b>(i, j)[0] * 0.30 + img.at<Vec3b>(i, j)[1] * 0.59 + img.at<Vec3b>(i, j)[2] * 0.11;
			}
		}
	}
}
