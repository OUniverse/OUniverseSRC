//Copyright 2015-2019, All Rights Reserved.

/**
AudioGroup holds different volume levels for types of audio, Example: Voice/UI/Music/Ambience.
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
