//Copyright 2015-2019, All Rights Reserved.

#include "System/Class.h"
#include "Form/CharacterA.h"
#include "Form/Character3D.h"

#include "Ui/Ui.h"
#include "Ui/Console_Max.h"
#include "Ui/Logv_Max.h"
#include "Ui/Pulse_Max.h"
#include "Ui/Sym_EmptyView.h"
#include "Ui/Sym_Max.h"
#include "Ui/Sym_UserData.h"
#include "Ui/Sym_UserList.h"
#include "Ui/Sym_UserView.h"
#include "Ui/Writer_Max.h"
#include "Ui/Writer_Head.h"
#include "Ui/Writer_AtlasView.h"
#include "Ui/Writer_AtlasList.h"
#include "Ui/Writer_AtlasData.h"
#include "Ui/Writer_FormView.h"
#include "Ui/Writer_FormList.h"
#include "Ui/Writer_FormData.h"

namespace Class
{
	bool Setup_ = false;
	TSubclassOf<UCharacterA> F_CharacterA;
	TSubclassOf<ACharacter3D> F_Character3D;
	

	TSubclassOf<UUi>					U_Ui;
	TSubclassOf<UConsole_Max>			Console_Max;
	TSubclassOf<ULogv_Max>				Logv_Max;
	TSubclassOf<UPulse_Max>				Pulse_Max;
	TSubclassOf<USym_EmptyView>			Sym_EmptyView;
	TSubclassOf<USym_Max>				Sym_Max;
	TSubclassOf<USym_UserData>			Sym_UserData;
	TSubclassOf<USym_UserList>			Sym_UserList;
	TSubclassOf<USym_UserView>			Sym_UserView;
	
	TSubclassOf<UWriter_AtlasView>		Writer_AtlasView;
	TSubclassOf<UWriter_AtlasList>		Writer_AtlasList;
	TSubclassOf<UWriter_AtlasData>		Writer_AtlasData;
	TSubclassOf<UWriter_FormView>		Writer_FormView;
	TSubclassOf<UWriter_FormList>		Writer_FormList;
	TSubclassOf<UWriter_FormData>		Writer_FormData;
	TSubclassOf<UWriter_Head>			Writer_Head;
	TSubclassOf<UWriter_Max>			Writer_Max;
}


void ClassC::Setup()
{
	Class::Setup_ = true;
	Class::F_CharacterA			= TSoftClassPtr<UCharacterA>(FSoftClassPath("/Game/class/form/ChracterA.ChracterA_C")).LoadSynchronous();
	Class::F_Character3D		= TSoftClassPtr<ACharacter3D>(FSoftClassPath("/Game/class/form/Character3D.Character3D_C")).LoadSynchronous();


	Class::U_Ui					= TSoftClassPtr<UUi>(FSoftClassPath("/Game/class/ui/Ui.Ui_C")).LoadSynchronous();
	Class::Console_Max			= TSoftClassPtr<UConsole_Max>(FSoftClassPath("/Game/class/ui/Console_Max.Console_Max_C")).LoadSynchronous();
	Class::Logv_Max				= TSoftClassPtr<ULogv_Max>(FSoftClassPath("/Game/class/ui/Logv_Max.Logv_Max_C")).LoadSynchronous();
	Class::Pulse_Max			= TSoftClassPtr<UPulse_Max>(FSoftClassPath("/Game/class/ui/Pulse_Max.Pulse_Max_C")).LoadSynchronous();
	Class::Sym_Max				= TSoftClassPtr<USym_Max>(FSoftClassPath("/Game/class/ui/Sym_Max.Sym_Max_C")).LoadSynchronous();
	Class::Sym_UserData			= TSoftClassPtr<USym_UserData>(FSoftClassPath("/Game/class/ui/Sym_UserData.Sym_UserData_C")).LoadSynchronous();
	Class::Sym_UserList			= TSoftClassPtr<USym_UserList>(FSoftClassPath("/Game/class/ui/Sym_UserList.Sym_UserList_C")).LoadSynchronous();
	Class::Sym_UserView			= TSoftClassPtr<USym_UserView>(FSoftClassPath("/Game/class/ui/Sym_UserView.Sym_UserView_C")).LoadSynchronous();
	
	Class::Writer_AtlasView		= TSoftClassPtr<UWriter_AtlasView>(FSoftClassPath("/Game/class/ui/Writer_AtlasView.Writer_AtlasView_C")).LoadSynchronous();
	Class::Writer_AtlasList		= TSoftClassPtr<UWriter_AtlasList>(FSoftClassPath("/Game/class/ui/Writer_AtlasList.Writer_AtlasList_C")).LoadSynchronous();
	Class::Writer_AtlasData		= TSoftClassPtr<UWriter_AtlasData>(FSoftClassPath("/Game/class/ui/Writer_AtlasData.Writer_AtlasData_C")).LoadSynchronous();
	Class::Writer_FormView		= TSoftClassPtr<UWriter_FormView>(FSoftClassPath("/Game/class/ui/Writer_FormView.Writer_FormView_C")).LoadSynchronous();
	Class::Writer_FormList		= TSoftClassPtr<UWriter_FormList>(FSoftClassPath("/Game/class/ui/Writer_FormList.Writer_FormList_C")).LoadSynchronous();
	Class::Writer_FormData		= TSoftClassPtr<UWriter_FormData>(FSoftClassPath("/Game/class/ui/Writer_FormData.Writer_FormData_C")).LoadSynchronous();
	Class::Writer_Head			= TSoftClassPtr<UWriter_Head>(FSoftClassPath("/Game/class/ui/Writer_Head.Writer_Head_C")).LoadSynchronous();
	Class::Writer_Max			= TSoftClassPtr<UWriter_Max>(FSoftClassPath("/Game/class/ui/Writer_Max.Writer_Max_C")).LoadSynchronous();
}

bool ClassC::IsSetup()
{
	return Class::Setup_;
}

TSubclassOf<UCharacterA> ClassC::F_CharacterA() { return Class::F_CharacterA; }
TSubclassOf<ACharacter3D> ClassC::F_Character3D() { return Class::F_Character3D; }


TSubclassOf<UUi> ClassC::U_Ui() { return Class::U_Ui; }
TSubclassOf<UConsole_Max> ClassC::Console_Max() { return Class::Console_Max; }
TSubclassOf<ULogv_Max> ClassC::Logv_Max() { return Class::Logv_Max; }
TSubclassOf<UWriter_Max> ClassC::Writer_Max() { return Class::Writer_Max; }
TSubclassOf<UWriter_Head> ClassC::Writer_Head() { return Class::Writer_Head; }
TSubclassOf<UWriter_AtlasView> ClassC::Writer_AtlasView() { return Class::Writer_AtlasView; }
TSubclassOf<UWriter_AtlasList> ClassC::Writer_AtlasList() { return Class::Writer_AtlasList; }
TSubclassOf<UWriter_AtlasData> ClassC::Writer_AtlasData() { return Class::Writer_AtlasData; }
TSubclassOf<UWriter_FormView> ClassC::Writer_FormView() { return Class::Writer_FormView; }
TSubclassOf<UWriter_FormList> ClassC::Writer_FormList() { return Class::Writer_FormList; }
TSubclassOf<UWriter_FormData> ClassC::Writer_FormData() { return Class::Writer_FormData; }