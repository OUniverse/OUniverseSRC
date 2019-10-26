//Copyright 2015-2019, All Rights Reserved.

#include "Form/ActraF.h"
#include "System/FormTypes.h"
#include "Interface/Json.h"


int ActraF::Type()
{
	return FormTypesC::Types::Actra;
}

ActraF::ActraF()
{

}

FormF* ActraF::Create(JsonS& InJ)
{ 
	FormF* Obj = new ActraF();
	Obj->Setup(InJ);
	return Obj;
}


void ActraF::Demarshal()
{
	FormF::Demarshal();
}