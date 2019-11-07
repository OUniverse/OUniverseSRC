//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer_Master.h"
#include "System/AtlasLib.h"
#include "System/Class.h"
#include "Ui/Ui_Viewer.h"
#include "Ui/Ui_ViewPanel.h"

UWriter_Master* UWriter_Master::Create(UWorld* InScope, AtlasLibC* InAtlasLib)
{
	return NULL;
}
void UWriter_Master::Init(AtlasLibC* InAtlasLib)
{

}

void UWriter_Master::ResponseBP(UViewPanel* InViewPanel)
{

}

TArray<UAtlas*>	UWriter_Master::GetAtlasiPre()
{
	return PreAtlasi_;
}

