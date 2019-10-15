//Copyright 2015-2019, All Rights Reserved.

#include "Ui/ConsoleU.h"
#include "System/Glass.h"
#include "System/InputManager.h"

#include "Min/DebugM.h"

ConsoleU::ConsoleU(InputManager* InInput)
{
	CommandE Event = InInput->ListenToCMD(InputManager::Layer::Menu, CommandLayerMenuC::CMD::Console);
	CMD_Console = *Event->Bind(Event->Create(this, &ConsoleU::OnConsoleKey));
	Open_ = false;
}

bool ConsoleU::Open()
{
	return Open_;
}

void ConsoleU::OnConsoleKey(StrokeS InStroke)
{
	if (InStroke.KeyDown())
	{
		if (!Open_)
		{
			GSEND1("console.open", true);
			Open_ = true;
		}
		else
		{
			GSEND1("console.open", false);
			Open_ = false;
		}
	}
}
