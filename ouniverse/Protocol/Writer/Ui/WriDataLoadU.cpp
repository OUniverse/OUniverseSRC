//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/Ui/WriDataLoadU.h"
#include "Protocol/Writer/WriDataLoadP.h"

#include "Ui/UiButton.h"
#include "Ui/UiEventCodes.h"

void UWriDataLoad::NativeConstruct()
{
	Super::NativeConstruct();
}

void UWriDataLoad::UiConstruct(WriDataLoadP* InPro)
{
	Pro_ = InPro;
}

void UWriDataLoad::AnimationComplete()
{
	Pro_->LoadingAnimationComplete();
}