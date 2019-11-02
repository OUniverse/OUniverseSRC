//Copyright 2015-2019, All Rights Reserved.

#include "System/Class.h"
#include "Form/CharacterA.h"
#include "Form/Character3D.h"

#include "Ui/Ui.h"
#include "Ui/Console_Master.h"
#include "Ui/Logv_Master.h"
#include "Ui/Pulse_Master.h"
#include "Ui/Sym_EmptyView.h"
#include "Ui/Sym_Master.h"
#include "Ui/Sym_UserView.h"
#include "Ui/Writer_Master.h"
#include "Ui/Writer_AtlasView.h"
#include "Ui/Writer_FormView.h"
#include "Ui/Writer_VSetup.h"
#include "Ui/Writer_VSetupEntry.h"

namespace Class
{
	bool Setup_ = false;
	TSubclassOf<UCharacterA> F_CharacterA;
	TSubclassOf<ACharacter3D> F_Character3D;
	

	TSubclassOf<UUi>					U_Ui;
	TSubclassOf<UConsole_Master>		Console_Master;
	TSubclassOf<ULogv_Master>			Logv_Master;
	TSubclassOf<UPulse_Master>			Pulse_Master;
	TSubclassOf<USym_EmptyView>			Sym_EmptyView;
	TSubclassOf<USym_Master>			Sym_Master;
	TSubclassOf<USym_UserView>			Sym_UserView;
	
	TSubclassOf<UWriter_AtlasView>		Writer_AtlasView;
	TSubclassOf<UWriter_FormView>		Writer_FormView;
	TSubclassOf<UWriter_Master>			Writer_Master;
	TSubclassOf<UWriter_VSetup>			Writer_VSetup;
	TSubclassOf<UWriter_VSetupEntry>	Writer_VSetupEntry;
}


void ClassC::Setup()
{
	Class::Setup_ = true;
	Class::F_CharacterA			= TSoftClassPtr<UCharacterA>(FSoftClassPath("/Game/class/form/ChracterA.ChracterA_C")).LoadSynchronous();
	Class::F_Character3D		= TSoftClassPtr<ACharacter3D>(FSoftClassPath("/Game/class/form/Character3D.Character3D_C")).LoadSynchronous();


	Class::U_Ui					= TSoftClassPtr<UUi>(FSoftClassPath("/Game/class/ui/UiC.UiC_C")).LoadSynchronous();
	Class::Console_Master		= TSoftClassPtr<UConsole_Master>(FSoftClassPath("/Game/class/ui/Console_MasterC.Console_MasterC_C")).LoadSynchronous();
	Class::Logv_Master			= TSoftClassPtr<ULogv_Master>(FSoftClassPath("/Game/class/ui/Logv_MasterC.Logv_MasterC_C")).LoadSynchronous();
	Class::Pulse_Master			= TSoftClassPtr<UPulse_Master>(FSoftClassPath("/Game/class/ui/Pulse_MasterC.Pulse_MasterC_C")).LoadSynchronous();
	Class::Sym_Master			= TSoftClassPtr<USym_Master>(FSoftClassPath("/Game/class/ui/Sym_MasterC.Sym_MasterC_C")).LoadSynchronous();
	Class::Sym_UserView			= TSoftClassPtr<USym_UserView>(FSoftClassPath("/Game/class/ui/Sym_UserViewC.Sym_UserViewC_C")).LoadSynchronous();
	
	Class::Writer_AtlasView		= TSoftClassPtr<UWriter_AtlasView>(FSoftClassPath("/Game/class/ui/Writer_AtlasViewC.Writer_AtlasViewC_C")).LoadSynchronous();
	Class::Writer_FormView		= TSoftClassPtr<UWriter_FormView>(FSoftClassPath("/Game/class/ui/Writer_FormViewC.Writer_FormViewC_C")).LoadSynchronous();
	Class::Writer_Master		= TSoftClassPtr<UWriter_Master>(FSoftClassPath("/Game/class/ui/Writer_MasterC.Writer_MasterC_C")).LoadSynchronous();
	Class::Writer_VSetup		= TSoftClassPtr<UWriter_VSetup>(FSoftClassPath("/Game/class/ui/Writer_VSetupC.Writer_VSetupC_C")).LoadSynchronous();
	Class::Writer_VSetupEntry	= TSoftClassPtr<UWriter_VSetupEntry>(FSoftClassPath("/Game/class/ui/Writer_VSetupEntryC.Writer_VSetupEntryC_C")).LoadSynchronous();
}

bool ClassC::IsSetup()
{
	return Class::Setup_;
}

TSubclassOf<UCharacterA> ClassC::F_CharacterA() { return Class::F_CharacterA; }
TSubclassOf<ACharacter3D> ClassC::F_Character3D() { return Class::F_Character3D; }


TSubclassOf<UUi> ClassC::U_Ui()									{ return Class::U_Ui; }
TSubclassOf<UConsole_Master> ClassC::Console_Master()			{ return Class::Console_Master; }
TSubclassOf<ULogv_Master> ClassC::Logv_Master()					{ return Class::Logv_Master; }
TSubclassOf<UWriter_Master> ClassC::Writer_Master()				{ return Class::Writer_Master; }
TSubclassOf<UWriter_AtlasView> ClassC::Writer_AtlasView()		{ return Class::Writer_AtlasView; }
TSubclassOf<UWriter_FormView> ClassC::Writer_FormView()			{ return Class::Writer_FormView; }
TSubclassOf<UWriter_VSetup> ClassC::Writer_VSetup()				{ return Class::Writer_VSetup; }
TSubclassOf<UWriter_VSetupEntry> ClassC::Writer_VSetupEntry()	{ return Class::Writer_VSetupEntry; }