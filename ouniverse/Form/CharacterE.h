//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Form/ObjectE.h"
#include "CharacterE.generated.h"

class CharacterF;
class ACharacter3D;

UCLASS(Blueprintable)
class OUNIVERSE_API UCharacterE : public UObjectE
{
	GENERATED_BODY()

public:

	static UCharacterE* Create(CharacterF* InForm);

	void Init(CharacterF* InForm);

	virtual AActor* Spawn() override;

	void Test();

	UFUNCTION()
	ACharacter3D* Character3D();
	UPROPERTY()
	ACharacter3D* Character3D_;

	CharacterF* Form();
	CharacterF* Form_;
	
//Unique
public:

	void Possess();
};