//Copyright 2015-2019, All Rights Reserved.


#include "Interface/String.h"
#pragma once


class PolyC
{

public:

	StringC Key;

	int DataID;

	int Type_;

	PolyC() {};

	PolyC(StringC InKey, int InDataID)
	{
		Key = InKey;
		DataID = InDataID;
	};

	static enum PolyType {
		Abstract,
		Object,
		Array,
		String,
		Int,
		Float,
	};

	int Type();
};

class PolyObjectC : public PolyC
{

public:

	PolyObjectC(StringC InKey, int InDataID);
	~PolyObjectC();

	void AddKey(PolyC* InNewKey);

	ArrayC<PolyC*> Items;
};

class PolyArrayC : public PolyC
{

public:

	PolyArrayC(StringC InKey, int InDataID);

	PolyC ArrType;
};

class PolyValueC : public PolyC
{

public:

	PolyValueC(StringC InKey, int InDataID);

	static enum ValueType {
		String,
		Float,
		Int,
		Link,
	};
};

class PolyStringC : public PolyValueC
{

public:

	PolyStringC(StringC InKey, int InDataID, StringC InValue);

	StringC Val_;
};

class PolyIntC : public PolyValueC
{

public:

	PolyIntC(StringC InKey, int InDataID, int InValue);

	int Val_;
};

class PolyFloatC : public PolyValueC
{

public:

	PolyFloatC(StringC InKey, int InDataID, float InValue);

	float Val_;
};