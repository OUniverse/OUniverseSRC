//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/WriBrassP.h"
#include "Protocol/Writer/Ui/WriBrassU.h"


WriBrassP::WriBrassP(int InID) : ProtocolC(InID,NULL)
{
	Lib_.Add(0, WriBrassS(142, 125125, 125125));
}

void WriBrassP::ConstructUi(UWriBrass* InView)
{
	View_ = InView;
}


void WriBrassP::BrassDisplay(int BrassID)
{
	View_->Display(&Lib_.Find(0));
}

void WriBrassP::BrassClear()
{
	View_->Clear();
}