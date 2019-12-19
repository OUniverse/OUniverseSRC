//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/WriDataLoadP.h"
#include "Protocol/Writer/Ui/WriDataLoadU.h"
#include "Protocol/Writer/WriPro.h"
#include "Protocol/Writer/Ex/WriData.h"

#include "System/InputID.h"

#include "Ui/Ui.h"

#include "Ui/UiButton.h"
#include "Protocol/Focus.h"

#include <thread>   

WriDataLoadP::WriDataLoadP(int InID, WriterPro* InPro, WriDataC* InWriData) : ProtocolC(InID,this)
{
	Pro_ = InPro;
	WriData_ = InWriData;
}

void WriDataLoadP::ConstructUi(UWriDataLoad* InView)
{
	View_ = InView;
	View_->UiConstruct(this);
	//View_->UiConstruct(this);
}

void WriDataLoadP::FluxOpen_Technical(FluxSwitchOpC* InOp)
{
	View_->Show();
	
	View_->LoadStart();
	std::thread first(LoadThread, WriData_);
	first.join();
	View_->LoadEnd();
}

void WriDataLoadP::FluxClose_Technical(FluxSwitchOpC* InOp)
{
	View_->Hide();
}

void WriDataLoadP::LoadThread(WriDataC* InWriData)
{
	InWriData->Mount();
}

void WriDataLoadP::LoadingAnimationComplete()
{
	Pro_->GoMain();
}