//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/WriSplashP.h"
#include "Protocol/Writer/Ui/WriSplashU.h"
#include "Protocol/Writer/WriPro.h"

#include "System/InputID.h"

#include "Ui/Ui.h"

#include "Ui/UiButtonNew.h"
#include "Protocol/Focus.h"



WriSplashP::WriSplashP(int InID, WriterPro* InPro) : ProtocolC(InID,this)
{
	Pro_ = InPro;

	ORack_ = new FocusUiRackC(Focus::FRack, this, true, false);
	RegisterFocus(ORack_);
}

void WriSplashP::ConstructUi(UWriSplash* InView)
{
	View_ = InView;
	View_->UiConstruct(this);
	//View_->UiConstruct(this);
}

bool WriSplashP::InputCommand(KeyS InKey)
{
	return FocalInputCommand(InKey);
}

void WriSplashP::FluxOpen_Technical(FluxSwitchOpC* InOp)
{

	View_->Show();	
	ORack_->Reset();
	ORack_->Add(View_->V_Start, Focus::FStart);
	ORack_->Add(View_->V_Back, Focus::FBack);
	FocalActivate(Focus::FRack);

}

void WriSplashP::FluxClose_Technical(FluxSwitchOpC* InOp)
{
	View_->Hide();
}

void WriSplashP::AcceptStart()
{
	Pro_->GoMain();
}

void WriSplashP::AcceptBack()
{
	Pro_->EscWriter();
}