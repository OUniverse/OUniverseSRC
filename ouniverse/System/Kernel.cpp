//Copyright 2015-2019, All Rights Reserved.

#include "System/Kernel.h"

#include "System/User.h"
#include "System/Session.h"
#include "System/SessionLib.h"
#include "System/Loadout.h"
#include "System/LoadoutLib.h"

#include "System/Log.h"

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
	HasLoadout_ = false;
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


	LOG(49033, User_->GetUID(), "Setting User: $V$")

	if (HasLoadout_)
	{
		LOG(16715, Void(), "Deleting prior User's LoadoutLib.")
		delete LoadoutLib_;
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

	LOG(12802, int(InLoadout->GetUID()), "Setting Loadout: $V$")

	if (HasSession_)
	{
			LOG(31908, Void(), "Deleting prior SessionLib belonging to the last Loadout.")
			delete SessionLib_;
	}

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

	LOG(16724, InSession->GetUID(), "Setting Session: $V$")

	return true;
}