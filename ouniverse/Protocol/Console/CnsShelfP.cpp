//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Console/CnsShelfP.h"
#include "Protocol/Console/Ui/CnsShelfU.h"
#include "Protocol/Console/CnsPro.h"

#include "System/Scope.h"
#include "Class/ClassProtocol.h"

#include "System/InputID.h"

#include "Ui/Ui.h"

#include "Protocol/Focus.h"

#include "Protocol/Console/CnsLogP.h"
#include "Protocol/Console/CnsOutputP.h"



CnsShelfP::CnsShelfP(int InID, UUi* InUi, ConsoleNewPro* InPro) : ProtocolC(InID,this)
{
	Ui_ = InUi;
	Pro_ = InPro;

	FluxDockC* Dock_ = AddFluxDock(Dock::DShelf, this);

	CnsLog_ = new CnsLogP(Pro::PLog, this);
	Dock_->AddFlux(CnsLog_);
	CnsOutput_ = new CnsOutputP(Pro::POutput, this);
	Dock_->AddFlux(CnsOutput_);

	ODock_ = new FocusDockC(Focus::FDock, this);
	ODock_->SetPath(LeyS::Dir::Cancel, LeyS::Type::Move, Focus::FRack);

	RegisterFocus(ODock_);
	ODock_->Set(Dock_);

	ORack_ = new FocusUiRackC(Focus::FRack, this, true, false);
	RegisterFocus(ORack_);
}


void CnsShelfP::OpenConsole()
{
	View_ = CreateWidget<UCnsShelf>(ScopeC::World(), UClassProtocol::Get()->CnsShelfUI);
	Ui_->ToShelf(View_);
}

void CnsShelfP::CloseConsole()
{
	View_->RemoveFromParent();
}