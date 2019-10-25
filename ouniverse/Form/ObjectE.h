//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Form/FormE.h"
#include "ObjectE.generated.h"

class AActor;

UCLASS(Blueprintable)
class OUNIVERSE_API UObjectE : public UFormE
{
	GENERATED_BODY()

public:

	UObjectE();
	static UObjectE* Create();
	void Init();

	UFUNCTION()
	virtual AActor* Spawn();

	UFUNCTION()
	UObjectE* Type3D();

	UPROPERTY()
	UObjectE* Type3D_;
};