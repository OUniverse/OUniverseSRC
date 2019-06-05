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

	U8  UInt8();
	U16 UInt16();
	U32 UInt32();
	U64 UInt64();

	U8  UInt8(const char* Query);
	U16 UInt16(const char* Query);
	U32 UInt32(const char* Query);
	U64 UInt64(const char* Query);

};

