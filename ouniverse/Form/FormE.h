//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "UObject/NoExportTypes.h"
#include "FormE.generated.h"

class FormD;

UCLASS()
class OUNIVERSE_API UFormE : public UObject
{
	GENERATED_BODY()

public:

	static UFormE* Create(FormD* InDat);
	void Init(FormD* InDat);
	
	FormD* Dat_;
};