//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/UserP.h"
#include "System/UserLib.h"
#include "System/Kernel.h"

#include "Min/DebugM.h"

UserP::UserP(KernelC* InKernel, UserLibC* InUserLib)
{
	First_ = true;
	Kernel_ = InKernel;
	UserLib_ = InUserLib;

}

void UserP::Activate()
{
	DBUG("GOT HERE1")
	if (First_)
	{
		DBUG("GOT HERE2")
		GoUser();
		return;
	}
}

void UserP::GoUser()
{
	UserLib_->SetUser(65535);
	GoTitle();
}

void UserP::GoTitle()
{
	Kernel_->SetLoadout(0);
	GoSession();
}

void UserP::GoSession()
{
	Kernel_->SetSession(41290);
}