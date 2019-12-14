//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/System/SymMenuP.h"
#include "Class/ClassProtocol.h"
#include "System/Scope.h"
#include "System/InputID.h"

#include "Ui/Ui.h"

#include "Protocol/System/SymPro.h"
#include "Protocol/System/Ui/SymMenuU.h"
#include "Ui/UiButtonNew.h"
#include "Protocol/Focus.h"

#include "Protocol/System/SymUserSelectP.h"
#include "Protocol/System/SymUserCreateP.h"
#include "Protocol/System/SymUserEditP.h"

#include "Protocol/System/Ui/SymUserSelectU.h"


SymMenuP::SymMenuP(int InID, SystemPro* InPro) : ProtocolC(InID,this)
{
	Pro_ = InPro;

	ORack_ = new FocusUiRackC(Focus::FRack, this, true, false);
	RegisterFocus(ORack_);

}

void SymMenuP::ConstructUi(USymMenu* InView)
{
	View_ = InView;
	View_->UiConstruct(this);
}

bool SymMenuP::InputCommand(KeyS InKey)
{
	return FocalInputCommand(InKey);
}

void SymMenuP::FluxOpen_Technical(FluxSwitchOpC* InOp)
{
	View_->Show();
	ORack_->Reset();
	ORack_->Add(View_->V_NewGame, Focus::FRackNewGame);
	ORack_->Add(View_->V_Continue, Focus::FRackContinue);
	ORack_->Add(View_->V_User, Focus::FRackUser);
	ORack_->Add(View_->V_Loadout, Focus::FRackLoadout);
	ORack_->Add(View_->V_Trophey, Focus::FRackTrophey);
	ORack_->Add(View_->V_Settings, Focus::FRackSettings);
	ORack_->Add(View_->V_Update, Focus::FRackUpdate);
	ORack_->Add(View_->V_Credits, Focus::FRackCredits);
	ORack_->Add(View_->V_News, Focus::FRackNews);
	ORack_->Add(View_->V_Scribe, Focus::FRackScribe);

	FocalActivate(Focus::FRack);
}

void SymMenuP::FluxClose_Technical(FluxSwitchOpC* InOp)
{
	View_->Hide();
}


void SymMenuP::AcceptUser()
{
	Pro_->GoUser();
}

void SymMenuP::AcceptWriter()
{
	Pro_->GoWriter();
}