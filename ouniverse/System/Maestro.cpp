//Copyright 2015-2019, All Rights Reserved.

#include "System/Maestro.h"
#include "System/Major.h"

#include "Protocol/GlobalPro.h"
#include "Protocol/WorldPro.h"

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
	Global_ = UGlobalPro::Create();
	World_ = UWorldPro::Create(Major->Control(),Major->Cosmos());
	Add(Global_);
}

void UMaestro::Start()
{

}

void UMaestro::FauxStart()
{
	Add(World_);
	World_->Start();
}