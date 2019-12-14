//Copyright 2015-2019, All Rights Reserved.



#pragma once

#include "UObject/NoExportTypes.h"
#include "Interface/Url.h"
#include "Interface/Map.h"
#include "Interface/String.h"


class OUNIVERSE_API BabelC
{

public:

	BabelC(FileC BabelDoc);

	FText Decode(int InCode);

	static BabelC* Get();

	static BabelC* Create(FileC BabelDoc);
	
	MapC<int, FString> Lib_;
};