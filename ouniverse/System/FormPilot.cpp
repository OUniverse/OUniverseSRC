//Copyright 2015-2019, All Rights Reserved.


#include "System/FormPilot.h"
#include "Form/FormF.h"




FormPilotS::FormPilotS()
{

}
FormPilotS::FormPilotS(U64 InAtlasUID, U32 InUID, StringC InID, int InType)
{
	AtlasUID_ = InAtlasUID;
	UID_ = InUID;
	ID_ = InID;
	Type_ = InType;
}

U64 FormPilotS::AtlasUID()
{
	return AtlasUID_;
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