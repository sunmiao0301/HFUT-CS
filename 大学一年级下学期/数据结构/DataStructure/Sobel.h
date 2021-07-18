#pragma once
#include <iostream>
#include <highgui.hpp>
#include <core.hpp>
#include <cstring>

using namespace std;
using namespace cv;
class Sobel
{
public:
	Mat img;
	Mat img_temp;
	Mat img_x;
	Mat img_y;
	Sobel();
	~Sobel();
	void Sobel_processing();
	int max(int a, int b) {
		if (a >= b)
			return a;
		return b;
	}
};
