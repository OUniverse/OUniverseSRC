//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Console/CnsPro.h"

#include "System/Maestro.h"
#include "Ui/Ui.h"
#include "System/Major.h"

#include "Protocol/Console/CnsShelfP.h"
#include "Protocol/Console/CnsTrayP.h"

ConsoleNewPro* ConsoleNewPro::Create(int InID, UMajor* InMajor) 
{
	ConsoleNewPro* Neu = new ConsoleNewPro(InID, InMajor);
	return Neu;
}

ConsoleNewPro::ConsoleNewPro(int InID, UMajor* InMajor) : ProtocolC(InID,this)
{
	bToggled = false;
	Major_ = InMajor;
	Maestro_ = Major_->Maestro();
	Ui_ = Major_->Ui();
	
	Shelf_ = new CnsShelfP(Pro::PTray,Ui_,this);
	Tray_ = new CnsTrayP(Pro::PShelf,Ui_,this);
}

void ConsoleNewPro::Toggle()
{
	if (bToggled)
	{
		bToggled = false;
		Tray_->CloseConsole();
		Shelf_->CloseConsole();
	}
	else
	{
		bToggled = true;
		Tray_->OpenConsole();
		Shelf_->OpenConsole();
	}
}