//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/Ui_Interactive.h"
#include "Interface/String.h"
#include "Ui_TextAreaEdit.generated.h"


class UMultiLineEditableText;


UCLASS(Abstract,Blueprintable)
class OUNIVERSE_API UUi_TextAreaEdit : public UUi_Interactive
{

	GENERATED_BODY()

public:


	UFUNCTION(BlueprintCallable)
	void Required(UMultiLineEditableText* TextBox);
	
	UMultiLineEditableText* Text_;

	void SetText(StringC InText);

	StringC GetText();

	void KeyboardFocus();
};