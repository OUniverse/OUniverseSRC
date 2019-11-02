//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "UObject/NoExportTypes.h"
#include "CoreMinimal.h"
#include "Dialogue.generated.h"


UCLASS(BlueprintType)
class OUNIVERSE_API UDialogue : public UObject
{
	GENERATED_BODY()

public:

	static UDialogue* Create(bool PActors, bool TActors);

	void Init();
};