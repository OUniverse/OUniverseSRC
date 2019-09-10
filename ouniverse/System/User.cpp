//Copyright 2015-2019, All Rights Reserved.

#include "System/User.h"

#include "Interface/Json.h"
#include "Interface/Provenance.h"

#include "System/Log.h"

#include <fstream>

#include "System/Major.h"
#include "System/LoadoutLib.h"

#include "Key/GlobalK.h"

#include "Min/DebugM.h"


const int UserC::Provenance = 1;

UserC* UserC::Create(FolderC InFolder, StringC InFolderName)
{
	return new UserC(InFolder, InFolderName);
}

void UserC::Mount()
{
	MajorC* M = MajorC::Get();
	M->LoadoutL()->Load(Folder());
}

void UserC::Dismount()
{

}

UserC::UserC(FolderC InFolder, StringC InFolderName)
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
	ProvenanceC Prov = ProvenanceC(UserC::Provenance, StringC(LineSS).ToIntZeroFail());

	if(!Prov.IsValid())
	{
		LOG(505, Void(), "Error with Writer Version.");
		return;
	}

	if (!Prov.IsCurrent())
	{
		return;
	}


	std::getline(FileSS, LineSS);
	JsonS J = JsonS(StringC(LineSS));
	ID_ = J.String(GlobalK::ID);
	Glyph_ = J.Int(GlobalK::Glyph);

	LOG(10293, ID_, "Is Valid: $V$")
	
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


FolderC UserC::Folder()
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
		User_->Dismount();
	}

	User_ = InUser;
	User_->Mount();
}

UserC* UserW::Get()
{
	return User_;
}