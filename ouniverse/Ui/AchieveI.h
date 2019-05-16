//Copyright 2015-2019, All Rights Reserved.

/**
IO (InterfaceObject)
Handles the pop up effects when the player unlocks an achievement.
 */

#pragma once

#include "CoreMinimal.h"
#include "Ui/Io.h"
#include <vector>


class AchieveTemp
{

};


class OUNIVERSE_API AchieveIO : public Io
{

	friend UiManager;

private:

	AchieveIO(GlassC* InGlass);

	bool bActive;
	std::vector <AchieveTemp*> AchieveQue;

	void Award(AchieveTemp* NewAward);
	void OnEnd();

	void Activate() override;

};