//Copyright 2015-2019, All Rights Reserved.

#include "System/Maestro.h"
#include "Protocol/ProtocolREG.h"
#include "Protocol/FluxOp.h"
#include "System/Major.h"
#include "Ui/Ui.h"

#include "Protocol/Console/CnsPro.h"
#include "Protocol/System/SymPro.h"
#include "Protocol/GlobalPro.h"
#include "Protocol/WorldPro.h"
#include "Protocol/Writer/WriPro.h"

#include "System/Input.h"

MaestroC* MaestroC::Create()
{
	MaestroC* Obj = new MaestroC();
	return Obj;
}

MaestroC::MaestroC() : ProtocolC(ProtocolREG::Flux::FMaestro,this)
{

}

void MaestroC::Initialize(UMajor* Major)
{
	Ui_ = Major->Ui();

	FluxDockC* Dock_ = AddFluxDock(ProtocolREG::Dock::DMaestro, this);

	Console_ = ConsoleNewPro::Create(ProtocolREG::Flux::FConsole,Major);
	Dock_->AddFlux(Console_);
	System_ = SystemPro::Create(ProtocolREG::Flux::FSystem,Major);
	Dock_->AddFlux(System_);
	Writer_ = WriterPro::Create(ProtocolREG::Flux::FWriter, Major);
	Dock_->AddFlux(Writer_);
	Global_ = GlobalPro::Create(ProtocolREG::Flux::FGlobal, Major);
	Dock_->AddFlux(Global_);

}

void MaestroC::Start()
{
	ProSystem();
}

void MaestroC::ProSystem()
{
	FluxSwitchOpC* Op = FluxSwitchOpC::Create(this, ProtocolREG::Dock::DMaestro, ProtocolREG::Flux::FSystem);
	Op->DirectInputStack(this);
	Op->Run();
}

void MaestroC::ProWriter()
{
	FluxSwitchOpC* Op = FluxSwitchOpC::Create(this, ProtocolREG::Dock::DMaestro, ProtocolREG::Flux::FWriter);
	Op->DirectInputStack(this);
	Op->Run();
}