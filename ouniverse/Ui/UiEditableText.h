//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiFocus.h"
#include "UiEditableText.generated.h"

class UEditableText;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UUiEditableText : public UUiFocus
{

	GENERATED_BODY()


public:
	virtual void NativeConstruct() override;


	UEditableText* vText;

	UFUNCTION(BlueprintCallable)
	void Require(UEditableText* InText);

	void SetText(FText InText);

};