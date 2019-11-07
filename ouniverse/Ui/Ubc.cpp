//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ubc.h"
#include "System/Babel.h"

FText UUbc::BabelString(int UID)
{
	return UBabel::Decode(UID);
}