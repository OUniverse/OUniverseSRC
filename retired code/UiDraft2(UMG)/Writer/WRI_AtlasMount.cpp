//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer/WRI_AtlasMount.h"
#include <thread>     

void UWRI_AtlasMount::MountThread(UWRI* InAlpha)
{
	//InAlpha->OpenLoadout();
}

void UWRI_AtlasMount::Init(UUiView* InParentView)
{
	ConstructView(InParentView);

	//UWRI* CastedAlpha = Cast<UWRI>(Alpha());
	//MountingStart();
	//std::thread first(MountThread, CastedAlpha);
	//first.join();
}

void UWRI_AtlasMount::AnimationComplete()
{
	//OwningView_->SwitchView(0,UWRI_Main::VLoadout);
}