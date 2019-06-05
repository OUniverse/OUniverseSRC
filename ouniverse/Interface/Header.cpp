//Copyright 2015-2019, All Rights Reserved.

#include "Interface/Header.h"

ScribeS::ScribeS()
{
	Value_ = 0;
}

ScribeS::ScribeS(StringC InLine)
{
	if (!InLine.BeInt(Value_))
	{
		Value_ = 0;
	}
}

bool ScribeS::Valid()
{
	return Value_;
}

int ScribeS::Get()
{
	return Value_;
}