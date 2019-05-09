//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameViewportClient.h"
#include "ViewportUE.generated.h"


UCLASS()
class OUNIVERSE_API UViewportUE : public UGameViewportClient
{
	GENERATED_BODY()

public:

	//UE4 already was using UGameViewportClient::Init()

	void LostFocus(FViewport * Viewport) override;
	void ReceivedFocus(FViewport * Viewport) override;
};