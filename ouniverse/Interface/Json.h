//Copyright 2015-2019, All Rights Reserved.

/**

## Json

**Struct:**  JsonS

Json read-only interface which is a wrapper around rapidjson

*/

#pragma once

#include <rapidjson/document.h>
#include "Interface/String.h"
#include "Interface/Int.h"

typedef rapidjson::Value::Array JsonArray;


struct JsonS
{
	rapidjson::Document J;

	JsonS(const char* JSerialized);
	JsonS(StringC JSerialized);
	JsonS(JsonArray in);

	JsonArray Array(const char* Query);

	StringC String(const char* Query);

	int Int(const char* Query);
	UInt8  ToUInt8(const char* Query);
	UInt16 ToUInt16(const char* Query);
	UInt32 ToUInt32(const char* Query);
	UInt64 ToUInt64(const char* Query);

};