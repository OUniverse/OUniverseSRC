//Copyright 2015-2019, All Rights Reserved.

#include "Form/DialogueF.h"

#include "System/FormTypes.h"
#include "Interface/Json.h"


int DialogueF::Type()
{
	return FormTypesC::Types::Area;
}


DialogueF::DialogueF()
{

}

DataD* DialogueF::Create(JsonS& InJ)
{
	DataD* Obj = new DialogueF();
	Obj->Setup(InJ);
	return Obj;
}

void DialogueF::Demarshal()
{
	DataD::Demarshal();
}
