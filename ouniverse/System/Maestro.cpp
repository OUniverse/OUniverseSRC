//Copyright 2015-2019, All Rights Reserved.

#include "System/Maestro.h"
#include "System/Major.h"

#include "Protocol/GlobalP.h"
#include "Protocol/WorldP.h"


MaestroC* MaestroC::Create(MajorC* Major)
{
	return new MaestroC(Major);
}

MaestroC::MaestroC(MajorC* Major)
{
	Global_ = new GlobalP();
	World_ = new WorldP(Major->Control(),Major->Cosmos());
	Add(Global_);
}

void MaestroC::Start()
{

}

void MaestroC::FauxStart()
{
	Add(World_);
	World_->Start();
}