//Copyright 2015-2019, All Rights Reserved.

#include "Form/ActraF.h"
#include "System/FormTypes.h"
#include "Interface/Json.h"


int ActraF::Type()
{
	return FormTypesC::Types::Actra;
}

ActraF::ActraF(JsonS& InJ) : FormF(Json_)
{

}

FormF* ActraF::Create(JsonS& InJ)
{ 
	return new ActraF(InJ);
}


void ActraF::Marshal()
{
	FormF::Marshal();
}