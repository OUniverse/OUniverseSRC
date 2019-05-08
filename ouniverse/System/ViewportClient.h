//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameViewportClient.h"
#include "ViewportClient.generated.h"


UCLASS()
class OUNIVERSE_API UViewportClient : public UGameViewportClient
{
	GENERATED_BODY()

public:


	//UE4 already was using UGameViewportClient::Init()

	void LostFocus(FViewport * Viewport) override;
	void ReceivedFocus(FViewport * Viewport) override;
};
