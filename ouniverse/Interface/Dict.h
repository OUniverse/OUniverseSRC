//Copyright 2015-2019, All Rights Reserved.


#include "Interface/String.h"
#include "Interface/Url.h"
#include "Interface/Map.h"

#pragma once


class DictC
{

public:

	DictC();

	bool Load(FileC InFile, const char* Key="k", const char* Val="v");

	StringC Get(int InKey);

	void Clear();


private:

	MapC<int, StringC> Dict_;
};