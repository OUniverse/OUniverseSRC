//Copyright 2015-2019, All Rights Reserved.

#include "System/CreditLib.h"
#include "System/Credit.h"

#include "Interface/Json.h"
#include "Interface/File.h"

#include "System/Log.h"


#include <fstream>
#include <string>


CreditLibC::CreditLibC()
{
	Len_ = 0;
}


CreditC* CreditLibC::operator[](U64 InValue)
{
	return Lib_[InValue];
}

CreditC* CreditLibC::At(int Index)
{
	return Lib_.At(Index);
}

void CreditLibC::Add(U64 InUID, CreditC* InCredit)
{
	Len_++;
	Lib_.Add(InUID, InCredit);
}

int CreditLibC::Len()
{
	return Len_;
}

void CreditLibC::GetCreditsFromAtlas(StringC InAtlasPath)
{

	StringC SearchPath = InAtlasPath / CreditC::FILE_NAME;

	if (!FileC(SearchPath).Exists())
	{
		LOG(13789, SearchPath, "File missing: $V$")
			return;
	}

	std::string Line;
	std::ifstream File;
	File.open(SearchPath.ToChar());

	std::getline(File, Line);
	U8 WriterVer = StringC(Line).ToU8ZeroFail();
	if (!WriterVer)
	{
		LOG(51687, Void(), "Error with Writer Version.");
		return;
	}

	std::getline(File, Line);
	JsonS J = JsonS(StringC(Line));


	int L = J.Len();
	for (int i = 0; i < L; i++)
	{
		JsonS JCur = J[i];


		U64 InUID = JCur.UInt64(CreditC::K_UID);

		CreditC* Seek = NULL;

		if (Try(InUID, Seek))
		{
			Seek->Compare(&JCur);
		}
		else
		{
			Seek = new CreditC(&JCur);
			Lib_.Add(InUID, Seek);
		}
	}
}

bool CreditLibC::Try(U64 InUID, CreditC* Out)
{
	return Lib_.Try(InUID, Out);
}