//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBase.h"
#include "WriFormEditU.generated.h"

class WriFormEditP;

class UWriButton;
class UMultiLineEditableTextBox;
class UTextBlock;

class FormDataC;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriFormEdit : public UUiBase
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	void UiConstruct(WriFormEditP* InPro);

	WriFormEditP* Pro_;

	UPROPERTY(meta = (BindWidget))
	UWriButton* vDataMode;

	UPROPERTY(meta = (BindWidget))
	UWriButton* vOutputMode;

	UPROPERTY(meta = (BindWidget))
	UWriButton* vSave;

	UPROPERTY(meta = (BindWidget))
	UWriButton* vVerify;

	UPROPERTY(meta = (BindWidget))
	UMultiLineEditableTextBox* vOutput;

	UPROPERTY(meta = (BindWidget))
	UMultiLineEditableTextBox* vData;

	void OpenForm(FormDataC* InFormData);

	static enum REG {
		RDataMode,
		ROutputMode,
		RSave,
		RVerify,
	};
};