//Copyright 2015-2019, All Rights Reserved.

#include "System/Kernel.h"

#include "System/User.h"
#include "System/Session.h"
#include "System/SessionLib.h"
#include "System/Loadout.h"
#include "System/LoadoutLib.h"

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


LoadoutC* KernelC::GetLoadout()
{
	return Loadout_;
}

SessionC* KernelC::GetSession()
{
	return Session_;
}

void KernelC::SetUser(UserC* InUser)
{
	
	User_ = InUser;
	HasUser_ = true;

	LOG(BOOT, 0, 0, StringC("Setting User: ")+StringC(User_->GetUID()))

	if (HasLoadout_)
	{
		LOG(BOOT, 0, 0, "Deleting Prior User's SessionLib")
		delete LoadoutLib_;
		delete SessionLib_;
	}

	LoadoutLib_ = new LoadoutLibC(User_->GetPath());

}

bool KernelC::SetLoadout(int InLoadoutUID)
{
	LoadoutC* NewLoadout;

	if (LoadoutLib_->Try(InLoadoutUID, NewLoadout))
	{
		return SetLoadout(NewLoadout);
	}

	return false;
}

bool KernelC::SetLoadout(LoadoutC* InLoadout)
{
	Loadout_ = InLoadout;
	HasLoadout_ = true;

	SessionLib_ = new SessionLibC(User_->GetPath());

	return true;
}


bool KernelC::SetSession(int InSessionUID)
{
	SessionC* NewSession;

	if (SessionLib_->Try(InSessionUID, NewSession))
	{
		return SetSession(NewSession);
	}

	return false;
}

bool KernelC::SetSession(SessionC* InSession)
{
	
	if(HasSession_)
	{
		Session_->Demote();
	}

	Session_ = InSession;
	Session_->Promote();
	HasSession_ = true;

	return true;
}