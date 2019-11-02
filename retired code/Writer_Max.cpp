//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer_Max.h"
#include "System/AtlasLib.h"
#include "System/Class.h"

#include "Min/DebugM.h"

UWriter_Max* UWriter_Max::Create(UWorld* InScope, AtlasLibC* InAtlasLib)
{
	UWriter_Max* Neu = NULL;
	return Neu;
}
void UWriter_Max::Init(AtlasLibC* InAtlasLib)
{
	AtlasLib_ = InAtlasLib;
	PreAtlasi_ = AtlasLib_->Consulify();
	CreateViewer();
	Ready();
}

TArray<UAtlas*>	UWriter_Max::GetAtlasiPre()
{
	return PreAtlasi_;
}