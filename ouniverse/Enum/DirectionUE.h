//Copyright 2015-2019, All Rights Reserved.

#pragma once
#include "DirectionUE.generated.h"

UENUM(BlueprintType)
enum class EDirection : uint8
{
	None	UMETA(DisplayName = "None"),
	Up 		UMETA(DisplayName = "Up"),
	Down	UMETA(DisplayName = "Down"),
	Left	UMETA(DisplayName = "Left"),
	Right	UMETA(DisplayName = "Right")
};