//Copyright 2015-2019, All Rights Reserved.


#include <rapidjson/document.h>

#include "Interface/String.h"

struct JsonS
{
	rapidjson::Document J;

	JsonS(const char* JSerialized);

	StringC String(const char* Query);
	int Int(const char* Query);

};