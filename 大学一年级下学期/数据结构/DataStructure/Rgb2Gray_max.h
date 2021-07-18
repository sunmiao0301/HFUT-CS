#pragma once
#include "Rgb2Gray.h"
class Rgb2Gray_max :
	public Rgb2Gray
{
public:
	Rgb2Gray_max();
	~Rgb2Gray_max();
	void Rgb2Gray_max_processing();
	int max(int a, int b) {
		if (a >= b)
			return a;
		return b;
	}
};

