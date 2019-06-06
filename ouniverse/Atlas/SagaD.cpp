//Copyright 2015-2019, All Rights Reserved.

#include "Atlas/SagaD.h"
#include <fstream>
#include <string>
#include "Interface/Int.h"
#include "Interface/TitleParse.h"
#include "Interface/Json.h"

#include "System/Log.h"

#include "Min/DebugM.h"


const char* SagaD::EXT_Saga = "saga";
const char* SagaD::PFX = "S";

SagaD::SagaD(StringC InFile, StringC InPath)
{

	Valid_ = false;

	LOG(35187, InPath, "Validating Saga file at path: $V$")

		int ErrCode = TitleParseC::TryPrefixedUID(InFile.TrimExtension(), SagaD::PFX, Int::MaxU8, UID_);

	if (ErrCode)
	{
		LOG(13451, ErrCode, "Name is incorrect. 1:Prefix Wrong, 2:Name can't become an Integer, 3:Integer of name is larger than max allowed size.  Error Code: $V$")
			return;
	}

	std::string Line;
	std::ifstream File;
	File.open(InPath.ToChar());

	std::getline(File, Line);
	U8 WriterVer = StringC(Line).ToU8ZeroFail();
	if (!WriterVer)
	{
		LOG(51687, Void(), "Error with Writer Version.");
		return;
	}

	std::getline(File, Line);
	//SagaF NewSagaForm = SagaF(StringC(Line));
	//SagaMap.Add(NewSagaForm.UID(), NewSagaForm);

	LOG(30398, int(UID_), "Saga is valid: $V$")
	Valid_ = true;

}

U8 SagaD::UID()
{
	return UID_;
}

bool SagaD::Valid()
{
	return Valid_;
}