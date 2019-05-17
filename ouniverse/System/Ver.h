//Copyright 2015-2019, All Rights Reserved.

/**

## Version
Static constant access to version information of the program.

> Will most likely require access functions to pull versioning info from the UI and from UE4.

 */

#include "CoreMinimal.h"

#pragma once

class OUNIVERSE_API Version
{

public:

	static int Iterator = 0;
	static int Dev = 0;
	static int Arch = 0;
	static int Phase = 0;
	static FString Readable = "1.0";
};
