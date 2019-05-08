// Copyright 2015-2019. All Rights Reserved.

#include "System/ViewportClient.h"
//#include "System/DebugMinimal.h"


// WARNING INIT is already registered with Viewport so use a different name


void UViewportClient::LostFocus(FViewport * Viewport)
{
	Super::LostFocus(Viewport);
	//DEBUGPRINT(FColor::Turquoise, "Game Lost Focus...");
}

void UViewportClient::ReceivedFocus(FViewport * Viewport)
{
	Super::ReceivedFocus(Viewport);
	//DEBUGPRINT(FColor::Turquoise, "Game Gained Focus...");
}