//Copyright 2015-2019, All Rights Reserved.

/**
IO (InterfaceObject)
Handles the console.
 */

#pragma once

#include "CoreMinimal.h"
#include "Ui/Io.h"

class InputManager;

struct FStroke;

class OUNIVERSE_API ConsoleIO : public Io
{
	friend UiManager;

private:

	ConsoleIO(UCohtmlHUD* InUi, InputManager* InInputP);

	bool bOpen;

	bool bPendingOpen;

	bool bPendingClose;

	InputManager* InputP;

	void Activate() override;

	void AttemptConsoleString(FString CommandLine);
	
	void OnOpen();
	
	void OnClose();

	void OnCommand(FStroke Stroke);

};