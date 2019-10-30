//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Form/FormA.h"

#include "WorldA.generated.h"

class WorldF;

UCLASS(Blueprintable)
class OUNIVERSE_API UWorldA : public UFormA
{
	GENERATED_BODY()

public:

	UWorldA() {};

	static UWorldA* Create(WorldF* InForm);


};