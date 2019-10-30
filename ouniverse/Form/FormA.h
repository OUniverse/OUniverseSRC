//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "UObject/NoExportTypes.h"
#include "FormA.generated.h"

class FormF;

UCLASS(Blueprintable)
class OUNIVERSE_API UFormA : public UObject
{
	GENERATED_BODY()

public:

	static UFormA* Create(FormF* InForm);
	void InitBase(FormF* InForm);


	FormF* Form();
	FormF* Form_;	
	
	UFUNCTION(BlueprintPure, Category = "Form")
	FString GetFormID();

	UFUNCTION(BlueprintPure, Category = "Form")
	int GetFormUID();

};