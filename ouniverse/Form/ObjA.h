//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Form/FormA.h"
#include "ObjA.generated.h"

class AActor;

UCLASS(Blueprintable)
class OUNIVERSE_API UObjA : public UFormA
{
	GENERATED_BODY()

public:

	UObjA();
	static UObjA* Create(DataD* InForm);

	UFUNCTION()
	virtual AActor* Spawn();
};