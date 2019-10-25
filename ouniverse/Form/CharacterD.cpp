//Copyright 2015-2019, All Rights Reserved.

#include "Form/CharacterD.h"
#include "Form/CharacterE.h"

UCharacterE* CharacterD::CreateEx()
{
	return UCharacterE::Create(this);
}

CharacterD::CharacterD()
{

}