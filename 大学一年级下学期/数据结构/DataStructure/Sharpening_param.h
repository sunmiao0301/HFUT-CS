#pragma once
#include "Sharpening.h"
class Sharpening_param :
	public Sharpening
{
public:
	Sharpening_param();
	~Sharpening_param();
	void Sharpening_param_processing(int oper[3][3]);
};

