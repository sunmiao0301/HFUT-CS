#pragma once
#include "Smoothing.h"
class Smoothing_param :
	public Smoothing
{
public:
	Smoothing_param();
	~Smoothing_param();
	void Smoothing_param_processing(int n);
};

