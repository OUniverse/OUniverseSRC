// Copyright 2015-2019. All Rights Reserved.

#include "System/ViewportUE.h"
//#include "System/DebugMinimal.h"


// WARNING INIT is already registered with Viewport so use a different name


void UViewportUE::LostFocus(FViewport * InViewport)
{
	Super::LostFocus(InViewport);
	//DEBUGPRINT(FColor::Turquoise, "Game Lost Focus...");
}

void UViewportUE::ReceivedFocus(FViewport * InViewport)
{
	Super::ReceivedFocus(InViewport);
	//DEBUGPRINT(FColor::Turquoise, "Game Gained Focus...");
}