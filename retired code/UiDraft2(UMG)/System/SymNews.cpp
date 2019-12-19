//Copyright 2015-2019, All Rights Reserved.

#include "Ui/System/SymNews.h"
#include "System/Class.h"

#include "Ui/System/Sym.h"

void USYM_News::NativeConstruct()
{
	Super::NativeConstruct();
}

USYM_News* USYM_News::Create(UUiView* InParentView)
{
	//USYM_News* Neu = CreateWidget<USYM_News>(InParentView->Scope(), ClassC::SYM_News());
	//Neu->Init(InParentView);
	//return Neu;
	return NULL;
}

void USYM_News::Init(UUiView* InParentView)
{
	ConstructView(InParentView);
}