//Copyright 2015-2019, All Rights Reserved.

#include "System/AudioGroup.h"

AudioGroup::AudioGroup()
{
	VolumeMultiplier = 1.0f;
	bMute = false;
	bParent = false;
	Parent = (AudioGroup*)nullptr;
}

void AudioGroup::SetParent(AudioGroup* InParent)
{
	bParent = true;
	Parent = InParent;
}
bool AudioGroup::IsMuted()
{
	if (bParent)
	{
		return Parent->IsMuted();
	}
	return bMute;
}

float AudioGroup::GetVolumeMultiplier()
{
	if(bParent)
	{
		return VolumeMultiplier * Parent->GetVolumeMultiplier();
	}
	return VolumeMultiplier;
}