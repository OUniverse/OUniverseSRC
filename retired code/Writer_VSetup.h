//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ui_View.h"
#include "Writer_VSetup.generated.h"

class UWriter_Master;
class UWriter_VSetupEntry;

class UCanvasPanel;
class UScrollBox;

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EWriter_VSetupEntryBoolType : uint8
{
	Master		UMETA(DisplayName = "Master"),
	Support		UMETA(DisplayName = "Support"),
};

UCLASS(Blueprintable)
class OUNIVERSE_API UWriter_VSetup : public UUi_View
{

	GENERATED_BODY()

public:

	UWriter_VSetupEntry* ActiveEntry_;

	UWriter_Master* CastedMaster_;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CreateWriterSetupView"))
	static UWriter_VSetup* Create(UUi_Alpha* InMax, UCanvasPanel* InPanel);

	void Init(UUi_Alpha* InMaster, UCanvasPanel* InPanel);

	UFUNCTION(BlueprintCallable)
	void BuildEntryList(UScrollBox* InBox);

	UFUNCTION(BlueprintCallable)
	void OnEntryChanged(EWriter_VSetupEntryBoolType Type, UWriter_VSetupEntry* InEntry);

	UPROPERTY()
	TArray<UWriter_VSetupEntry*> Entries_;

};