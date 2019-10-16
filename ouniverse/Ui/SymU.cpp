//Copyright 2015-2019, All Rights Reserved.

#include "Ui/SymU.h"

#include "Interface/Json.h"

#include "System/UserLib.h"
#include "System/User.h"
#include "System/UserDais.h"

#include "System/LoadoutLib.h"
#include "System/Loadout.h"
#include "System/LoadoutDais.h"

#include "System/Log.h"

#include "System/Glass.h"

#include "System/User^.h"
#include "System/Loadout^.h"

#include <cohtml\Binding\Vector.h>
#include <cohtml\Binding\String.h>


SymU::SymU(UserLibC* InUserLib, UserDaisC* InUserD, LoadoutLibC* InLoadoutLib, LoadoutDaisC* InLoadoutD, OniManagerC* InOniManager)
{
	Open_ = false;

	UserL_ = InUserLib;
	UserDais_ = InUserD;
	LoadoutL_ = InLoadoutLib;
	LoadoutDais_ = InLoadoutD;
	Oni_ = InOniManager;

}

void SymU::Open()
{

	JsonS Vars = JsonS();

	JsonS Status = JsonS();
	Status.Add("vars", Vars);
	Status.Add("userl", UserL_->UiStatus());
	Status.Add("user", UserDais_->UiStatus());
	Status.Add("loadoutl", LoadoutL_->UiStatus());

	GSEND1("sym.open",Status.Serialize().ToChar());

	GBIND("sym.user<", this, &SymU::User_REQ);
	GBIND("sym.preusers<", this, &SymU::PreUsers_REQ);
	GBIND("sym.userconfig<", this, &SymU::UserConfig_REQ);
	GBIND("sym.config^", this, &SymU::User_SAVE);
	GBIND("sym.user+", this, &SymU::User_NEW);
	GBIND("sym.user!", this, &SymU::UserSelected_ACT);

	GBIND("sym.loadouts<", this, &SymU::Loadouts_REQ);
	GBIND("sym.loadout!", this, &SymU::LoadoutSelected_ACT);

	Open_ = true;
}

void SymU::Close()
{
	GSEND0("sym.close");

	Open_ = false;
}

void SymU::User_REQ(int uid)
{

}

void SymU::PreUsers_REQ()
{
	GSEND1("sym.preusers>", UserL_->Users().Vector());//sym_v_users
}

void SymU::UserConfig_REQ(int uid)
{

}

void SymU::User_SAVE(std::string Dat)
{

}

void SymU::User_NEW()
{

}

void SymU::UserSelected_ACT(int uid)
{
	UserL_->Set(uid);
	GSEND1("sym.user@", uid);//sym_v_users
	LOGP
}

void SymU::Loadouts_REQ()
{
	GSEND1("sym.loadouts>", LoadoutL_->Loadouts().Vector());//sym_v_users
}

void SymU::LoadoutSelected_ACT(int uid)
{
	LoadoutL_->Set(uid);
	GSEND1("sym.loadout@", uid);//sym_v_users
	LOGP
}