//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ubc.h"
#include "System/FormWrap.h"

#include "WRI_VFormEntry.generated.h"



class UScrollBox;
class UForm;
class UWRI_VForm;

UCLASS(Blueprintable)
class OUNIVERSE_API UWRI_VFormEntry : public UUbc
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	static UWRI_VFormEntry* Create(UWorld* InScope, UWRI_VForm* InView, FormWrapS InFormW);

	void Init(UWRI_VForm* InView, FormWrapS InFormW);

	FormWrapS FormW_;

	UPROPERTY()
	UWRI_VForm* View_;

	UFUNCTION(BlueprintPure)
	UWRI_VForm* View();

	UFUNCTION(BlueprintPure)
	FString GetFormID();

	UFUNCTION(BlueprintPure)
	int GetFormUID();

};