//Copyright 2015-2019, All Rights Reserved.

#include "Interface/Dict.h"
#include "Interface/Json.h"

DictC::DictC()
{

}


bool DictC::Load(FileC InFile, const char* InKey, const char* InVal)
{
	JsonS J = JsonS(InFile.Doc().Open().ToString());
	JsonS Cur;

	int L = J.Len();

	for (int i = 0; i < L; i++)
	{
		Cur = J[i];
		Dict_.Add(Cur.Int(InKey), Cur.String(InVal).ToFString());
	}

	return true;
}

StringC DictC::Get(int InKey)
{
	StringC TryString;

	if (Dict_.Try(InKey, TryString))
	{
		return TryString;
	}
	return "$ErrorLang";
}

void DictC::Clear()
{
	Dict_.Clear();
}
