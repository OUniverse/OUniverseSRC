//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/SystemP.h"
#include "System/UserLib.h"
#include "System/SessionLib.h"

#include "System/Kernel.h"

#include "System/Log.h"

#include "System/Glass.h"
#include "System/User^.h"
#include "System/Session^.h"

#include <cohtml\Binding\Vector.h>


#include "Min/DebugM.h"

SystemP::SystemP(KernelC* InKernel, UserLibC* InUserLib)
{

	First_ = true;
	Kernel_ = InKernel;
	UserLib_ = InUserLib;

}

void SystemP::Activate()
{
	GBIND("SystemP.PageClosed", this, &SystemP::PageClosed);
	GBIND("SystemP.PhaseClosed", this, &SystemP::PhaseClosed);

	GSEND0("sym.a");
	

	if (First_)
	{

	}

	GoPhasePreUser();
}


void SystemP::GoPhasePreUser()
{
	ActivePage = Pages::User;
	ActivePhase = Phases::PreUser;
	GSEND1("sym.setPhase", "puser");
}

void SystemP::GoPhasePreData()
{
	ActivePage = Pages::Title;
	ActivePhase = Phases::PreData;
	GSEND1("sym.setPhase", "pdata");
}

void SystemP::GoPhasePreLoad()
{

}


void SystemP::SetupPhasePreUser()
{
	GoUser();
}

void SystemP::SetupPhasePreData()
{
	TitleGo();
}

void SystemP::SetupPhasePreLoad()
{

}


void SystemP::GoUser()
{
	ActivePage = Pages::User;
	GSEND1("sym.setPage", "user");
}

void SystemP::SetupUser()
{
	GBIND("SystemP.UserSelected", this, &SystemP::UserSelected);
	GSEND1("sym.user.a", UserLib_->Users().Vector());	
	
}

void SystemP::UserSelected(int InUID)
{
	UserLib_->SetUser(InUID);
	LOGP
	DBUG(IFS(InUID));
	GoPhasePreData();
}


void SystemP::TitleGo()
{

	ActivePage = Pages::Title;
	GSEND1("sym.setPage", "title");
}


void SystemP::TitleSetup()
{
	GBIND("SystemP.ForwardTitle", this, &SystemP::TitleForward);
	GSEND0("sym.title.a");
}

void SystemP::TitleForward(int InUID)
{
	Kernel_->SetLoadout(1);
	LOGP
	DBUG(IFS(InUID));
	TitleOnward();
}

void SystemP::TitleOnward()
{
	SessionGo();
}






void SystemP::SessionGo()
{
	ActivePage = Pages::Session;
	GSEND1("sym.setPage", "session");

	//Kernel_->SetSession(41290);
	//LOGP
}

void SystemP::SessionSetup()
{
	GBIND("SystemP.SessionSelected", this, &SystemP::SessionSelected);
	Kernel_->SessionLib()->Sessions().Vector();
	GSEND1("sym.session.a", Kernel_->SessionLib()->Sessions().Vector());
	//GSEND1("sym.session.a", UserLib_->Users().Vector());
}

void SystemP::SessionSelected()
{

}

void SystemP::PageClosed()
{
	switch (ActivePage) {
		case Pages::User:
		SetupUser();
		break;
		case Pages::Title:
		TitleSetup();
		break;
		case Pages::Session:
		SessionSetup();
		break;
	}
}

void SystemP::PhaseClosed()
{
	switch (ActivePhase) {
	case Phases::PreUser:
		SetupPhasePreUser();
		break;
	case Phases::PreData:
		SetupPhasePreData();
		break;
	case Phases::PreLoad:
		SetupPhasePreLoad();
		break;
	}
}



void SystemP::EndTitle()
{

}

