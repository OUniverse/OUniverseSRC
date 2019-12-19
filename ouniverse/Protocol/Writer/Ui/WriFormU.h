//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBase.h"
#include "Interface/Array.h"
#include "WriFormU.generated.h"

class WriFormP;

class UWriButton;
class UEditableText;
class UUiScroll;

class UWriFormEdit;

class AtlasLibC;
class FormDataC;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriForm : public UUiBase
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	void UiConstruct(WriFormP* InPro, AtlasLibC* InAtlasLib);

	WriFormP* Pro_;

	AtlasLibC* AtlasLib_;

	ArrayC<FormDataC*> FormRefs_;

	UPROPERTY(meta = (BindWidget))
	UEditableText* vQuery;

	UPROPERTY(meta = (BindWidget))
	UUiScroll* vScroll;

	UPROPERTY(meta = (BindWidget))
	UWriButton* vSearch;

	UPROPERTY(meta = (BindWidget))
	UWriButton* vNewForm;
	
	UPROPERTY(meta = (BindWidget))
	UWriButton* vDeleteForm;


	UPROPERTY(meta = (BindWidget))
	UWriFormEdit* vFormEdit;

	UFUNCTION()
	void OnTextCommitted(const FText& Text, ETextCommit::Type CommitMethod);

	void Query();

	void OpenForm(FormDataC* InFormData);

	static enum REG {
		RSearch,
		RNewForm,
		RDeleteForm,
	};
};