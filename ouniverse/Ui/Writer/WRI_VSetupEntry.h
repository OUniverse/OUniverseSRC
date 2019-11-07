//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ubc.h"
#include "WRI_VSetupEntry.generated.h"

class AtlasC;

class UWRI_VSetup;
class UUi_Bool;
class UTexture2D;
class UImage;
class UTextBlock;
class UUi_Bool;
class UUi_Catch;

UCLASS(Blueprintable)
class OUNIVERSE_API UWRI_VSetupEntry : public UUbc
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	static UWRI_VSetupEntry* Create(UWorld* InScope, UWRI_VSetup* InView, AtlasC* InAtlas);

	void Init(UWRI_VSetup* InView, AtlasC* InAtlas);

	UPROPERTY(meta = (BindWidget))
	UImage* V_Image;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* V_Text;
	UPROPERTY(meta = (BindWidget))
	UUi_Catch* V_Catch;
	UPROPERTY(meta = (BindWidget))
	UUi_Bool* V_BoolMaster;
	UPROPERTY(meta = (BindWidget))
	UUi_Bool* V_BoolSupport;
	
	AtlasC* Atlas_;

	UFUNCTION(BlueprintPure)
	FText GetAtlasID();

	UFUNCTION(BlueprintPure)
	UTexture2D* GetAtlasIcon();

	UWRI_VSetup* View_;

	UFUNCTION(BlueprintCallable)
	void BoolChanged(EWRI_VSetupEntryBoolType Type);

};