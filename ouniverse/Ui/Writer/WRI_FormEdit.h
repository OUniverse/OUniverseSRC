//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/UiView.h"
#include "Interface/Array.h"
#include "System/FormWrap.h"

#include "WRI_FormEdit.generated.h"

class AtlasLibC;

class UWRI_FormEdit_Le;
class UCanvasPanel;
class UUi_ScrollBox;

UCLASS(Blueprintable)
class OUNIVERSE_API UWRI_FormEdit : public UUiView
{

	GENERATED_BODY()

public:


	void Init(UUiView* InOwningView, AtlasLibC* InAtlasLib);


	void FormSelected(FormWrapS InFormWrap);

	UPROPERTY(meta = (BindWidget))
	UUi_ScrollBox* V_Scroll;

	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* V_Form;

	UFUNCTION(BlueprintCallable)
	void Query();

	AtlasLibC* AtlasLib_;

	ArrayC<FormWrapS> FormRefs_;

	TArray<UWRI_FormEdit_Le*> Entries_;

	static enum Interactives {
		IQuery,
	};

};