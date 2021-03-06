//Copyright 2015-2019, All Rights Reserved.

#include "System/Save.h"
#include "Interface/Json.h"
#include "System/Log.h"

#include <fstream>

#include "Min/DebugM.h"

SaveC* SaveC::Create(FileC InFile)
{
	return new SaveC(InFile);
}

void SaveC::Mount()
{

}

void SaveC::Dismount()
{

}

SaveC::SaveC(FileC InFile)
{
	Valid_ = false;
	
	int ErrCode;
	ErrCode = UID_.ParseTitle(InFile.Name());

	File_ = InFile;

	if (ErrCode)
	{
		LOG(13451, ErrCode, "Name is incorrect. 1:Prefix Wrong, 2:Name can't become an Integer, 3:Integer of name is larger then max allowed size.  Error Code: $V$")
		return;
	}


	std::string LineSS;
	std::ifstream FileSS;

	FileSS.open(File_.ToString().ToChar());

	std::getline(FileSS, LineSS);
	StringC WVer = StringC(LineSS);
	U16 WriterVer = WVer.ToU16ZeroFail();

	if (!WriterVer)
	{
		LOG(505, Void(), "Error with Writer Version.");
		return;
	}

	LOG(10293, Name_, "Is Valid: $V$")
	
	Valid_ = true;
	LOG(10293, InFile.Name(), "Is Valid: $V$")
	
}


SaveUID SaveC::UID()
{
	return UID_;
}


bool SaveC::IsValid()
{
	return Valid_;
}


FileC SaveC::File()
{
	return File_;
}




SaveW::SaveW()
{
	Save_ = nullptr;
}

void SaveW::Set(SaveC* InSave)
{
	if (Save_ != nullptr)
	{
		Save_->Dismount();
	}

	Save_ = InSave;
	E_Set.TriggerAndLife(Save_);
}

SaveC* SaveW::Get()
{
	return Save_;
}