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
#include "Ui/System/SYM_AtlasMount.h"
#include "Ui/System/SYM_Home.h"
#include "Ui/System/SYM_Loadout.h"
#include "Ui/System/SYM_Main.h"
#include "Ui/System/SYM_Pre.h"
#include "Ui/System/SYM_UserCreate.h"
#include "Ui/System/SYM_UserEdit.h"
#include "Ui/System/SYM_UserSelect.h"
#include "Ui/System/SYM_UserSelect_Le.h"

#include "Ui/Title/TIM_Alpha.h"
#include "Ui/Title/TIM_AtlasMount.h"
#include "Ui/Title/TIM_Home.h"
#include "Ui/Title/TIM_Main.h"
#include "Ui/Title/TIM_Pre.h"

#include "Ui/Writer/WRI_Alpha.h"
#include "Ui/Writer/WRI_AtlasEdit.h"
#include "Ui/Writer/WRI_AtlasMount.h"
#include "Ui/Writer/WRI_FormEdit.h"
#include "Ui/Writer/WRI_FormEdit_Le.h"
#include "Ui/Writer/WRI_Loadout.h"
#include "Ui/Writer/WRI_Loadout_Le.h"
#include "Ui/Writer/WRI_Main.h"
#include "Ui/Writer/WRI_Splash.h"
#include "Ui/Writer/WRI_VMainVFormEForm.h"




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

	TSubclassOf<ULOG_Alpha>					LOG_Alpha;
	TSubclassOf<UPLS_Alpha>					PLS_Alpha;

	TSubclassOf<USYM_Alpha>					SYM_Alpha;
	TSubclassOf<USYM_AtlasMount>			SYM_AtlasMount;
	TSubclassOf<USYM_Home>					SYM_Home;
	TSubclassOf<USYM_Loadout>				SYM_Loadout;
	TSubclassOf<USYM_Main>					SYM_Main;
	TSubclassOf<USYM_Pre>					SYM_Pre;
	TSubclassOf<USYM_UserCreate>			SYM_UserCreate;
	TSubclassOf<USYM_UserEdit>				SYM_UserEdit;
	TSubclassOf<USYM_UserSelect>			SYM_UserSelect;
	TSubclassOf<USYM_UserSelect_Le>			SYM_UserSelect_Le;
		

	TSubclassOf<UTIM_Alpha>					TIM_Alpha;
	TSubclassOf<UTIM_AtlasMount>			TIM_AtlasMount;
	TSubclassOf<UTIM_Home>					TIM_Home;
	TSubclassOf<UTIM_Main>					TIM_Main;
	TSubclassOf<UTIM_Pre>					TIM_Pre;

	TSubclassOf<UWRI_Alpha>					WRI_Alpha;
	TSubclassOf<UWRI_AtlasEdit>				WRI_AtlasEdit;
	TSubclassOf<UWRI_AtlasMount>			WRI_AtlasMount;
	TSubclassOf<UWRI_FormEdit>				WRI_FormEdit;
	TSubclassOf<UWRI_FormEdit_Form>			WRI_FormEdit_Form;
	TSubclassOf<UWRI_FormEdit_Le>			WRI_FormEdit_Le;
	TSubclassOf<UWRI_Loadout>				WRI_Loadout;
	TSubclassOf<UWRI_Loadout_Le>			WRI_Loadout_Le;
	TSubclassOf<UWRI_Main>					WRI_Main;
	TSubclassOf<UWRI_Splash>				WRI_Splash;
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


	Class::LOG_Alpha			= TSoftClassPtr<ULOG_Alpha>(FSoftClassPath("/Game/class/ui/log/LOG_AlphaC.LOG_AlphaC_C")).LoadSynchronous();

	Class::PLS_Alpha				= TSoftClassPtr<UPLS_Alpha>(FSoftClassPath("/Game/class/ui/pulse/PLS_AlphaC.PLS_AlphaC_C")).LoadSynchronous();

	Class::SYM_Alpha				= TSoftClassPtr<USYM_Alpha>(FSoftClassPath("/Game/class/ui/system/SYM_AlphaC.SYM_AlphaC_C")).LoadSynchronous();
	Class::SYM_AtlasMount			= TSoftClassPtr<USYM_AtlasMount>(FSoftClassPath("/Game/class/ui/system/SYM_AtlasMountC.SYM_AtlasMountC_C")).LoadSynchronous();
	Class::SYM_Home					= TSoftClassPtr<USYM_Home>(FSoftClassPath("/Game/class/ui/system/SYM_HomeC.SYM_HomeC_C")).LoadSynchronous();
	Class::SYM_Loadout				= TSoftClassPtr<USYM_Loadout>(FSoftClassPath("/Game/class/ui/system/SYM_LoadoutC.SYM_LoadoutC_C")).LoadSynchronous();
	Class::SYM_Main					= TSoftClassPtr<USYM_Main>(FSoftClassPath("/Game/class/ui/system/SYM_MainC.SYM_MainC_C")).LoadSynchronous();
	Class::SYM_Pre					= TSoftClassPtr<USYM_Pre>(FSoftClassPath("/Game/class/ui/system/SYM_PreC.SYM_PreC_C")).LoadSynchronous();
	Class::SYM_UserCreate			= TSoftClassPtr<USYM_UserCreate>(FSoftClassPath("/Game/class/ui/system/SYM_UserCreateC.SYM_UserCreateC_C")).LoadSynchronous();
	Class::SYM_UserEdit				= TSoftClassPtr<USYM_UserEdit>(FSoftClassPath("/Game/class/ui/system/SYM_UserEditC.SYM_UserEditC_C")).LoadSynchronous();
	Class::SYM_UserSelect			= TSoftClassPtr<USYM_UserSelect>(FSoftClassPath("/Game/class/ui/system/SYM_UserSelectC.SYM_UserSelectC_C")).LoadSynchronous();
	Class::SYM_UserSelect_Le		= TSoftClassPtr<USYM_UserSelect_Le>(FSoftClassPath("/Game/class/ui/system/SYM_UserSelect_LeC.SYM_UserSelect_LeC_C")).LoadSynchronous();

	Class::TIM_Alpha				= TSoftClassPtr<UTIM_Alpha>(FSoftClassPath("/Game/class/ui/title/TIM_AlphaC.TIM_AlphaC_C")).LoadSynchronous();
	Class::TIM_AtlasMount			= TSoftClassPtr<UTIM_AtlasMount>(FSoftClassPath("/Game/class/ui/title/TIM_AtlasMountC.TIM_AtlasMountC_C")).LoadSynchronous();
	Class::TIM_Home					= TSoftClassPtr<UTIM_Home>(FSoftClassPath("/Game/class/ui/title/TIM_HomeC.TIM_HomeC_C")).LoadSynchronous();
	Class::TIM_Main					= TSoftClassPtr<UTIM_Main>(FSoftClassPath("/Game/class/ui/title/TIM_MainC.TIM_MainC_C")).LoadSynchronous();
	Class::TIM_Pre					= TSoftClassPtr<UTIM_Pre>(FSoftClassPath("/Game/class/ui/title/TIM_PreC.TIM_PreC_C")).LoadSynchronous();

	Class::WRI_Alpha				= TSoftClassPtr<UWRI_Alpha>(FSoftClassPath("/Game/class/ui/writer/WRI_AlphaC.WRI_AlphaC_C")).LoadSynchronous();
	Class::WRI_AtlasEdit			= TSoftClassPtr<UWRI_AtlasEdit>(FSoftClassPath("/Game/class/ui/writer/WRI_AtlasEditC.WRI_AtlasEditC_C")).LoadSynchronous();
	Class::WRI_AtlasMount			= TSoftClassPtr<UWRI_AtlasMount>(FSoftClassPath("/Game/class/ui/writer/WRI_AtlasMountC.WRI_AtlasMountC_C")).LoadSynchronous();
	Class::WRI_FormEdit				= TSoftClassPtr<UWRI_FormEdit>(FSoftClassPath("/Game/class/ui/writer/WRI_FormEditC.WRI_FormEditC_C")).LoadSynchronous();
	Class::WRI_FormEdit_Form		= TSoftClassPtr<UWRI_FormEdit_Form>(FSoftClassPath("/Game/class/ui/writer/WRI_FormEdit_FormC.WRI_FormEdit_FormC_C")).LoadSynchronous();
	Class::WRI_FormEdit_Le			= TSoftClassPtr<UWRI_FormEdit_Le>(FSoftClassPath("/Game/class/ui/writer/WRI_FormEdit_LeC.WRI_FormEdit_LeC_C")).LoadSynchronous();
	Class::WRI_Loadout				= TSoftClassPtr<UWRI_Loadout>(FSoftClassPath("/Game/class/ui/writer/WRI_LoadoutC.WRI_LoadoutC_C")).LoadSynchronous();
	Class::WRI_Loadout_Le			= TSoftClassPtr<UWRI_Loadout_Le>(FSoftClassPath("/Game/class/ui/writer/WRI_Loadout_LeC.WRI_Loadout_LeC_C")).LoadSynchronous();
	Class::WRI_Main					= TSoftClassPtr<UWRI_Main>(FSoftClassPath("/Game/class/ui/writer/WRI_MainC.WRI_MainC_C")).LoadSynchronous();
	Class::WRI_Splash				= TSoftClassPtr<UWRI_Splash>(FSoftClassPath("/Game/class/ui/writer/WRI_SplashC.WRI_SplashC_C")).LoadSynchronous();
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

TSubclassOf<ULOG_Alpha> ClassC::LOG_Alpha()									{ return Class::LOG_Alpha; }
TSubclassOf<UPLS_Alpha> ClassC::PLS_Alpha()									{ return Class::PLS_Alpha; }

TSubclassOf<USYM_Alpha> ClassC::SYM_Alpha()									{ return Class::SYM_Alpha; }
TSubclassOf<USYM_AtlasMount> ClassC::SYM_AtlasMount()						{ return Class::SYM_AtlasMount; }
TSubclassOf<USYM_Home> ClassC::SYM_Home()									{ return Class::SYM_Home; }
TSubclassOf<USYM_Main> ClassC::SYM_Main()									{ return Class::SYM_Main; }
TSubclassOf<USYM_Pre> ClassC::SYM_Pre()								{ return Class::SYM_Pre; }
TSubclassOf<USYM_Loadout> ClassC::SYM_Loadout()								{ return Class::SYM_Loadout; }
TSubclassOf<USYM_UserSelect_Le> ClassC::SYM_UserSelect_Le()					{ return Class::SYM_UserSelect_Le; }
TSubclassOf<USYM_UserCreate> ClassC::SYM_UserCreate()						{ return Class::SYM_UserCreate; }
TSubclassOf<USYM_UserEdit> ClassC::SYM_UserEdit()							{ return Class::SYM_UserEdit; }
TSubclassOf<USYM_UserSelect> ClassC::SYM_UserSelect()						{ return Class::SYM_UserSelect; }

TSubclassOf<UTIM_Alpha> ClassC::TIM_Alpha()								{ return Class::TIM_Alpha; }
TSubclassOf<UTIM_Main> ClassC::TIM_Main()								{ return Class::TIM_Main; }
TSubclassOf<UTIM_Home> ClassC::TIM_Home()								{ return Class::TIM_Home; }
TSubclassOf<UTIM_AtlasMount> ClassC::TIM_AtlasMount()					{ return Class::TIM_AtlasMount; }
TSubclassOf<UTIM_Pre> ClassC::TIM_Pre()									{ return Class::TIM_Pre; }

TSubclassOf<UWRI_Alpha> ClassC::WRI_Alpha()								{ return Class::WRI_Alpha; }
TSubclassOf<UWRI_AtlasEdit> ClassC::WRI_AtlasEdit()						{ return Class::WRI_AtlasEdit; }
TSubclassOf<UWRI_AtlasMount> ClassC::WRI_AtlasMount()					{ return Class::WRI_AtlasMount; }
TSubclassOf<UWRI_FormEdit> ClassC::WRI_FormEdit()						{ return Class::WRI_FormEdit; }
TSubclassOf<UWRI_FormEdit_Form> ClassC::WRI_FormEdit_Form()				{ return Class::WRI_FormEdit_Form; }
TSubclassOf<UWRI_FormEdit_Le> ClassC::WRI_FormEdit_Le()					{ return Class::WRI_FormEdit_Le; }
TSubclassOf<UWRI_Loadout> ClassC::WRI_Loadout()							{ return Class::WRI_Loadout; }
TSubclassOf<UWRI_Loadout_Le> ClassC::WRI_Loadout_Le()					{ return Class::WRI_Loadout_Le; }
TSubclassOf<UWRI_Main> ClassC::WRI_Main()								{ return Class::WRI_Main; }
TSubclassOf<UWRI_Splash> ClassC::WRI_Splash()							{ return Class::WRI_Splash; }