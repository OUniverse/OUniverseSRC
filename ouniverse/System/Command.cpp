//Copyright 2015-2019, All Rights Reserved.

#include "Command.h"

CommandC::CommandC()
{
	BoundKeyCode_ = -1;
}

void CommandC::SetBoundKey(int InBoundKey)
{
	BoundKeyCode_ = InBoundKey;
}

int CommandC::BoundKey()
{
	return BoundKeyCode_;
}

void CommandC::Trigger(StrokeS InStroke)
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, ID.ToString());
	Event_->Trigger(InStroke);
}