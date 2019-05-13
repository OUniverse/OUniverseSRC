//Copyright 2015-2019, All Rights Reserved.

#include "System/UserFolder.h"
#include "Interface/JsonWriter.h"
#include "Interface/Dir.h"
#include "Interface/File.h"
#include "Interface/DirQuery.h"

#include "User/DeclarationU.h"
#include "User/User.h"

#include "Min/LogM.h"
#include "Min/DebugM.h"


UserFolderC* UserFolderC::Create(DirS* InUserDir, StringC InFolderName)
{
	return new UserFolderC(InUserDir, InFolderName);
}

UserC* UserFolderC::Promote()
{
	return new UserC(Declaration_);
}

UserFolderC::UserFolderC(DirS* InUserDir, StringC InFolderName)
{
	Valid_ = false;
	
	if (InFolderName.Len() != 6)
	{
		LOG(BOOT, 0, 1, InFolderName+": "+"Folder Name is too long.")
		return;
	}

	if (InFolderName[0] != 'U')
	{
		LOG(BOOT, 0, 1, InFolderName + ": " + "Prefix is not U.")
		return;
	}

	FileC DeclarationFile = FileC(InUserDir->Get() / InFolderName, "u.oudcl");

	if (!DeclarationFile.Exists())
	{
		LOG(BOOT, 0, 1, InFolderName + ": " + "Declaration does not exist. (u.oudcl)")
		return;
	}

	StringC StrUID = InFolderName.SubString(1, 5);

	if (!StrUID.BeInt(UID_))
	{
		LOG(BOOT, 0, 1, InFolderName + ": " + "Prefix is not a number ("+ StrUID +")")
		return;
	}
	
	if (UID_ > USHRT_MAX)
	{
		LOG(BOOT, 0, 1, InFolderName + ": " + "UID is larger than a uint16 (" + UID_ + ")")
		return;
	}


	Valid_ = true;
	LOG(BOOT, 0, 1, InFolderName + ": " + "Valid")
	Declaration_ = new DeclarationU(UserDir->Get(),UID_);

}


int UserFolderC::GetUID()
{
	return UID_;
}
bool UserFolderC::IsValid()
{
	return Valid_;
}