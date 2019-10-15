//Copyright 2015-2019, All Rights Reserved.

#include "System/UserDais.h"
#include "System/User.h"


UserDaisC::UserDaisC()
{
	User_ = NULL;
}

void UserDaisC::Set(UserC* InUser)
{
	if (User_ != NULL)
	{
		User_->Dismount();
	}

	User_ = InUser;
	User_->Mount();
}

UserC* UserDaisC::Get()
{
	return User_;
}

JsonS UserDaisC::UiStatus()
{
	return JsonS();
}