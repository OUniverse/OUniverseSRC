//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBaseNew.h"
#include "WriAtlasU.generated.h"

class UEditableTextBox;
class WriAtlasP;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriAtlas : public UUiBaseNew
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	void UiConstruct(WriAtlasP* InPro);

	WriAtlasP* Pro_;

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* V_ID;

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* V_Author;


};