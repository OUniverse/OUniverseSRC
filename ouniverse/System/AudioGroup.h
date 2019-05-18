//Copyright 2015-2019, All Rights Reserved.

/**

## AudioGroups

AudioGroups are nesting volume control containers Example: Voice/UI/Music/Ambience.
* These are intended to be adjustable by the user from ingame menus during gameplay.

**Creator:** AudioManager
**Holder:** AudioManager

*/

#pragma once

#include "CoreMinimal.h"

class OUNIVERSE_API AudioGroup
{

public:

	AudioGroup();

	FString ID;
	float VolumeMultiplier;
	bool bMute;	
	bool bParent;

	void SetParent(AudioGroup* InParent);
	bool IsMuted();
	float GetVolumeMultiplier();

private:

	AudioGroup* Parent;

};
