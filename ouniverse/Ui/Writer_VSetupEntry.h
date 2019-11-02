//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ubc.h"
#include "Writer_VSetupEntry.generated.h"

class UScrollBox;
class UAtlas;
class UUi_Bool;

UCLASS(Blueprintable)
class OUNIVERSE_API UWriter_VSetupEntry : public UUbc
{

	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CreateWriterVSetupEntry"))
	static UWriter_VSetupEntry* Create(UWorld* InScope,UWriter_VSetup* InView, UAtlas* InAtlas, UScrollBox* InBox);

	void Init(UWriter_VSetup* InView, UAtlas* InAtlas, UScrollBox* InBox);

	UPROPERTY()
	UAtlas* Atlas_;

	UFUNCTION(BlueprintPure)
	UAtlas* Atlas();

	UPROPERTY()
	UWriter_VSetup* RView_;

	UFUNCTION(BlueprintPure)
	UWriter_VSetup* RView();

	UFUNCTION(BlueprintImplementableEvent)
	void Ready();

	//MUST BE SET IN Ready() EVENT FOR CLASS TO FUNCTION
	UFUNCTION(BlueprintCallable)
	void SetInterface(UUi_Bool* InMaster, UUi_Bool* InSupport);

	UUi_Bool* Master_;
	UUi_Bool* Support_;

};