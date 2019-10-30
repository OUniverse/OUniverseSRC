//Copyright 2015-2019, All Rights Reserved.

#include "Form/CharacterF.h"
#include "Form/CharacterA.h"

#include "System/FormTypes.h"
#include "Interface/Json.h"


int CharacterF::Type()
{
	return FormTypesC::Types::Character;
}

UCharacterA* CharacterF::CreateEx()
{
	return UCharacterA::Create(this);
}

CharacterF::CharacterF()
{

}

FormF* CharacterF::Create(JsonS& InJ)
{ 
	FormF* Obj = new CharacterF();
	Obj->Setup(InJ);
	return Obj;
}

void CharacterF::Demarshal()
{
	Name_ = "THIS IS A TEST";
	FormF::Demarshal();
}
