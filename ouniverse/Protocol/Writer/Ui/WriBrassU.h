//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBase.h"
#include "WriBrassU.generated.h"

class WriBrassP;


UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriBrass : public UUiBase
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
};