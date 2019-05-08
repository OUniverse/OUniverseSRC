//Copyright 2015-2019, All Rights Reserved.

/**
IO (InterfaceObject)
Handles the pop up effects when the player unlocks an achievement.
 */

#pragma once

#include "CoreMinimal.h"
#include "Ui/Io.h"
#include "I_Achieve.generated.h"


UCLASS()
class UAchieveTemp : public UObject
{
	GENERATED_BODY()
};


UCLASS()
class OUNIVERSE_API UI_Achieve : public UIo
{
	GENERATED_BODY()

public:

	UI_Achieve();

	bool bActive;
	TArray<UAchieveTemp*> AchieveQue;

	void Award(UAchieveTemp* NewAward);
	void OnEnd();

	void Activate() override;
};