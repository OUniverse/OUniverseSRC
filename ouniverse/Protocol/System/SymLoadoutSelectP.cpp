//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/System/SymLoadoutSelectP.h"
#include "System/InputID.h"

#include "Protocol/System/SymLoadoutMenuP.h"
#include "Protocol/System/Ui/SymLoadoutSelectU.h"

#include "Ui/UiButton.h"
#include "Protocol/System/Ui/SymLoadoutSelectU_Solodex.h"

#include "Protocol/Focus.h"

#include "Min/DebugM.h"

SymLoadoutSelectP::SymLoadoutSelectP(int InID, SymLoadoutMenuP* InPro, LoadoutLibC* InLoadoutLib) : ProtocolC(InID,this)
{
	Pro_ = InPro;
	LoadoutLib_ = InLoadoutLib;
	
	OSolodex_ = new FocusUiC(Foc::OSolodex,this);
	OSolodex_->SetPath(LeyS::Dir::Cancel, LeyS::Type::Event, Events::EscapeSolodex);
	RegisterFocus(OSolodex_);
}

void SymLoadoutSelectP::ConstructUi(USymLoadoutSelect* InView)
{
	View_ = InView;
}

void SymLoadoutSelectP::FluxOpen_Technical(FluxSwitchOpC* InOp)
{
	View_->Show();

	View_->UiConstruct(this, LoadoutLib_);
	OSolodex_->Set(View_->V_Solodex);
	FocalActivate(Foc::OSolodex);
}

void SymLoadoutSelectP::FluxClose_Technical(FluxSwitchOpC* InOp)
{
	View_->Hide();
}

bool SymLoadoutSelectP::InputCommand(KeyS InKey)
{
	return FocalInputCommand(InKey);
}

void SymLoadoutSelectP::EventCode(int ID, int EventID, int Var)
{
	switch (EventID) {
	case Events::EscapeSolodex:
		//Var here is Ley Direction
		Pro_->DockEscape();
		break;
	}
}