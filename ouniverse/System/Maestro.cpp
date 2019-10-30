//Copyright 2015-2019, All Rights Reserved.

#include "System/Maestro.h"
#include "System/Major.h"
#include "Ui/Ui.h"

#include "Protocol/GlobalPro.h"
#include "Protocol/WorldPro.h"
#include "Protocol/WriterPro.h"

UMaestro::UMaestro()
{

}


UMaestro* UMaestro::Create(UMajor* Major)
{
	UMaestro* Obj = NewObject<UMaestro>();
	Obj->Init(Major);
	return Obj;
}

void UMaestro::Init(UMajor* Major)
{
	Ui_ = Major->Ui();
	Global_ = UGlobalPro::Create();
	World_ = UWorldPro::Create(Major->Control(),Major->Cosmos());
	Writer_ = UWriterPro::Create();
	AddInputSchema(Global_);
}

void UMaestro::Start()
{

}

void UMaestro::FauxStart()
{
	AddInputSchema(World_);
	World_->Start();
}

void UMaestro::WriterStart()
{
	Ui_->OpenWriter();
}