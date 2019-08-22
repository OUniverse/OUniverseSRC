//Copyright 2015-2019, All Rights Reserved.


#include "System/FormPilot.h"
#include "Form/FormF.h"




FormPilotS::FormPilotS()
{

}
FormPilotS::FormPilotS(DuetUID InDuet, StringC InID, int InType)
{
	DuetUID_ = InDuet;
	ID_ = InID;
	Type_ = InType;
}

AtlasUID FormPilotS::AtlasUID()
{
	return DuetUID_.Atlas();
}


FormUID FormPilotS::FormUID()
{
	return DuetUID_.Form();
}

StringC FormPilotS::ID()
{
	return ID_;
}

int FormPilotS::Type()
{
	return Type_;
}