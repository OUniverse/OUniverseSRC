//Copyright 2015-2019, All Rights Reserved.

#include "System/Babel.h"
#include "Interface/Json.h"

#include <fstream>
#include <string>

#include "Min/DebugM.h"

namespace Global
{
	UBabel* Babel;
}

UBabel* UBabel::Create(FileC BabelDoc)
{
	UBabel* Neu = NewObject<UBabel>();
	Global::Babel = Neu;
	Neu->Init(BabelDoc);
	return Neu;
}

void UBabel::Init(FileC BabelFile)
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


FString UBabel::Decode(int InCode)
{
	FString Result;

	bool bFound = Global::Babel->Lib_.Try(InCode,Result);

	if (bFound)
	{
		return Result;
	}
	
	return FString::FromInt(InCode);

}