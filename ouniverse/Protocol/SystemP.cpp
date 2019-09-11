//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/SystemP.h"


#include "Interface/Json.h"

#include "System/UserLib.h"
#include "System/User.h"

#include "System/Log.h"

#include "System/Glass.h"

#include "System/User^.h"

#include <cohtml\Binding\Vector.h>
#include <cohtml\Binding\String.h>

#include "Min/DebugM.h"

SystemP::SystemP(MaestroC* InMaestro, UserLibC* InUserLib, OniManagerC* InOniManager)
{
	FirstOpen_ = true;
	Maestro_ = InMaestro;
	UserL_ = InUserLib;
	Oni_ = InOniManager;
}

void SystemP::Activate()
{

	if (FirstOpen_)
	{

		GSEND0("sym.o");

		GBIND("sym.user<", this, &SystemP::REQ_User);
		GBIND("sym.preusers<", this, &SystemP::REQ_PreUsers);
		GBIND("sym.userconfig<", this, &SystemP::REQ_UserConfig);
		GBIND("sym.config^", this, &SystemP::SAVE_User);
		GBIND("sym.user+", this, &SystemP::CREATE_User);
	}

	FirstOpen_ = false;
}



void SystemP::REQ_PreUsers()
{
	GSEND1("sym.users.preusers>", UserL_->Users().Vector());//sym_v_users
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