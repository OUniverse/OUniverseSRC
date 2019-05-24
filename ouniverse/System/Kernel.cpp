//Copyright 2015-2019, All Rights Reserved.

#include "System/Kernel.h"

#include "System/User.h"
#include "Dais/Session.h"
#include "System/SessionLib.h"

#include "Min/LogM.h"

namespace GlobalSingleton
{
	KernelC Kernel;
}

KernelC* KernelC::Get()
{
	return &GlobalSingleton::Kernel;
}

KernelC* KernelC::Create()
{
	GlobalSingleton::Kernel = *(new KernelC());
	return &GlobalSingleton::Kernel;
}

KernelC::KernelC()
{
	HasUser_ = false;
	HasSession_ = false;
}

UserC* KernelC::GetUser()
{
	return User_;
}

SessionC* KernelC::GetSession()
{
	return Session_;
}

void KernelC::SetUser(UserC* InNewUser)
{
	
	User_ = InNewUser;
	HasUser_ = true;

	LOG(BOOT, 0, 0, StringC("Setting new user: ")+StringC(User_->GetUID()))

	if (HasSession_)
	{
		LOG(BOOT, 0, 0, "Deleting Prior User's SessionLib")
		delete SessionLib_;
	}

	SessionLib_ = new SessionLib(User_->GetPath());
	SessionC* NewSession;

	bool Found = SessionLib_->Try(41290,NewSession);

	if (Found)
	{
		SetSession(NewSession);
	}
}

void KernelC::SetSession(SessionC* InNewSession)
{
	Session_ = InNewSession;
	if(HasSession_)
	{
		Session_->Demote();
	}
	Session_->Promote();
	HasSession_ = true;
}