//Copyright 2015-2019, All Rights Reserved.

#include "Ui/ConsoleI.h"
#include "CohtmlHUD.h"

#include "System/InputManager.h"
#include "System/Command.h"

#include "cohtml/Binding/Binding.h"
#include "cohtml/Binding/EventHandler.h"
#include "CohtmlFStringBinder.h"


ConsoleIO::ConsoleIO(UCohtmlHUD* InUi, InputManager* InInput) : Io(InUi)
{
	InputP = InInput;
	bOpen = false;
	bPendingOpen = false;
	bPendingClose = false;
}

void ConsoleIO::Activate()
{
	Ui->GetView()->BindCall("console_attemptConsoleString", cohtml::MakeHandler(this, &ConsoleIO::AttemptConsoleString));
	Ui->GetView()->BindCall("console_onClose", cohtml::MakeHandler(this, &ConsoleIO::OnClose));
	Ui->GetView()->BindCall("console_onOpen", cohtml::MakeHandler(this, &ConsoleIO::OnOpen));
	InputP->GetCommand("console")->Call.BindRaw(this, &ConsoleIO::OnCommand);
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

void ConsoleIO::OnCommand(FStroke Stroke)
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