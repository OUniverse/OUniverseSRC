//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/SystemP.h"
#include "System/UserLib.h"
#include "System/Kernel.h"

#include "Min/DebugM.h"

SystemP::SystemP(KernelC* InKernel, UserLibC* InUserLib)
{
	First_ = true;
	Kernel_ = InKernel;
	UserLib_ = InUserLib;

}

void SystemP::Activate()
{
	DBUG("GOT HERE1")
	if (First_)
	{
		DBUG("GOT HERE2")
		GoUser();
		return;
	}
}

void SystemP::GoUser()
{
	UserLib_->SetUser(65535);
	GoTitle();
}

void SystemP::GoTitle()
{
	Kernel_->SetLoadout(0);
	GoSession();
}

void SystemP::GoSession()
{
	Kernel_->SetSession(41290);
}