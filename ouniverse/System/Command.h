//Copyright 2015-2019, All Rights Reserved.

/**
Commands represent functions that can be bound to a keypress.
For example "Jump" "Accept" "Interact" could all be commands.

A CommandC has an ID and a delegate which can broadcast.
If something wants to register for a keypress they add their trigger function to the delegate.
 */

#pragma once

#include "CoreMinimal.h"
#include "Delegates/IDelegateInstance.h"


struct StrokeS
{
	bool KeyDown;

	StrokeS()
	{
		KeyDown = false;
	}
	
	StrokeS(bool InKeyDown)
	{
		KeyDown = InKeyDown;
	}
};

DECLARE_DELEGATE_OneParam(DelegateCommand, StrokeS);

class OUNIVERSE_API CommandC
{

public:

	CommandC();
	DelegateCommand Call;
	FName ID;
	int32 BoundKeyCode;
	bool bAllowDuringTypeMode;
	void Send(StrokeS InStroke);
	//Beacon
};