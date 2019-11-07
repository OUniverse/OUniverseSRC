//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Components/EditableTextBox.h"
#include "Ui_EditableTextBox.generated.h"


class UUbc;

UCLASS(Blueprintable)
class OUNIVERSE_API UUi_EditableTextBox : public UEditableTextBox
{

	GENERATED_BODY()

public:

	void SetRelay(UUbc* InRelay);

	UUbc* Relay();

	UUbc* Relay_;

	virtual void HandleOnTextChanged(const FText& Text) override {};
	virtual void HandleOnTextCommitted(const FText& Text, ETextCommit::Type CommitMethod) override {};
};