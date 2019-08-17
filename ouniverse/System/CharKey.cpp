//Copyright 2015-2019, All Rights Reserved.

#include "System/CharKey.h"
#include "System/ControlUE.h"

#include "Min/DebugM.h"

CharKey::CharKey(int InKeyCode, Handler InHandler, Modifier InModifier, StringC InID)
{
	ID_ = InID;
	KeyCode_ = InKeyCode;
	Handler_ = InHandler;
	Modifier_ = InModifier;
}


bool CharKey::IsValid(bool InCtr, bool InAlt)
{

	if (Modifier_ == Modifier::None)
	{
		return true;
	}

	if (Modifier_ == Modifier::CTR)
	{

		return InCtr;
		
	}


	if (Modifier_ == Modifier::ALT)
	{
		return InAlt;
	}

	if (Modifier_ == Modifier::CTRALT)
	{
		if (InCtr && InAlt)
		{
			return true;
		}
	}

	return false;
}