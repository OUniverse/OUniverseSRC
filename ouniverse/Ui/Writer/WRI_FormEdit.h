//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ui_View.h"
#include "Interface/Array.h"
#include "System/FormWrap.h"

#include "WRI_FormEdit.generated.h"

class AtlasLibC;

class UWRI_FormEdit_Le;
class UCanvasPanel;
class UUi_ScrollBox;
class UUi_TextEdit;

UCLASS(Blueprintable)
class OUNIVERSE_API UWRI_FormEdit : public UUi_View
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	static UWRI_FormEdit* Create(UUi_View* InOwningView, AtlasLibC* InAtlasLib);

	void Init(UUi_View* InOwningView, AtlasLibC* InAtlasLib);


	void FormSelected(FormWrapS InFormWrap);

	UPROPERTY(meta = (BindWidget))
	UUi_ScrollBox* V_Scroll;

	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* V_Form;

	UPROPERTY(meta = (BindWidget))
	UUi_TextEdit* V_Query;

	UFUNCTION(BlueprintCallable)
	void Query();

	AtlasLibC* AtlasLib_;

	ArrayC<FormWrapS> FormRefs_;

	TArray<UWRI_FormEdit_Le*> Entries_;

	static enum Interactives {
		IQuery,
	};

	void TextCommit(UUi_Interactive* Interactive, int CommitMethod) override;

};