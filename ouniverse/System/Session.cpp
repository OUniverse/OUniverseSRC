//Copyright 2015-2019, All Rights Reserved.

#include "System/Session.h"
#include "System/User.h"
#include "Kernel/Kernel.h"

namespace GlobalSingleton
{
	SessionC Session;
}

SessionC* SessionC::Get()
{
	return &GlobalSingleton::Session;
}

SessionC* SessionC::Create()
{
	GlobalSingleton::Session = *(new SessionC());
	return &GlobalSingleton::Session;
}

SessionC::SessionC()
{
	HasKernel_ = false;
}

void SessionC::NewKernel(UserC* InNewUser)
{

}