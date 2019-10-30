//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Form/FormA.h"

#include "EpochA.generated.h"

class EpochF;

UCLASS(Blueprintable)
class OUNIVERSE_API UEpochA : public UFormA
{
	GENERATED_BODY()

public:

	UEpochA() {};

	static UEpochA* Create(EpochF* InForm);


};