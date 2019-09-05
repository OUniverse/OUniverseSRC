//Copyright 2015-2019, All Rights Reserved.

#include "System/KeyCode.h"

#include "Min/DebugM.h"

KeyCodeC::KeyCodeC()
{
	KeyCode_ = -1;
}

int KeyCodeC::Out()
{
	return KeyCode_;
}
KeyCodeC::KeyCodeC(int InKeyCode)
{
	KeyCode_ = InKeyCode; 
}

bool KeyCodeC::operator<(const KeyCodeC& l) const
{
	return KeyCode_ < l.KeyCode_;
}

KeyCodeC::KeyCodeC(int InKeyCode, bool ShiftDN, bool CtrDN, bool AltDN)
{
	int V = InKeyCode;

	V = V*10;
	if (ShiftDN)
	{
		V++;
	}

	V = V*10;
	if (CtrDN)
	{
		V++;
	}

	V = V*10;
	if (AltDN)
	{
		V++;
	}

	KeyCode_ = V;
}