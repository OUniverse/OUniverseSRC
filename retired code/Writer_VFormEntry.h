//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ubc.h"
#include "System/FormWrap.h"

#include "Writer_VFormEntry.generated.h"



class UScrollBox;
class UForm;

UCLASS(Blueprintable)
class OUNIVERSE_API UWriter_VFormEntry : public UUbc
{

	GENERATED_BODY()

public:


	static UWriter_VFormEntry* Create(UWorld* InScope, UWriter_VForm* InView, FormWrapS InFormW, UScrollBox* InBox);

	void Init(UWriter_VForm* InView, FormWrapS InFormW, UScrollBox* InBox);

	FormWrapS FormW_;

	UPROPERTY()
	UWriter_VForm* RView_;

	UFUNCTION(BlueprintPure)
	UWriter_VForm* RView();

	UFUNCTION(BlueprintImplementableEvent)
	void Ready();

	UFUNCTION(BlueprintPure)
	FString GetFormID();

	UFUNCTION(BlueprintPure)
	int GetFormUID();

};