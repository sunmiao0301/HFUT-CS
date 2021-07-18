#pragma once
#include <iostream>
#include <highgui.hpp>
#include <core.hpp>
#include <cstring>

using namespace std;
using namespace cv;
class Rgb2Gray
{
public:
	//我设计的主类的目的 主要是为子类提供一个Mat img
	Mat img;
	Rgb2Gray();
	virtual ~Rgb2Gray();
};

