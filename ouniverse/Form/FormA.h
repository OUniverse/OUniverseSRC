//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "UObject/NoExportTypes.h"
#include "FormA.generated.h"

class DataD;

UCLASS(Blueprintable)
class OUNIVERSE_API UFormA : public UObject
{
	GENERATED_BODY()

public:

	static UFormA* Create(DataD* InForm);
	void InitBase(DataD* InForm);


	DataD* Form();
	DataD* Form_;	
	
	UFUNCTION(BlueprintPure, Category = "Form")
	FString GetFormID();

	UFUNCTION(BlueprintPure, Category = "Form")
	int GetFormUID();

};