//Copyright 2015-2019, All Rights Reserved.

#include "Form/FormF.h"
#include "Interface/Json.h"

#include "Min/DebugM.h"


const char* FormF::K_UID		= "@";
const char* FormF::K_NAME		= "n";


FormF::FormF(JsonS& InJ)
{
	J = InJ;
	UID_ = J.UInt32(FormF::K_UID);
}

FormF* FormF::Create(JsonS& InJ)
{ 
	return new FormF(InJ); 
}

void FormF::Marshal() {}	

U32 FormF::UID()
{
	return UID_;
}