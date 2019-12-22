//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Json/UiJsonType.h"
#include "UiJsonArray.generated.h"

class UVerticalBox;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UUiJsonArray : public UUiJsonType
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

};