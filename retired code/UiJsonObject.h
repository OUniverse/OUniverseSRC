//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Json/UiJsonType.h"
#include "UiJsonObject.generated.h"

class UVerticalBox;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UUiJsonObject : public UUiJsonType
{

	GENERATED_BODY()

public:

	UPROPERTY(meta = (BindWidget))
	UVerticalBox* vBox;

};