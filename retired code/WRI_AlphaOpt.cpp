//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer/WRI_AlphaOpt.h"
#include "Ui/Writer/WRI_Alpha.h"

#include "System/Class.h"

#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Ui/Ui_Catch.h"

#include "Min/DebugM.h"

UWRI_AlphaOpt* UWRI_AlphaOpt::Create(UWorld* InScope, UUi_View* InView, int InViewUID, int BabelUID)
{
	//UWRI_AlphaOpt* Neu = NewObject<UWRI_AlphaOpt>(InScope, ClassC::WRI_AlphaOpt());
	//Neu->SetView(InView);
	//Neu->ViewUID_ = InViewUID;
	//Neu->BabelID_ = BabelUID;
	return NULL;
}

void UWRI_AlphaOpt::NativeConstruct()
{
	V_Text->SetText(BabelString(BabelID_));
	//V_Catch->SetupInterface(this);
	CastedView_ = Cast<UWRI_Alpha>(View_);
	Super::NativeConstruct();
}

void UWRI_AlphaOpt::Clicked()
{
	//CastedView_->SwitchView(UWRI_Alpha::ViewPanels::Main, ViewUID_, false);
}