//Copyright 2015-2019, All Rights Reserved.

#include "Command.h"

UCommand::UCommand()
{
	BoundKeyCode = -1;
}

void UCommand::Send(FStroke Stroke)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, ID.ToString());
	Call.ExecuteIfBound(Stroke);
}