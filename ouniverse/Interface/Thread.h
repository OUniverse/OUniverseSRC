//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include <thread>

class ThreadC
{

public:

	static int ThreadMax()
	{
		return std::thread::hardware_concurrency();
	}

};