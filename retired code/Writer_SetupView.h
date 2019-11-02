//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ui_View.h"
#include "Writer_SetupView.generated.h"

class UCanvasPanel;

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EUi_Writer_SetupViewAtlasEntryBoolType : uint8
{
	Master		UMETA(DisplayName = "Master"),
	Support		UMETA(DisplayName = "Support"),
};

UCLASS(Blueprintable)
class OUNIVERSE_API UWriter_SetupView : public UUi_View
{

	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CreateWriterVSetup"))
	static UWriter_SetupView* Create(UUi_Master* InMaster, UCanvasPanel* InPanel);

	void Init(UUi_Master* InMax, UCanvasPanel* InPanel);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSelectionChanged(EUi_Writer_SetupViewAtlasEntryBoolType Type, bool Value);
};