//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/WriBrassP.h"
#include "Protocol/Writer/Ui/WriBrassU.h"


WriBrassP::WriBrassP(int InID) : ProtocolC(InID,NULL)
{

}

void WriBrassP::ConstructUi(UWriBrass* InView)
{
	View_ = InView;
}