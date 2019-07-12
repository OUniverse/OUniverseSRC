//Copyright 2015-2019, All Rights Reserved.

#include "System/User.h"
#include "Interface/JsonWriter.h"
#include "Interface/Dir.h"
#include "Interface/DirQuery.h"

#include "Interface/TitleParse.h"

#include "System/UserFile.h"

#include "System/Log.h"
#include "Min/DebugM.h"



const char* UserC::FOLDER_PREFIX	= "U";
const char* UserC::FILE_NAME		= "_user.ousr";



UserC* UserC::Create(DirS* InUserDir, StringC InFolderName)
{
	return new UserC(InUserDir, InFolderName);
}

void UserC::Promote()
{

}

void UserC::Demote()
{

}

UserC::UserC(DirS* InUserDir, StringC InFolderName)
{
	Valid_ = false;
	

	int ErrCode;
	ErrCode = TitleParseC::TryPrefixedUID(InFolderName, UserC::FOLDER_PREFIX, Int::MaxU16, UID_);

	if (ErrCode)
	{
		LOG(13451, ErrCode, "Name is incorrect. 1:Prefix Wrong, 2:Name can't become an Integer, 3:Integer of name is larger then max allowed size.  Error Code: $V$")
	
			return;
	}

	Path_ = InUserDir->Get()/InFolderName;

	UserFile_ = new UserFileC(Path_);

	if(!UserFile_->Valid())
	{
		delete UserFile_;
		return;
	}

	Name_ = UserFile_->Name_;
	Glyph_ = UserFile_->Glyph_;

	Valid_ = true;
	LOG(10293, InFolderName, "Is Valid: $V$")
	

}


int UserC::UID()
{
	return UID_;
}


bool UserC::IsValid()
{
	return Valid_;
}


StringC UserC::GetPath()
{
	return Path_;
}