//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Title/TIM_Alpha.h"

#include "UI/Title/TIM_Main.h"
#include "System/Class.h"
#include "UI/Ui.h"


namespace TIM_Mem
{
	bool FirstOpenComplete = false;
}



void UTIM_Alpha::NativeConstruct()
{
	//SetViewPanel(0, V_View);

	SwitchView(0, UTIM_Alpha::VMain);

	TIM_Mem::FirstOpenComplete = true;

	Super::NativeConstruct();
}


UTIM_Alpha* UTIM_Alpha::Create(UWorld* InScope, UUi* InUi, UserDaisC* InUserDais, LoadoutDaisC* InLoadoutDais, AtlasLibC* InAtlasLib)
{
	UTIM_Alpha* Neu = CreateWidget<UTIM_Alpha>(InScope, ClassC::TIM_Alpha());
	Neu->Init(InScope, InUi, InUserDais, InLoadoutDais,InAtlasLib);

	return Neu;
}

void UTIM_Alpha::Init(UWorld* InScope, UUi* InUi, UserDaisC* InUserDais, LoadoutDaisC* InLoadoutDais, AtlasLibC* InAtlasLib)
{
	ConstructAlpha(InScope, InUi);

	UserDais_ = InUserDais;
	LoadoutDais_ = InLoadoutDais;

	AddViewPanel(0);


	View_Main = UTIM_Main::Create(this,UserDais_,LoadoutDais_,InAtlasLib);
	AddView(0, UTIM_Alpha::VMain, View_Main);
}

void UTIM_Alpha::ToWriterMenu()
{
	Ui_->OpenWriterMenu();
}