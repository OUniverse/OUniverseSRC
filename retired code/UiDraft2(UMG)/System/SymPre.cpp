//Copyright 2015-2019, All Rights Reserved.

#include "Ui/System/SymPre.h"
#include "Ui/System/SymReg.h"

#include "Ui/UiMouseInput.h"


void USYM_Pre::Init(UUiView* InParentView)
{
	ConstructView(InParentView);
	V_Mouse->SetRelay(0, this);
}


FReply USYM_Pre::EventMouseClick(int ElementID, const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) 
{
	OwningView_->SwitchView(SYMREG::Docks::DAlpha, SYMREG::Views::VAtlasLoad);
	return FReply::Handled();
}