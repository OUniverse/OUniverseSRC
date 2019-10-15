//Copyright 2015-2019, All Rights Reserved.

#include "System/Ui.h"
#include "System/Major.h"
#include "Ui/SymU.h"
#include "Ui/HudU.h"
#include "Ui/ConsoleU.h"


namespace GlobalSingleton
{
	UiC Ui;
}

UiC* UiC::Get()
{
	return &GlobalSingleton::Ui;
}

UiC* UiC::Create(MajorC* Major)
{
	GlobalSingleton::Ui = *(new UiC(Major));
	return &GlobalSingleton::Ui;
}

UiC::UiC()
{

}

UiC::UiC(MajorC* Major)
{
	SystemMenu_		= new SymU(Major->UserL(), Major->UserD(),Major->LoadoutL(), Major->LoadoutD(),Major->Oni());
	Hud_			= new HudU();
	Console_		= new ConsoleU(Major->Input());
}

void UiC::OpenSystemMenu()
{
	SystemMenu_->Open();
}

void UiC::OpenWriter()
{

}

void UiC::OpenHud()
{

}