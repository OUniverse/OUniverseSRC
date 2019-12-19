//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/FieldWriter/UiFieldWriter.h"
#include "UiFieldWriterString.generated.h"

class UEditableText;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UUiFieldWriterString : public UUiFieldWriter
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	UPROPERTY(meta = (BindWidget))
	UEditableText* V_Text;

	UFUNCTION()
	void OnTextChanged(const FText& Text);
	UFUNCTION()
	void OnTextCommitted(const FText& Text, ETextCommit::Type CommitMethod);

	void SetText(FText InText);
};