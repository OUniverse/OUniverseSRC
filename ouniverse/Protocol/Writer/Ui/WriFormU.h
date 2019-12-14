//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBaseNew.h"
#include "WriFormU.generated.h"

class WriFormP;

class UEditableTextBox;
class UUiScroller;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriForm : public UUiBaseNew
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	void UiConstruct(WriFormP* InPro);

	WriFormP* Pro_;

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* V_Query;

	UPROPERTY(meta = (BindWidget))
	UUiScroller* Scroller;
};