//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/ConsolePro.h"
#include "Ui/Ui.h"
#include "System/Major.h"

#include "Ui/Console/ConTray.h"
#include "Ui/Console/ConShelf.h"

ConsolePro* ConsolePro::Create(int InID, UMajor* InMajor)
{
	ConsolePro* Neu = new ConsolePro(InID, InMajor);
	return Neu;
}

ConsolePro::ConsolePro(int InID, UMajor* InMajor) : ProtocolC(InID)
{
	bToggled = false;
	Major_ = InMajor;
	Ui_ = Major_->Ui();
}

void ConsolePro::Toggle()
{

	if (bToggled)
	{	
		bToggled = false;
		Tray_->RemoveFromParent();
		Shelf_->RemoveFromParent();
	}
	else
	{
		bToggled = true;
		Shelf_ = UConShelf::Create(this, Major_);
		Ui_->ToShelf(Shelf_);

		Tray_ = UConTray::Create(this);
		Ui_->ToTray(Tray_);
	}
}