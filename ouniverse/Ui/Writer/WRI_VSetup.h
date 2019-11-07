//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ui_View.h"
#include "WRI_VSetup.generated.h"

class UWRI_Alpha;
class UWRI_VSetupEntry;

class AtlasLibC;

class UUi_ScrollBox;

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EWRI_VSetupEntryBoolType : uint8
{
	Master		UMETA(DisplayName = "Master"),
	Support		UMETA(DisplayName = "Support"),
};

UCLASS(Blueprintable)
class OUNIVERSE_API UWRI_VSetup : public UUi_View
{

	GENERATED_BODY()

public:

	void InitFromViewer() override;

	void Imbue(AtlasLibC* InAtlasLib);

	UPROPERTY(meta = (BindWidget))
	UUi_ScrollBox* V_ScrollBox;

	UWRI_VSetupEntry* ActiveEntry_;

	UWRI_Alpha* CastedView_;

	void BoolChanged(EWRI_VSetupEntryBoolType Type, UWRI_VSetupEntry* InEntry);

	UPROPERTY()
	TArray<UWRI_VSetupEntry*> Entries_;

};