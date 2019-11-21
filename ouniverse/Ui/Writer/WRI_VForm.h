//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ui_View.h"
#include "Interface/Array.h"
#include "System/FormWrap.h"

#include "WRI_VForm.generated.h"

class AtlasLibC;

class UWRI_Alpha;
class UWRI_VFormEntry;
class UCanvasPanel;
class UUi_ScrollBox;

UCLASS(Blueprintable)
class OUNIVERSE_API UWRI_VForm : public UUi_View
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	void FormSelected(FormWrapS InFormWrap);

	UWRI_Alpha* CastedMaster_;

	UPROPERTY(meta = (BindWidget))
	UUi_ScrollBox* V_Scroll;

	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* V_Form;

	UWRI_Alpha* CastedView_;

	UCanvasPanel* FormPin_;

	UFUNCTION(BlueprintCallable)
	void Query(FString InQueryText);

	AtlasLibC* AtlasLib_;

	ArrayC<FormWrapS> FormRefs_;

	TArray<UWRI_VFormEntry*> Entries_;
};