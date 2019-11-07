//Copyright 2015-2019, All Rights Reserved.

#include "System/Class.h"
#include "Form/CharacterA.h"
#include "Form/Character3D.h"

#include "Ui/Ui.h"
#include "Ui/Console/CNS_Alpha.h"

#include "Ui/FormField/FF_Bool.h"
#include "Ui/FormField/FF_Link.h"
#include "Ui/FormField/FF_LinkList.h"
#include "Ui/FormField/FF_Text.h"

#include "Ui/Log/LOG_Alpha.h"
#include "Ui/Pulse/PLS_Alpha.h"

#include "Ui/Sym_Master.h"
#include "Ui/Sym_VLoadout.h"
#include "Ui/Sym_VUser.h"
#include "Ui/Sym_VUserEntry.h"
#include "Ui/Writer/WRI_Alpha.h"
#include "Ui/Writer/WRI_AlphaOpt.h"
#include "Ui/Writer/WRI_VAtlas.h"
#include "Ui/Writer/WRI_VForm.h"
#include "Ui/Writer/WRI_VFormEForm.h"
#include "Ui/Writer/WRI_VFormEntry.h"
#include "Ui/Writer/WRI_VSetup.h"
#include "Ui/Writer/WRI_VSetupEntry.h"

namespace Class
{
	bool Setup_ = false;
	TSubclassOf<UCharacterA> F_CharacterA;
	TSubclassOf<ACharacter3D> F_Character3D;


	TSubclassOf<UUi>					U_Ui;
	TSubclassOf<UCNS_Alpha>				CNS_Alpha;

	TSubclassOf<UFF_Bool>				FF_Bool;
	TSubclassOf<UFF_Link>				FF_Link;
	TSubclassOf<UFF_LinkList>			FF_LinkList;
	TSubclassOf<UFF_Text>				FF_Text;

	TSubclassOf<ULOG_Alpha>				LOG_Alpha;
	TSubclassOf<UPLS_Alpha>				PLS_Alpha;
	TSubclassOf<USym_Master>			Sym_Master;
	TSubclassOf<USym_VLoadout>			Sym_VLoadout;
	TSubclassOf<USym_VUser>				Sym_VUser;
	TSubclassOf<USym_VUserEntry>		Sym_VUserEntry;

	TSubclassOf<UTim_Master>			Tim_Master;
	TSubclassOf<UTim_VHome>				Tim_VHome;

	TSubclassOf<UWRI_Alpha>				WRI_Alpha;
	TSubclassOf<UWRI_AlphaOpt>			WRI_AlphaOpt;
	TSubclassOf<UWRI_VAtlas>			WRI_VAtlas;
	TSubclassOf<UWRI_VForm>				WRI_VForm;
	TSubclassOf<UWRI_VFormEForm>		WRI_VFormEForm;
	TSubclassOf<UWRI_VFormEntry>		WRI_VFormEntry;
	TSubclassOf<UWRI_VSetup>			WRI_VSetup;
	TSubclassOf<UWRI_VSetupEntry>		WRI_VSetupEntry;
}


void ClassC::Setup()
{
	Class::Setup_ = true;
	Class::F_CharacterA = TSoftClassPtr<UCharacterA>(FSoftClassPath("/Game/class/form/ChracterA.ChracterA_C")).LoadSynchronous();
	Class::F_Character3D = TSoftClassPtr<ACharacter3D>(FSoftClassPath("/Game/class/form/Character3D.Character3D_C")).LoadSynchronous();


	Class::U_Ui			= TSoftClassPtr<UUi>(FSoftClassPath("/Game/class/ui/UiC.UiC_C")).LoadSynchronous();

	Class::CNS_Alpha	= TSoftClassPtr<UCNS_Alpha>(FSoftClassPath("/Game/class/ui/console/CNS_AlphaC.CNS_AlphaC_C")).LoadSynchronous();

	Class::FF_Bool		= TSoftClassPtr<UFF_Bool>(FSoftClassPath("/Game/class/ui/FormField/FF_BoolC.FF_BoolC_C")).LoadSynchronous();
	Class::FF_Link		= TSoftClassPtr<UFF_Link>(FSoftClassPath("/Game/class/ui/FormField/FF_LinkC.FF_LinkC_C")).LoadSynchronous();
	Class::FF_LinkList	= TSoftClassPtr<UFF_LinkList>(FSoftClassPath("/Game/class/ui/FormField/FF_LinkListC.FF_LinkListC_C")).LoadSynchronous();
	Class::FF_Text		= TSoftClassPtr<UFF_Text>(FSoftClassPath("/Game/class/ui/FormField/FF_TextC.FF_TextC_C")).LoadSynchronous();


	Class::LOG_Alpha	= TSoftClassPtr<ULOG_Alpha>(FSoftClassPath("/Game/class/ui/log/LOG_AlphaC.LOG_AlphaC_C")).LoadSynchronous();

	Class::PLS_Alpha	= TSoftClassPtr<UPLS_Alpha>(FSoftClassPath("/Game/class/ui/pulse/PLS_AlphaC.PLS_AlphaC_C")).LoadSynchronous();

	Class::Sym_Master		= TSoftClassPtr<USym_Master>(FSoftClassPath("/Game/class/ui/Sym_MasterC.Sym_MasterC_C")).LoadSynchronous();
	Class::Sym_VLoadout		= TSoftClassPtr<USym_VLoadout>(FSoftClassPath("/Game/class/ui/Sym_UserVLoadoutC.Sym_UserVLoadoutC_C")).LoadSynchronous();
	Class::Sym_VUser		= TSoftClassPtr<USym_VUser>(FSoftClassPath("/Game/class/ui/Sym_UserViewC.Sym_UserViewC_C")).LoadSynchronous();
	Class::Sym_VUserEntry	= TSoftClassPtr<USym_VUserEntry>(FSoftClassPath("/Game/class/ui/Sym_UserViewEntryC.Sym_UserViewEntryC_C")).LoadSynchronous();

	Class::WRI_Alpha		= TSoftClassPtr<UWRI_Alpha>(FSoftClassPath("/Game/class/ui/writer/WRI_AlphaC.WRI_AlphaC_C")).LoadSynchronous();
	Class::WRI_AlphaOpt		= TSoftClassPtr<UWRI_AlphaOpt>(FSoftClassPath("/Game/class/ui/writer/WRI_AlphaOptC.WRI_AlphaOptC_C")).LoadSynchronous();
	Class::WRI_VAtlas		= TSoftClassPtr<UWRI_VAtlas>(FSoftClassPath("/Game/class/ui/writer/WRI_VAtlasC.WRI_VAtlasC_C")).LoadSynchronous();
	Class::WRI_VForm		= TSoftClassPtr<UWRI_VForm>(FSoftClassPath("/Game/class/ui/writer/WRI_VFormC.WRI_VFormC_C")).LoadSynchronous();
	Class::WRI_VFormEForm	= TSoftClassPtr<UWRI_VFormEForm>(FSoftClassPath("/Game/class/ui/writer/WRI_VFormEFormC.WRI_VFormEFormC_C")).LoadSynchronous();
	Class::WRI_VFormEntry	= TSoftClassPtr<UWRI_VFormEntry>(FSoftClassPath("/Game/class/ui/writer/WRI_VFormEntryC.WRI_VFormEntryC_C")).LoadSynchronous();
	Class::WRI_VSetup		= TSoftClassPtr<UWRI_VSetup>(FSoftClassPath("/Game/class/ui/writer/WRI_VSetupC.WRI_VSetupC_C")).LoadSynchronous();
	Class::WRI_VSetupEntry	= TSoftClassPtr<UWRI_VSetupEntry>(FSoftClassPath("/Game/class/ui/writer/WRI_VSetupEntryC.WRI_VSetupEntryC_C")).LoadSynchronous();
}

bool ClassC::IsSetup()
{
	return Class::Setup_;
}

TSubclassOf<UCharacterA> ClassC::F_CharacterA()					{ return Class::F_CharacterA; }
TSubclassOf<ACharacter3D> ClassC::F_Character3D()				{ return Class::F_Character3D; }


TSubclassOf<UUi> ClassC::U_Ui()									{ return Class::U_Ui; }

TSubclassOf<UCNS_Alpha> ClassC::CNS_Alpha()						{ return Class::CNS_Alpha; }

TSubclassOf<UFF_Bool> ClassC::FF_Bool()							{ return Class::FF_Bool; }
TSubclassOf<UFF_Link> ClassC::FF_Link()							{ return Class::FF_Link; }
TSubclassOf<UFF_LinkList> ClassC::FF_LinkList()					{ return Class::FF_LinkList; }
TSubclassOf<UFF_Text> ClassC::FF_Text()							{ return Class::FF_Text; }

TSubclassOf<ULOG_Alpha> ClassC::LOG_Alpha()						{ return Class::LOG_Alpha; }
TSubclassOf<UPLS_Alpha> ClassC::PLS_Alpha()						{ return Class::PLS_Alpha; }

TSubclassOf<USym_Master> ClassC::Sym_Master()					{ return Class::Sym_Master; }
TSubclassOf<USym_VLoadout> ClassC::Sym_VLoadout()				{ return Class::Sym_VLoadout; }
TSubclassOf<USym_VUser> ClassC::Sym_VUser()						{ return Class::Sym_VUser; }
TSubclassOf<USym_VUserEntry> ClassC::Sym_VUserEntry()			{ return Class::Sym_VUserEntry; }

TSubclassOf<UTim_Master> ClassC::Tim_Master()					{ return Class::Tim_Master; }
TSubclassOf<UTim_VHome> ClassC::Tim_VHome()						{ return Class::Tim_VHome; }

TSubclassOf<UWRI_Alpha> ClassC::WRI_Alpha()					{ return Class::WRI_Alpha; }
TSubclassOf<UWRI_AlphaOpt> ClassC::WRI_AlphaOpt()			{ return Class::WRI_AlphaOpt; }
TSubclassOf<UWRI_VAtlas> ClassC::WRI_VAtlas()				{ return Class::WRI_VAtlas; }
TSubclassOf<UWRI_VForm> ClassC::WRI_VForm()					{ return Class::WRI_VForm; }
TSubclassOf<UWRI_VFormEForm> ClassC::WRI_VFormEForm()		{ return Class::WRI_VFormEForm; }
TSubclassOf<UWRI_VFormEntry> ClassC::WRI_VFormEntry()		{ return Class::WRI_VFormEntry; }
TSubclassOf<UWRI_VSetup> ClassC::WRI_VSetup()				{ return Class::WRI_VSetup; }
TSubclassOf<UWRI_VSetupEntry> ClassC::WRI_VSetupEntry()		{ return Class::WRI_VSetupEntry; }