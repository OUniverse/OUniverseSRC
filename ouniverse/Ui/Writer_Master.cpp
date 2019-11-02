//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer_Master.h"
#include "System/AtlasLib.h"
#include "System/Class.h"

#include "Min/DebugM.h"

UWriter_Master* UWriter_Master::Create(UWorld* InScope, AtlasLibC* InAtlasLib)
{
	UWriter_Master* Neu = CreateWidget<UWriter_Master>(InScope, ClassC::Writer_Master());
	Neu->SetScope(InScope);
	Neu->Init(InAtlasLib);
	return Neu;
}
void UWriter_Master::Init(AtlasLibC* InAtlasLib)
{
	AtlasLib_ = InAtlasLib;
	PreAtlasi_ = AtlasLib_->Consulify();
	CreateViewer();
	Ready();
}

TArray<UAtlas*>	UWriter_Master::GetAtlasiPre()
{
	return PreAtlasi_;
}