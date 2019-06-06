//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/SystemP.h"
#include "System/UserLib.h"
#include "System/Kernel.h"

#include "System/Log.h"

SystemP::SystemP(KernelC* InKernel, UserLibC* InUserLib)
{
	First_ = true;
	Kernel_ = InKernel;
	UserLib_ = InUserLib;

}

void SystemP::Activate()
{
	if (First_)
	{
		GoUser();
		return;
	}
}

void SystemP::GoUser()
{
	UserLib_->SetUser(65535);
	LOGP
	GoTitle();
}

void SystemP::GoTitle()
{
	Kernel_->SetLoadout(0);
	LOGP
	GoSession();
}

void SystemP::GoSession()
{
	Kernel_->SetSession(41290);
	LOGP
}