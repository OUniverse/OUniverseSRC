//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "UObject/SoftObjectPtr.h"

class ACharacter3D;
class UCharacterA;

class UUi;

class OUNIVERSE_API ClassC
{


public:

	static void Setup();

	static bool IsSetup();
	static TSubclassOf<UCharacterA> F_CharacterA();
	static TSubclassOf<ACharacter3D> F_Character3D();
};