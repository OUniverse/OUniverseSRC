//Copyright 2015-2019, All Rights Reserved.

/**

## Thread

**Class:** ThreadC

No interface needed since std::thread is so straightforward.
Currently just a static function for detecting hardware max thread.


*/

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