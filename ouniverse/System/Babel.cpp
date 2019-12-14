//Copyright 2015-2019, All Rights Reserved.

#include "System/Babel.h"
#include "Interface/Json.h"

#include <fstream>
#include <string>

#include "Min/DebugM.h"


namespace Global
{
	BabelC* Babel;
	bool Initialized = false;
}

BabelC* BabelC::Get()
{
	return Global::Babel;
}

BabelC::BabelC(FileC BabelFile)
{
	JsonS J = JsonS(BabelFile.Doc().Open().ToString());
	JsonS Cur;

	int L = J.Len();

	for (int i = 0; i < L; i++)
	{
		Cur = J[i];
		Lib_.Add(Cur.Int("k"), Cur.String("v").ToFString());
	}
}

BabelC* BabelC::Create(FileC InBabelDoc)
{
	BabelC* Neu = new BabelC(InBabelDoc);
	Global::Babel = Neu;
	Global::Initialized = true;
	return Neu;
}


FText BabelC::Decode(int InCode)
{
	if (!Global::Initialized)
	{
		return FText::FromString(FString::FromInt(InCode));
	}
	FString Result;

	bool bFound = Global::Babel->Lib_.Try(InCode,Result);

	if (bFound)
	{
		return FText::FromString(Result);
	}
	
	return FText::FromString(FString::FromInt(InCode));

}