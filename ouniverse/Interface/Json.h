//Copyright 2015-2019, All Rights Reserved.

/**

## Json

**Struct:**  JsonS

Json read-only interface which is a wrapper around rapidjson

*/

#pragma once

#include <nlohmann/json.hpp>

#include "Interface/String.h"
#include "Interface/Int.h"

using json = nlohmann::json;


struct JsonS
{
	json J;

	JsonS(const char* JSerialized);
	JsonS(StringC JSerialized);
	JsonS(json InJ);

	int Size();

	StringC String(const char* Query);

	JsonS operator[](const char* Query);
	JsonS operator[](int Query);

	int Int(const char* Query);

	UInt8  ToUInt8();
	UInt16 ToUInt16();
	UInt32 ToUInt32();
	UInt64 ToUInt64();

	UInt8  ToUInt8(const char* Query);
	UInt16 ToUInt16(const char* Query);
	UInt32 ToUInt32(const char* Query);
	UInt64 ToUInt64(const char* Query);

};