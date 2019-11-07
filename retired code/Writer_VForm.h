//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ui_View.h"
#include "Interface/Array.h"
#include "System/FormWrap.h"

#include "Writer_VForm.generated.h"

class UWriter_Master;
class UWriter_VFormEntry;
class UCanvasPanel;
class UScrollBox;

UCLASS(Blueprintable)
class OUNIVERSE_API UWriter_VForm : public UUi_View
{

	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CreateWriterFormView"))
	static UWriter_VForm* Create(UUi_Alpha* InMax, UCanvasPanel* InPanel);

	void Init(UUi_Alpha* InMaster, UCanvasPanel* InPanel);

	UWriter_Master* CastedMaster_;

	UFUNCTION(BlueprintCallable)
	void Need(UScrollBox* InFormScroll, UCanvasPanel* InFormPin);

	UScrollBox* FormScroll_;
	
	UCanvasPanel* FormPin_;

	UFUNCTION(BlueprintCallable)
	void Query(FString InQueryText);

	ArrayC<FormWrapS> FormRefs_;

	UPROPERTY()
	TArray<UWriter_VFormEntry*> Entries_;
};