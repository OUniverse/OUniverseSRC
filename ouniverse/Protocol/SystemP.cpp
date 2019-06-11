//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/SystemP.h"
#include "System/UserLib.h"
#include "System/Kernel.h"

#include "System/Log.h"

#include "System/Glass.h"
#include "System/User^.h"

#include <cohtml\Binding\Vector.h>



SystemP::SystemP(KernelC* InKernel, UserLibC* InUserLib)
{

	First_ = true;
	Kernel_ = InKernel;
	UserLib_ = InUserLib;

}

void SystemP::Activate()
{
	GSEND0("sym.o");

	if (First_)
	{
		GSEND1("sym.user.o", UserLib_->Users().Vector())

		//GoUser();
		//return;
	}

	//GBIND("sym.oTitle", this, &SystemP::EndTitle);

}

void SystemP::EndTitle()
{

}

void SystemP::GoUser()
{
	//UserLib_->SetUser(65535);
	//LOGP
	//GoTitle();
}

void SystemP::GoTitle()
{
	Kernel_->SetLoadout(1);
	LOGP
	GoSession();
}

void SystemP::GoSession()
{
	Kernel_->SetSession(41290);
	LOGP
}