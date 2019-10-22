//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/ProtocolP.h"


ProtocolP::ProtocolP(int InUID)
{
	UID_ = InUID;
}

void ProtocolP::Mount()
{

}

void ProtocolP::Dismount()
{

}

InputReplyS* ProtocolP::OnCommandInternal(InputReplyS* Reply, InputSchemaC::Commands Command, bool UpDown, bool PostUI)
{
	if(Reply->Bubble())
	{
		OnCommand(Reply, Command, UpDown, PostUI);
	}

	return Reply;
}

InputReplyS* ProtocolP::OnCommand(InputReplyS* Reply, InputSchemaC::Commands Command, bool UpDown, bool PostUI)
{
	return Reply;
}