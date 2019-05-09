//Copyright 2015-2019, All Rights Reserved.

#include "CoreMinimal.h"
#include <rapidjson/document.h>

struct JsonS
{
	rapidjson::Document J;

	JsonS(const char* JSerialized);

	FString String(const char* Query);
	FString operator&(const char* Query);
	int Int(const char* Query);
	int operator%(const char* Query);
};