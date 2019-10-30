//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Form/FormA.h"

#include "AreaA.generated.h"

class AreaF;

UCLASS(Blueprintable)
class OUNIVERSE_API UAreaA : public UFormA
{
	GENERATED_BODY()

public:

	UAreaA() {};

	static UAreaA* Create(AreaF* InForm);


};