//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/SystemP.h"


#include "Interface/Json.h"

#include "System/UserLib.h"
#include "System/User.h"

#include "System/LoadoutLib.h"
#include "System/Loadout.h"

#include "System/Log.h"

#include "System/Glass.h"


#include <cohtml\Binding\Vector.h>
#include <cohtml\Binding\String.h>

#include "Min/DebugM.h"

SystemP::SystemP(MaestroC* InMaestro, UserLibC* InUserLib, LoadoutLibC* InLoadoutLib, OniManagerC* InOniManager)
{
	FirstOpen_ = true;
	Maestro_ = InMaestro;
	UserL_ = InUserLib;
	LoadoutL_ = InLoadoutLib;
	Oni_ = InOniManager;
}

void SystemP::Activate()
{

	if (FirstOpen_)
	{


	}

	FirstOpen_ = false;
}



void SystemP::REQ_PreUsers()
{

}

void SystemP::ACT_UserSelected(int uid)
{

}

void SystemP::REQ_User(int uid)
{
	
}

void SystemP::REQ_UserConfig(int uid)
{

}

void SystemP::SAVE_User(std::string Dat)
{

}

void  SystemP::CREATE_User()
{

}


void SystemP::REQ_Loadouts()
{

}