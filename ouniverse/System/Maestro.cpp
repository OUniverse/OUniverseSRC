//Copyright 2015-2019, All Rights Reserved.

#include "System/Maestro.h"
#include "Protocol/GlobalP.h"
#include "Protocol/SymP.h"
#include "Protocol/OpenWorldP.h"
#include "System/Major.h"

#include "Min/DebugM.h"


MaestroC* MaestroC::Create(MajorC* Major)
{
	return new MaestroC(Major);
}

MaestroC::MaestroC(MajorC* Major)
{
	InputStackLen_ = 0;

	GlobalP_ = new GlobalP(ProtocolUID::Global);
	SymP_ = new SymP(ProtocolUID::Sym);
	OpenWorldP_ = new OpenWorldP(ProtocolUID::OpenWorld);

}

void MaestroC::Start()
{

}

InputReplyS MaestroC::OnCommand(InputSchemaC::Commands Command, bool UpDown, bool PostUI)
{
	InputReplyS Reply = InputReplyS(true,true);

	for (int i = 0; i < InputStackLen_; i++)
	{
		InputStack_[i]->OnCommandInternal(&Reply, Command, UpDown, PostUI);
	}

	return Reply;
}