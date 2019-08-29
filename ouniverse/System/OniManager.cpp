//Copyright 2015-2019, All Rights Reserved.

#include "System/OniManager.h"
#include "System/OniKey.h"
#include "System/Oni.h"
#include "System/OniCategory.h"

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

	Oni = Lib_[OniTypeC::Type::User];

	Oni->AddOnu(new OnuBoolC(OniGlobalC::AUTOLOGIN_SINGLE_USER, 0, OniCategoryC::User::General));
	Oni->AddOnu(new OnuBoolC(OniGlobalC::AUTOLOGIN_LAST_USER, 0, OniCategoryC::User::General));

}

void OniManagerC::Load(OniTypeC::Type InType, NewFileC InFile)
{
	Lib_[InType]->Load(InFile);
}