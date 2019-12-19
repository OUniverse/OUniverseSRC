//Copyright 2015-2019, All Rights Reserved.

#include "System/Class.h"
#include "Form/CharacterA.h"
#include "Form/Character3D.h"



namespace Class
{
	bool Setup_ = false;
	TSubclassOf<UCharacterA> F_CharacterA;
	TSubclassOf<ACharacter3D> F_Character3D;
}


void ClassC::Setup()
{
	Class::Setup_ = true;
	Class::F_CharacterA = TSoftClassPtr<UCharacterA>(FSoftClassPath("/Game/class/form/ChracterA.ChracterA_C")).LoadSynchronous();
	Class::F_Character3D = TSoftClassPtr<ACharacter3D>(FSoftClassPath("/Game/class/form/Character3D.Character3D_C")).LoadSynchronous();
}

bool ClassC::IsSetup()
{
	return Class::Setup_;
}

TSubclassOf<UCharacterA> ClassC::F_CharacterA()					{ return Class::F_CharacterA; }
TSubclassOf<ACharacter3D> ClassC::F_Character3D()				{ return Class::F_Character3D; }