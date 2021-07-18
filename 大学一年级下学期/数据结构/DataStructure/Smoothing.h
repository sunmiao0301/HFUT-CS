#pragma once
#include <iostream>
#include <highgui.hpp>
#include <core.hpp>
#include <cstring>
#include<algorithm>//

using namespace std;
using namespace cv;
class Smoothing
{
public:
	Mat img;
	Mat img_temp;
	Smoothing();
	~Smoothing();
	void Smoothing_processing();
};

