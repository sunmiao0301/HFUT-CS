#pragma once
#include <iostream>
#include <highgui.hpp>
#include <core.hpp>
#include <cstring>

using namespace std;
using namespace cv;
class Sharpening
{
public:
	Mat img;
	Mat img_temp;
	Sharpening();
	~Sharpening();
	void Sharpening_processing();
};

