//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBase.h"
#include "WriFooterU.generated.h"

class WriFooterP;


UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriFooter : public UUiBase
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;


	UPROPERTY(meta = (BindWidget))
	UWriBrass* vBrass;

};