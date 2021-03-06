//Copyright 2015-2019, All Rights Reserved.

#include "System/UserDais.h"
#include "System/User.h"

#include "System/OniManager.h"
#include "System/LoadoutLib.h"
#include "File/UserOni@.h"
#include "System/OniType.h"
#include "Interface/Url.h"

#include "System/LoadoutLib.h"

#include "Min/DebugM.h"

UserDaisC::UserDaisC(OniManagerC* InOni)
{
	User_ = NULL;
	Oni_ = InOni;
}

void UserDaisC::Initialize(LoadoutLibC* InLoadoutLib)
{
	LoadoutLib_ = InLoadoutLib;
}

void UserDaisC::Set(UserC* InUser)
{
	if (User_ != NULL)
	{
		User_->Dismount();
	}

	User_ = InUser;
	User_->Mount();

	Oni_->Load(OniTypeC::Type::User, User_->Folder().ToFile(UserOniFI::FileName, UserOniFI::Extension));
	LoadoutLib_->Load(User_->Folder());
}
 
int UserDaisC::IntUID()
{
	return User_->UID().ToInt();
}

FolderC UserDaisC::Folder()
{
	return User_->Folder();
}

UserC* UserDaisC::Get()
{
	return User_;
}

JsonS UserDaisC::UiStatus()
{
	return JsonS();
}