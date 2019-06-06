//Copyright 2015-2019, All Rights Reserved.

#include "Form/FormF.h"
#include "Interface/Json.h"

#include "Min/DebugM.h"

const char* FormF::K_UID		= "u";
const char* FormF::K_NAME		= "n";

FormF::FormF() {}

FormF FormF::Create() { return FormF(); }

void FormF::Marshal(JsonS* J)
{

	UID_ = J->UInt32(FormF::K_UID);

}	

U32 FormF::UID()
{
	return UID_;
}