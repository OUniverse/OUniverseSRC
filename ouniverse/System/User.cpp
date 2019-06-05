//Copyright 2015-2019, All Rights Reserved.

#include "System/User.h"
#include "Interface/JsonWriter.h"
#include "Interface/Dir.h"
#include "Interface/DirQuery.h"

#include "Interface/TitleParse.h"

#include "System/UserFile.h"

#include "Min/LogM.h"
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
		LOG(BOOT, 0, 1, StringC("Error Code with file name: ") + StringC(ErrCode))
			return;
	}

	Path_ = InUserDir->Get()/InFolderName;

	UserFile_ = new UserFileC(Path_);

	if(!UserFile_->Valid())
	{
		delete UserFile_;
		return;
	}

	Valid_ = true;
	LOG(BOOT, 0, 1, InFolderName + ": " + "Valid")
	

}


int UserC::GetUID()
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
