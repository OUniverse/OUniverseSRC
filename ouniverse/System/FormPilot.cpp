//Copyright 2015-2019, All Rights Reserved.


#include "System/FormPilot.h"
#include "Form/FormF.h"




FormPilotS::FormPilotS()
{

}
FormPilotS::FormPilotS(U32 InUID, StringC InID, int InType)
{
	UID_ = InUID;
	ID_ = InID;
	Type_ = InType;
}

U32 FormPilotS::UID()
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