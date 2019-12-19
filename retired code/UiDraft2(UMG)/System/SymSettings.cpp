//Copyright 2015-2019, All Rights Reserved.

#include "Ui/System/SymSettings.h"
#include "System/Class.h"

void USYM_Settings::NativeConstruct()
{
	Super::NativeConstruct();
}

USYM_Settings* USYM_Settings::Create(UUiView* InParentView)
{
	//USYM_Settings* Neu = CreateWidget<USYM_Settings>(InParentView->Scope(), ClassC::SYM_Settings());
	//Neu->Init(InParentView);
	//return Neu;
	return NULL;
}

void USYM_Settings::Init(UUiView* InParentView)
{
	ConstructView(InParentView);
}