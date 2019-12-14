//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/System/SymUserSelectP.h"
#include "System/InputID.h"

#include "Protocol/System/SymUserMenuP.h"
#include "Protocol/System/Ui/SymUserSelectU.h"

#include "Ui/UiButtonNew.h"
#include "Protocol/System/Ui/SymUserSelectU_Solodex.h"

#include "Protocol/Focus.h"

#include "Min/DebugM.h"

SymUserSelectP::SymUserSelectP(int InID, SymUserMenuP* InPro, UserLibC* InUserLib) : ProtocolC(InID,this)
{
	Pro_ = InPro;
	UserLib_ = InUserLib;
	
	OSolodex_ = new FocusUiC(Foc::OSolodex,this);
	OSolodex_->SetPath(LeyS::Dir::Cancel, LeyS::Type::Event, Events::EscapeSolodex);
	RegisterFocus(OSolodex_);
}

void SymUserSelectP::ConstructUi(USymUserSelect* InView)
{
	View_ = InView;
}

void SymUserSelectP::FluxOpen_Technical(FluxSwitchOpC* InOp)
{
	View_->Show();

	View_->UiConstruct(this, UserLib_);
	OSolodex_->Set(View_->V_Solodex);
	FocalActivate(Foc::OSolodex);
}

void SymUserSelectP::FluxClose_Technical(FluxSwitchOpC* InOp)
{
	View_->Hide();
}

bool SymUserSelectP::InputCommand(KeyS InKey)
{
	return FocalInputCommand(InKey);
}

void SymUserSelectP::EventCode(int ID, int EventID, int Var)
{
	switch (EventID) {
	case Events::EscapeSolodex:
		//Var here is Ley Direction
		Pro_->DockEscape();
		break;
	}
}