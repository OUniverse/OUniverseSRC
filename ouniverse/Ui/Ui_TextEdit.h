//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/Ui_Interactive.h"
#include "Interface/String.h"
#include "Ui_TextEdit.generated.h"


class UEditableText;


UCLASS(Abstract,Blueprintable)
class OUNIVERSE_API UUi_TextEdit : public UUi_Interactive
{

	GENERATED_BODY()

public:


	UFUNCTION(BlueprintCallable)
	void Required(UEditableText* TextBox);
	
	UEditableText* Text_;

	void SetText(StringC InText);

	StringC GetText();

	void KeyboardFocus();
};