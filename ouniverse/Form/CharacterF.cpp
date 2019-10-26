//Copyright 2015-2019, All Rights Reserved.

#include "Form/CharacterF.h"
#include "Form/CharacterE.h"

#include "System/FormTypes.h"
#include "Interface/Json.h"


int CharacterF::Type()
{
	return FormTypesC::Types::Character;
}

UCharacterE* CharacterF::CreateEx()
{
	return UCharacterE::Create(this);
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
	FormF::Demarshal();
}
