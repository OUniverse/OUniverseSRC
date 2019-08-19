//Copyright 2015-2019, All Rights Reserved.


#include "System/FormPilot.h"
#include "Form/FormF.h"




FormPilotS::FormPilotS()
{

}
FormPilotS::FormPilotS(FormF* InForm)
{

}

U64 FormPilotS::UID()
{
	return UID_;
}

StringC FormPilotS::ID()
{
	return ID_;
}

int FormPilotS::Type()
{
	return Type_;
}