//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/WriFooterP.h"
#include "Protocol/Writer/Ui/WriFooterU.h"

#include "Protocol/Writer/WriBrassP.h"



WriFooterP::WriFooterP(int InID, WriterPro* InPro) : ProtocolC(InID,this)
{
	Pro_ = InPro;
	WriBrass_ = new WriBrassP(Pro::PBrass);

}

void WriFooterP::ConstructUi(UWriFooter* InView)
{
	View_ = InView;
	//View_->UiConstruct(this);
	WriBrass_->ConstructUi(View_->vBrass);
}