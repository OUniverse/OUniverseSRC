//Copyright 2015-2019, All Rights Reserved.

/**
IO (InterfaceObject)
Menu where the player selects and manages their UserID.
 */

#pragma once

#include "CoreMinimal.h"
#include "Ui/Io.h"
#include "I_User.generated.h"

UENUM()
enum class EI_UserMode : uint8
{
	Select						UMETA(DisplayName = "User Select"),
	Create						UMETA(DisplayName = "User Edit"),
	Edit						UMETA(DisplayName = "User Create"),
	Intro						UMETA(DisplayName = "User Intro"),
};


UCLASS()
class OUNIVERSE_API UI_User : public UIo
{
	GENERATED_BODY()

public:
	
	UI_User();
	bool bOpen;

	void King();
	void SetMode(EI_UserMode NewMode);
	void OnUserSelected();

	void Activate() override;
};