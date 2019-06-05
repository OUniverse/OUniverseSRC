//Copyright 2015-2019, All Rights Reserved.

#include "System/User.h"
#include "Interface/JsonWriter.h"
#include "Interface/Dir.h"
#include "Interface/File.h"
#include "Interface/DirQuery.h"

#include "Kernel/DeclarationK.h"

#include "Interface/TitleParse.h"

#include "Min/LogM.h"
#include "Min/DebugM.h"


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
	ErrCode = TitleParseC::TryPrefixedUID(InFolderName, "U", Int::MaxU16(), UID_);

	if (ErrCode)
	{
		LOG(BOOT, 0, 1, StringC("Error Code with file name: ") + StringC(ErrCode))
			return;
	}

	FileC DeclarationFile = FileC(InUserDir->Get()/InFolderName/"u.oudcl");

	if (!DeclarationFile.Exists())
	{
		LOG(BOOT, 0, 1, InFolderName + ": " + "Declaration does not exist. (u.oudcl)")
		return;
	}

	Path_ = InUserDir->Get()/InFolderName;
	Valid_ = true;
	LOG(BOOT, 0, 1, InFolderName + ": " + "Valid")
	Declaration_ = new DeclarationK(Path_,UID_);

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

DeclarationK* UserC::GetDeclaration()
{
	return Declaration_;
}