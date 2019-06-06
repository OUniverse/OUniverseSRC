//Copyright 2015-2019, All Rights Reserved.

#include "Form/EpochF.h"
#include "Interface/Json.h"



EpochF::EpochF(StringC Jser)
{
	JsonS J = JsonS(Jser);
	Marshal(&J);
}

EpochF EpochF::Create(StringC Jser) 
{ 
	return EpochF(Jser); 
}

void EpochF::Marshal(JsonS* J)
{
	Name_ = J->String(FormF::K_NAME);
	FormF::Marshal(J);
}