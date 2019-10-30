//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Form/FormA.h"

#include "RegionA.generated.h"

class RegionF;

UCLASS(Blueprintable)
class OUNIVERSE_API URegionA : public UFormA
{
	GENERATED_BODY()

public:

	URegionA() {};

	static URegionA* Create(RegionF* InForm);


};