//Copyright 2015-2019, All Rights Reserved.

#include "Ui/I_Console.h"
#include "System/Major.h"
#include "System/InputManager.h"
#include "System/Command.h"

#include "CohtmlHUD.h"
#include "cohtml/Binding/Binding.h"
#include "cohtml/Binding/EventHandler.h"
#include "CohtmlFStringBinder.h"


UI_Console::UI_Console()
{
	bOpen = false;
	bPendingOpen = false;
	bPendingClose = false;
}

void UI_Console::Activate()
{
	Ui->GetView()->BindCall("console_attemptConsoleString", cohtml::MakeHandler(this, &UI_Console::AttemptConsoleString));
	Ui->GetView()->BindCall("console_onClose", cohtml::MakeHandler(this, &UI_Console::OnClose));
	Ui->GetView()->BindCall("console_onOpen", cohtml::MakeHandler(this, &UI_Console::OnOpen));
	Major->InputManager->GetCommand("console")->Call.BindUObject(this, &UI_Console::OnCommand);
}


void UI_Console::AttemptConsoleString(FString CommandLine)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, CommandLine);
}

void UI_Console::OnClose()
{
	bOpen = false;
	bPendingClose = false;
}

void UI_Console::OnOpen()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "OnOPEN RECEIVED");
	bOpen = true;
	bPendingOpen = false;
}

void UI_Console::Test()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "TEST HAPPENING");
	Ui->GetView()->TriggerEvent("ToggleMenu");
}
void UI_Console::OnCommand(FStroke Stroke)
{
	if (Stroke.KeyDown)
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
				Ui->GetView()->TriggerEvent("console_close");
			}
			else
			{
				bPendingOpen = true;
				Ui->GetView()->TriggerEvent("console_open");
			}
		}
	}
}