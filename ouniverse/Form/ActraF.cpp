//Copyright 2015-2019, All Rights Reserved.

#include "Form/ActraF.h"
#include "Interface/Json.h"

ActraF::ActraF(JsonS& InJ) : FormF(J)
{

}

ActraF* ActraF::Create(JsonS& InJ)
{ 
	return new ActraF(InJ);
}


void ActraF::Marshal()
{
	FormF::Marshal();
}