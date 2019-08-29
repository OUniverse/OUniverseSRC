//Copyright 2015-2019, All Rights Reserved.

#include "System/User.h"
#include "Interface/Json.h"
#include "System/Log.h"

#include <fstream>

#include "Min/DebugM.h"

const char* UserC::K_NAME = "n";
const char* UserC::K_GLYPH = "g";
const char* UserC::K_AWARDS = "a";

UserC* UserC::Create(NewFolderC InFolder, StringC InFolderName)
{
	return new UserC(InFolder, InFolderName);
}

void UserC::Mount()
{

}

void UserC::Demount()
{

}

UserC::UserC(NewFolderC InFolder, StringC InFolderName)
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

	
	File_ = Folder_.ToFile("_user","ousr");

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
	Name_ = J.String(UserC::K_NAME);
	Glyph_ = J.String(UserC::K_GLYPH);

	LOG(10293, Name_, "Is Valid: $V$")
	
	Valid_ = true;
	LOG(10293, InFolderName, "Is Valid: $V$")
	
}


UserUID UserC::UID()
{
	return UID_;
}


bool UserC::IsValid()
{
	return Valid_;
}


NewFolderC UserC::Folder()
{
	return Folder_;
}











UserW::UserW()
{
	User_ = nullptr;
}

void UserW::Set(UserC* InUser)
{
	if (User_ != nullptr)
	{
		User_->Demount();
	}

	User_ = InUser;

	Ev_UserSet.TriggerAndLife(User_);
}

UserC* UserW::Get()
{
	return User_;
}