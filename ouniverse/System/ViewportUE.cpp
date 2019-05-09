// Copyright 2015-2019. All Rights Reserved.

#include "System/ViewportUE.h"
//#include "System/DebugMinimal.h"


// WARNING INIT is already registered with Viewport so use a different name


void UViewportUE::LostFocus(FViewport * Viewport)
{
	Super::LostFocus(Viewport);
	//DEBUGPRINT(FColor::Turquoise, "Game Lost Focus...");
}

void UViewportUE::ReceivedFocus(FViewport * Viewport)
{
	Super::ReceivedFocus(Viewport);
	//DEBUGPRINT(FColor::Turquoise, "Game Gained Focus...");
}