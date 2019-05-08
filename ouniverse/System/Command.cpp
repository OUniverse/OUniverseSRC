//Copyright 2015-2019, All Rights Reserved.

#include "Command.h"

CommandC::CommandC()
{
	BoundKeyCode = -1;
}

void CommandC::Send(StrokeS InStroke)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, ID.ToString());
	Call.ExecuteIfBound(InStroke);
}