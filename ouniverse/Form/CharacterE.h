//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Form/ObjectE.h"
#include "CharacterE.generated.h"

class CharacterD;
class ACharacter3D;

UCLASS(Blueprintable)
class OUNIVERSE_API UCharacterE : public UObjectE
{
	GENERATED_BODY()

public:

	static UCharacterE* Create(CharacterD* InDat);

	void Init(CharacterD* InDat);

	virtual AActor* Spawn() override;

	UFUNCTION()
	ACharacter3D* Character3D();
	UPROPERTY()
	ACharacter3D* Character3D_;

	CharacterD* Dat();
	CharacterD* Dat_;
	
};