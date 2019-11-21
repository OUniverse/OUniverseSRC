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

#include "Ui/System/SYM_Alpha.h"
#include "Ui/System/SYM_AlphaOpt.h"
#include "Ui/System/SYM_VMainVLoadout.h"
#include "Ui/System/SYM_VMain.h"
#include "Ui/System/SYM_VMainVUser.h"
#include "Ui/System/SYM_VMainVUserEntry.h"
#include "Ui/System/SYM_VUser.h"
#include "Ui/System/SYM_VUserVCreate.h"
#include "Ui/System/SYM_VUserVSelect.h"

#include "Ui/Title/TIM_Alpha.h"
#include "Ui/Title/TIM_VMain.h"
#include "Ui/Title/TIM_VMainVHome.h"
#include "Ui/Title/TIM_VMainVLoad.h"
#include "Ui/Title/TIM_VMainVPre.h"

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

	TSubclassOf<USYM_Alpha>				SYM_Alpha;
	TSubclassOf<USYM_AlphaOpt>			SYM_AlphaOpt;
	TSubclassOf<USYM_VMain>				SYM_VMain;
	TSubclassOf<USYM_VMainVLoadout>		SYM_VMainVLoadout;
	TSubclassOf<USYM_VMainVUser>		SYM_VMainVUser;
	TSubclassOf<USYM_VMainVUserEntry>	SYM_VUserEntry;
	TSubclassOf<USYM_VUser>				SYM_VUser;
	TSubclassOf<USYM_VUserVCreate>		SYM_VUserVCreate;
	TSubclassOf<USYM_VUserVSelect>		SYM_VUserVSelect;

	TSubclassOf<UTIM_Alpha>				TIM_Alpha;
	TSubclassOf<UTIM_VMain>				TIM_VMain;
	TSubclassOf<UTIM_VMainVHome>		TIM_VMainVHome;
	TSubclassOf<UTIM_VMainVLoad>		TIM_VMainVLoad;
	TSubclassOf<UTIM_VMainVPre>			TIM_VMainVPre;

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

	Class::SYM_Alpha			= TSoftClassPtr<USYM_Alpha>(FSoftClassPath("/Game/class/ui/system/SYM_AlphaC.SYM_AlphaC_C")).LoadSynchronous();
	Class::SYM_AlphaOpt			= TSoftClassPtr<USYM_AlphaOpt>(FSoftClassPath("/Game/class/ui/system/SYM_AlphaOptC.SYM_AlphaOptC_C")).LoadSynchronous();
	Class::SYM_VMain			= TSoftClassPtr<USYM_VMain>(FSoftClassPath("/Game/class/ui/system/SYM_VMainC.SYM_VMainC_C")).LoadSynchronous();
	Class::SYM_VMainVLoadout	= TSoftClassPtr<USYM_VMainVLoadout>(FSoftClassPath("/Game/class/ui/system/SYM_VMainVLoadoutC.SYM_VMainVLoadoutC_C")).LoadSynchronous();
	Class::SYM_VMainVUser		= TSoftClassPtr<USYM_VMainVUser>(FSoftClassPath("/Game/class/ui/system/SYM_VMainVUserC.SYM_VMainVUserC_C")).LoadSynchronous();
	Class::SYM_VUserEntry		= TSoftClassPtr<USYM_VMainVUserEntry>(FSoftClassPath("/Game/class/ui/system/SYM_VUserEntryC.SYM_VUserEntryC_C")).LoadSynchronous();
	Class::SYM_VUser			= TSoftClassPtr<USYM_VUser>(FSoftClassPath("/Game/class/ui/system/SYM_VUserC.SYM_VUserC_C")).LoadSynchronous();
	Class::SYM_VUserVCreate		= TSoftClassPtr<USYM_VUserVCreate>(FSoftClassPath("/Game/class/ui/system/SYM_VUserVCreateC.SYM_VUserVCreateC_C")).LoadSynchronous();
	Class::SYM_VUserVSelect		= TSoftClassPtr<USYM_VUserVSelect>(FSoftClassPath("/Game/class/ui/system/SYM_VUserVSelectC.SYM_VUserVSelectC_C")).LoadSynchronous();

	Class::TIM_Alpha			= TSoftClassPtr<UTIM_Alpha>(FSoftClassPath("/Game/class/ui/title/TIM_AlphaC.TIM_AlphaC_C")).LoadSynchronous();
	Class::TIM_VMain			= TSoftClassPtr<UTIM_VMain>(FSoftClassPath("/Game/class/ui/title/TIM_VMainC.TIM_VMainC_C")).LoadSynchronous();
	Class::TIM_VMainVHome		= TSoftClassPtr<UTIM_VMainVHome>(FSoftClassPath("/Game/class/ui/title/TIM_VMainVHomeC.TIM_VMainVHomeC_C")).LoadSynchronous();
	Class::TIM_VMainVLoad		= TSoftClassPtr<UTIM_VMainVLoad>(FSoftClassPath("/Game/class/ui/title/TIM_VMainVLoadC.TIM_VMainVLoadC_C")).LoadSynchronous();
	Class::TIM_VMainVPre		= TSoftClassPtr<UTIM_VMainVPre>(FSoftClassPath("/Game/class/ui/title/TIM_VMainVPreC.TIM_VMainVPreC_C")).LoadSynchronous();

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

TSubclassOf<USYM_Alpha> ClassC::SYM_Alpha()						{ return Class::SYM_Alpha; }
TSubclassOf<USYM_AlphaOpt> ClassC::SYM_AlphaOpt()				{ return Class::SYM_AlphaOpt; }
TSubclassOf<USYM_VMain> ClassC::SYM_VMain()						{ return Class::SYM_VMain; }
TSubclassOf<USYM_VMainVLoadout> ClassC::SYM_VMainVLoadout()		{ return Class::SYM_VMainVLoadout; }
TSubclassOf<USYM_VMainVUserEntry> ClassC::SYM_VUserEntry()		{ return Class::SYM_VUserEntry; }
TSubclassOf<USYM_VUser> ClassC::SYM_VUser()						{ return Class::SYM_VUser; }
TSubclassOf<USYM_VUserVCreate> ClassC::SYM_VUserVCreate()		{ return Class::SYM_VUserVCreate; }
TSubclassOf<USYM_VUserVSelect> ClassC::SYM_VUserVSelect()		{ return Class::SYM_VUserVSelect; }

TSubclassOf<UTIM_Alpha> ClassC::TIM_Alpha()						{ return Class::TIM_Alpha; }
TSubclassOf<UTIM_VMain> ClassC::TIM_VMain()						{ return Class::TIM_VMain; }
TSubclassOf<UTIM_VMainVHome> ClassC::TIM_VMainVHome()			{ return Class::TIM_VMainVHome; }
TSubclassOf<UTIM_VMainVLoad> ClassC::TIM_VMainVLoad()			{ return Class::TIM_VMainVLoad; }
TSubclassOf<UTIM_VMainVPre> ClassC::TIM_VMainVPre()				{ return Class::TIM_VMainVPre; }

TSubclassOf<UWRI_Alpha> ClassC::WRI_Alpha()						{ return Class::WRI_Alpha; }
TSubclassOf<UWRI_AlphaOpt> ClassC::WRI_AlphaOpt()				{ return Class::WRI_AlphaOpt; }
TSubclassOf<UWRI_VAtlas> ClassC::WRI_VAtlas()					{ return Class::WRI_VAtlas; }
TSubclassOf<UWRI_VForm> ClassC::WRI_VForm()						{ return Class::WRI_VForm; }
TSubclassOf<UWRI_VFormEForm> ClassC::WRI_VFormEForm()			{ return Class::WRI_VFormEForm; }
TSubclassOf<UWRI_VFormEntry> ClassC::WRI_VFormEntry()			{ return Class::WRI_VFormEntry; }
TSubclassOf<UWRI_VSetup> ClassC::WRI_VSetup()					{ return Class::WRI_VSetup; }
TSubclassOf<UWRI_VSetupEntry> ClassC::WRI_VSetupEntry()			{ return Class::WRI_VSetupEntry; }