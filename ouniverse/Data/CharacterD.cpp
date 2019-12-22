//Copyright 2015-2019, All Rights Reserved.

#include "Data/CharacterD.h"
#include "Form/CharacterA.h"

#include "System/FormTypes.h"
#include "Interface/Json.h"


int CharacterD::Type()
{
	return FormTypesC::Types::Character;
}

UCharacterA* CharacterD::CreateEx()
{
	return UCharacterA::Create(this);
}

CharacterD::CharacterD()
{

}

DataD* CharacterD::Create(JsonS& InJ)
{ 
	DataD* Obj = new CharacterD();
	Obj->Setup(InJ);
	return Obj;
}

void CharacterD::Demarshal()
{
	Name_ = "THIS IS A TEST";
	DataD::Demarshal();
}

PolyC* CharacterD::PolyInternal(PolyObjectC* InPoly)
{
	DataD::PolyInternal(InPoly);
	InPoly->AddKey(new PolyStringC("name", 0, "Fioner LongName"));
	InPoly->AddKey(new PolyIntC("age", 0, 24));
	

	return InPoly;
}