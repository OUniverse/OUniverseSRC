//Copyright 2015-2019, All Rights Reserved.

#include "CoreMinimal.h"

class FJsonObject;

class JsonUtil
{

public:

	//Isolates the file extension from a file name.
	static FString SerializeJson(TSharedPtr<FJsonObject> Json);

};

