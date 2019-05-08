//Copyright 2015-2019, All Rights Reserved.

/**
IO (InterfaceObject)
Handles the console.
 */


#pragma once

#include "CoreMinimal.h"
#include "Ui/Io.h"
#include "I_Console.generated.h"

struct FStroke;

UCLASS()
class OUNIVERSE_API UI_Console : public UIo
{
	GENERATED_BODY()

public:
	
	UI_Console();
	bool bOpen;
	bool bPendingOpen;
	bool bPendingClose;

	void Activate() override;
	void AttemptConsoleString(FString CommandLine);
	void OnOpen();
	void OnClose();

	void OnCommand(FStroke Stroke);

	void Test();

};