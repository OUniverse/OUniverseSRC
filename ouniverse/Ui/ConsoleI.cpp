//Copyright 2015-2019, All Rights Reserved.

#include "Ui/ConsoleI.h"
#include "System/Glass.h"

#include "System/InputManager.h"
#include "System/Command.h"

#include "cohtml/Binding/Binding.h"
#include "cohtml/Binding/EventHandler.h"
#include "CohtmlFStringBinder.h"


ConsoleIO::ConsoleIO(GlassC* InGlass, InputManager* InInput) : Io(InGlass)
{
	InputP = InInput;
	bOpen = false;
	bPendingOpen = false;
	bPendingClose = false;
}

void ConsoleIO::Activate()
{
	GBIND("console_attemptConsoleString", this, &ConsoleIO::AttemptConsoleString);
	GBIND("console_onClose", this, &ConsoleIO::OnClose);
	GBIND("console_onOpen", this, &ConsoleIO::OnOpen);
	//InputP->GetCommand("console")->Call.BindRaw(this, &ConsoleIO::OnCommand);
}


void ConsoleIO::AttemptConsoleString(FString CommandLine)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, CommandLine);
}

void ConsoleIO::OnClose()
{
	bOpen = false;
	bPendingClose = false;
}

void ConsoleIO::OnOpen()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "OnOPEN RECEIVED");
	bOpen = true;
	bPendingOpen = false;
}

void ConsoleIO::OnCommand(StrokeS InStroke)
{
	if (InStroke.KeyDown())
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "COMMAND IN");

		if (bPendingOpen || bPendingClose)
		{
			return;
		}
		else
		{
			if (bOpen)
			{
				bPendingClose = true;
				GSEND0("console_close");
			}
			else
			{
				bPendingOpen = true;
				GSEND0("console_open");
			}
		}
	}
}