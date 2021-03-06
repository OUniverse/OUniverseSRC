//Copyright 2015-2019, All Rights Reserved.

#include "System/OniManager.h"
#include "System/OniKey.h"
#include "System/Oni.h"
#include "System/OniCategory.h"

#include "System/Log.h"

OniManagerC::OniManagerC()
{
	Lib_.Init(OniTypeC::Type::TYPE_MAX,nullptr);

	Lib_[OniTypeC::Type::Internal] = new OniC();
	Lib_[OniTypeC::Type::Global] = new OniC();
	Lib_[OniTypeC::Type::User] = new OniC();
	Lib_[OniTypeC::Type::Scribe] = new OniC();


	OniC* Oni;
	Oni = Lib_[OniTypeC::Type::Internal];
	Oni->AddOnu(new OnuIntC(OniInternalC::LAST_USER, -1, OniCategoryC::Internal::All));
	Oni->AddOnu(new OnuIntC(OniInternalC::LAST_LOGIN, -1, OniCategoryC::Internal::All));

	Oni = Lib_[OniTypeC::Type::Global];

	Oni->AddOnu(new OnuBoolC(OniGlobalC::AUTOLOGIN_SINGLE_USER, 0, OniCategoryC::Global::Boot));
	Oni->AddOnu(new OnuBoolC(OniGlobalC::AUTOLOGIN_LAST_USER, 0, OniCategoryC::Global::Boot));
	Oni->AddOnu(new OnuBoolC(OniGlobalC::SKIP_SPLASH_MOVIES, 0, OniCategoryC::Global::Boot));

	Oni = Lib_[OniTypeC::Type::User];

	Oni->AddOnu(new OnuIntC(OniUserC::LOADOUT_LAST, -1, OniCategoryC::User::General));
	Oni->AddOnu(new OnuBoolC(OniUserC::LOADOUT_BYPASS, 1, OniCategoryC::User::General));
	Oni->AddOnu(new OnuBoolC(OniUserC::LOADOUT_AUTOSELECT_SINGLE, 1, OniCategoryC::User::General));
	Oni->AddOnu(new OnuBoolC(OniUserC::LOADOUT_AUTOSELECT_LAST, 1, OniCategoryC::User::General));
}

void OniManagerC::Load(OniTypeC::Type InType, FileC InFile)
{
	LOG(19955, InType, "Loading Oni. Type: $V$")
	LOG(34755, InFile.ToString().ToChar(), "Oni file path: $V$")

	Lib_[InType]->Load(InFile);
}

bool OniManagerC::GetBool(OniTypeC::Type InType, int OniKey)
{
	return Lib_[InType]->Get(OniKey)->ToBool();
}

int OniManagerC::GetInt(OniTypeC::Type InType, int OniKey)
{
	return Lib_[InType]->Get(OniKey)->ToInt();
}

StringC OniManagerC::GetString(OniTypeC::Type InType, int OniKey)
{
	return Lib_[InType]->Get(OniKey)->ToString();
}

float OniManagerC::GetFloat(OniTypeC::Type InType, int OniKey)
{
	return Lib_[InType]->Get(OniKey)->ToFloat();
}

StringC OniManagerC::GetSerializedCategory(OniTypeC::Type InType, int InCategory)
{
	return Lib_[InType]->GetSerializedCategory(InCategory);
}