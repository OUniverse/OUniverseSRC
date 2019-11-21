//Copyright 2015-2019, All Rights Reserved.

#include "Ui/System/SYM_AlphaOpt.h"
#include "Ui/System/SYM_Alpha.h"

#include "System/Class.h"

#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Ui/Ui_Catch.h"


USYM_AlphaOpt* USYM_AlphaOpt::Create(UWorld* InScope, UUi_View* InView, int InViewUID, int BabelUID)
{
	USYM_AlphaOpt* Neu = NewObject<USYM_AlphaOpt>(InScope, ClassC::SYM_AlphaOpt());
	Neu->SetView(InView);
	Neu->ViewUID_ = InViewUID;
	Neu->BabelID_ = BabelUID;
	return Neu;
}

void USYM_AlphaOpt::NativeConstruct()
{
	V_Text->SetText(BabelString(BabelID_));
	V_Catch->SetRelay(this);
	CastedView_ = Cast<USYM_Alpha>(View_);
	Super::NativeConstruct();
}

void USYM_AlphaOpt::Clicked()
{
	//CastedView_->SwitchView(USYM_Alpha::ViewPanels::Main, ViewUID_, false);
}

