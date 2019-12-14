//Copyright 2015-2019, All Rights Reserved.

#include "System/Class.h"
#include "Form/CharacterA.h"
#include "Form/Character3D.h"

#include "Ui/Ui.h"
#include "Ui/Console/ConShelf.h"
#include "Ui/Console/ConShelf_LogEntry.h"
#include "Ui/Console/ConTray.h"

#include "Ui/FormField/FF_Bool.h"
#include "Ui/FormField/FF_Link.h"
#include "Ui/FormField/FF_LinkList.h"
#include "Ui/FormField/FF_Text.h"

#include "Ui/Shared/Pulse.h"

#include "Ui/System/Sym.h"
#include "Ui/System/SYM_UserSelect_Le.h"

#include "Ui/Writer/Wri.h"
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


	TSubclassOf<UFF_Bool>				FF_Bool;
	TSubclassOf<UFF_Link>				FF_Link;
	TSubclassOf<UFF_LinkList>			FF_LinkList;
	TSubclassOf<UFF_Text>				FF_Text;

	TSubclassOf<UConTray>				ConTray;
	TSubclassOf<UConShelf>				ConShelf;
	TSubclassOf<UConShelf_LogEntry>		ConShelf_LogEntry;
	TSubclassOf<UPLS_Alpha>					PLS_Alpha;

	TSubclassOf<USystemUi>						SYM_Alpha;
	TSubclassOf<USYM_UserSelect_Le>			SYM_UserSelect_Le;
		
	TSubclassOf<UWRI>					WRI_Alpha;
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


	Class::U_Ui			= TSoftClassPtr<UUi>(FSoftClassPath("/Game/class/ui/Ui.Ui_C")).LoadSynchronous();

	Class::FF_Bool		= TSoftClassPtr<UFF_Bool>(FSoftClassPath("/Game/class/ui/FormField/FF_BoolC.FF_BoolC_C")).LoadSynchronous();
	Class::FF_Link		= TSoftClassPtr<UFF_Link>(FSoftClassPath("/Game/class/ui/FormField/FF_LinkC.FF_LinkC_C")).LoadSynchronous();
	Class::FF_LinkList	= TSoftClassPtr<UFF_LinkList>(FSoftClassPath("/Game/class/ui/FormField/FF_LinkListC.FF_LinkListC_C")).LoadSynchronous();
	Class::FF_Text		= TSoftClassPtr<UFF_Text>(FSoftClassPath("/Game/class/ui/FormField/FF_TextC.FF_TextC_C")).LoadSynchronous();


	Class::ConShelf				= TSoftClassPtr<UConShelf>(FSoftClassPath("/Game/class/ui/console/ConShelf.ConShelf_C")).LoadSynchronous();
	Class::ConShelf_LogEntry	= TSoftClassPtr<UConShelf_LogEntry>(FSoftClassPath("/Game/class/ui/console/ConShelf_LogEntry.ConShelf_LogEntry_C")).LoadSynchronous();
	Class::ConTray				= TSoftClassPtr<UConTray>(FSoftClassPath("/Game/class/ui/console/ConTray.ConTray_C")).LoadSynchronous();

	Class::PLS_Alpha				= TSoftClassPtr<UPLS_Alpha>(FSoftClassPath("/Game/class/ui/pulse/PLS_AlphaC.PLS_AlphaC_C")).LoadSynchronous();

	Class::SYM_Alpha				= TSoftClassPtr<USystemUi>(FSoftClassPath("/Game/class/ui/system/Sym.Sym_C")).LoadSynchronous();
	Class::SYM_UserSelect_Le		= TSoftClassPtr<USYM_UserSelect_Le>(FSoftClassPath("/Game/class/ui/system/SYM_UserSelect_LeC.SYM_UserSelect_LeC_C")).LoadSynchronous();

	Class::WRI_Alpha				= TSoftClassPtr<UWRI>(FSoftClassPath("/Game/class/ui/writer/WRI_AlphaC.WRI_AlphaC_C")).LoadSynchronous();
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

TSubclassOf<UConShelf> ClassC::ConShelf()						{ return Class::ConShelf; }
TSubclassOf<UConShelf_LogEntry> ClassC::ConShelf_LogEntry()		{ return Class::ConShelf_LogEntry; }
TSubclassOf<UConTray> ClassC::ConTray()							{ return Class::ConTray; }


TSubclassOf<UFF_Bool> ClassC::FF_Bool()							{ return Class::FF_Bool; }
TSubclassOf<UFF_Link> ClassC::FF_Link()							{ return Class::FF_Link; }
TSubclassOf<UFF_LinkList> ClassC::FF_LinkList()					{ return Class::FF_LinkList; }
TSubclassOf<UFF_Text> ClassC::FF_Text()							{ return Class::FF_Text; }

TSubclassOf<UPLS_Alpha> ClassC::PLS_Alpha()									{ return Class::PLS_Alpha; }

TSubclassOf<USystemUi> ClassC::SYM_Alpha()									{ return Class::SYM_Alpha; }
TSubclassOf<USYM_UserSelect_Le> ClassC::SYM_UserSelect_Le()				{ return Class::SYM_UserSelect_Le; }


TSubclassOf<UWRI> ClassC::WRI_Alpha()								{ return Class::WRI_Alpha; }
TSubclassOf<UWRI_AtlasEdit> ClassC::WRI_AtlasEdit()						{ return Class::WRI_AtlasEdit; }
TSubclassOf<UWRI_AtlasMount> ClassC::WRI_AtlasMount()					{ return Class::WRI_AtlasMount; }
TSubclassOf<UWRI_FormEdit> ClassC::WRI_FormEdit()						{ return Class::WRI_FormEdit; }
TSubclassOf<UWRI_FormEdit_Form> ClassC::WRI_FormEdit_Form()				{ return Class::WRI_FormEdit_Form; }
TSubclassOf<UWRI_FormEdit_Le> ClassC::WRI_FormEdit_Le()					{ return Class::WRI_FormEdit_Le; }
TSubclassOf<UWRI_Loadout> ClassC::WRI_Loadout()							{ return Class::WRI_Loadout; }
TSubclassOf<UWRI_Loadout_Le> ClassC::WRI_Loadout_Le()					{ return Class::WRI_Loadout_Le; }
TSubclassOf<UWRI_Main> ClassC::WRI_Main()								{ return Class::WRI_Main; }
TSubclassOf<UWRI_Splash> ClassC::WRI_Splash()							{ return Class::WRI_Splash; }