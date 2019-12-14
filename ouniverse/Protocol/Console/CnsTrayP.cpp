//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Console/CnsTrayP.h"
#include "Protocol/Console/Ui/CnsTrayU.h"
#include "Protocol/Console/CnsPro.h"

#include "System/Scope.h"
#include "Class/ClassProtocol.h"

#include "System/InputID.h"

#include "Ui/Ui.h"

#include "Protocol/Focus.h"




CnsTrayP::CnsTrayP(int InID, UUi* InUi, ConsoleNewPro* InPro) : ProtocolC(InID,this)
{
	Ui_ = InUi;
	Pro_ = InPro;
}

void CnsTrayP::OpenConsole()
{
	View_ = CreateWidget<UCnsTray>(ScopeC::World(), UClassProtocol::Get()->CnsTrayUI);
	Ui_->ToTray(View_);
}

void CnsTrayP::CloseConsole()
{
	View_->RemoveFromParent();
}