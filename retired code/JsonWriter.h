//Copyright 2015-2019, All Rights Reserved.

/**

## JsonWriter

**Struct:**  JsonWriterS

Custom JSON serializer for fast minimal output without having to create marshal structs.

*/

#include "Interface/String.h"

struct JsonWriterS
{

	StringC J;

	int Obj;
	int Arr;

	JsonWriterS()
	{
		J = "";
		Obj = 0;
		Arr = 0;
	}

	void Add(StringC Key, int Val);
	void Add(StringC Key, StringC Val);
	void BaseObject();
	void Object(StringC Key);
	void EndObject();
	void BaseArray();
	void Array(StringC Key);
	void EndArray();

	StringC Print();
};