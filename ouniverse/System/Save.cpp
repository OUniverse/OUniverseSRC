//Copyright 2015-2019, All Rights Reserved.

#include "System/Save.h"
#include "Interface/Json.h"
#include "System/Log.h"

#include <fstream>

#include "Min/DebugM.h"

const char* SaveC::K_NAME = "n";
const char* SaveC::K_GLYPH = "g";
const char* SaveC::K_AWARDS = "a";

SaveC* SaveC::Create(FolderC InFolder, StringC InFolderName)
{
	return new SaveC(InFolder, InFolderName);
}

void SaveC::Mount()
{

}

void SaveC::Dismount()
{

}

SaveC::SaveC(FolderC InFolder, StringC InFolderName)
{
	Valid_ = false;
	
	int ErrCode;
	ErrCode = UID_.ParseTitle(InFolderName);

	Folder_ = InFolder;

	if (ErrCode)
	{
		LOG(13451, ErrCode, "Name is incorrect. 1:Prefix Wrong, 2:Name can't become an Integer, 3:Integer of name is larger then max allowed size.  Error Code: $V$")
		return;
	}

	
	File_ = Folder_.ToFile("_Save","ousr");

	if (!File_.Exists())
	{
		LOG(13789, File_.ToString(), "File missing: $V$")
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

	std::getline(FileSS, LineSS);
	JsonS J = JsonS(StringC(LineSS));
	Name_ = J.String(SaveC::K_NAME);
	Glyph_ = J.String(SaveC::K_GLYPH);

	LOG(10293, Name_, "Is Valid: $V$")
	
	Valid_ = true;
	LOG(10293, InFolderName, "Is Valid: $V$")
	
}


SaveUID SaveC::UID()
{
	return UID_;
}


bool SaveC::IsValid()
{
	return Valid_;
}


FolderC SaveC::Folder()
{
	return Folder_;
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