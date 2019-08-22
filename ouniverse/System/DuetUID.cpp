//Copyright 2015-2019, All Rights Reserved.

#include "System/DuetUID.h"


DuetUID::DuetUID()
{

}

DuetUID::DuetUID(AtlasUID InAtlasUID, FormUID InFormUID)
{
	AtlasUID_ = InAtlasUID;
	FormUID_ = InFormUID;
}

DuetUID::DuetUID(StringC InS)
{

}

AtlasUID DuetUID::Atlas()
{
	return AtlasUID_;
}

AtlasUID DuetUID::Atlas() const
{
	return AtlasUID_;
}

FormUID DuetUID::Form()
{
	return FormUID_;
}

FormUID DuetUID::Form() const
{
	return FormUID_;
}

bool DuetUID::operator<(const DuetUID& l) const
{
	return (Atlas().UID() < l.Atlas().UID() && Form().UID() < l.Form().UID());
}

bool DuetUID::operator==(DuetUID In)
{
	if (Atlas().UID() == In.Atlas().UID() && Form().UID() == In.Form().UID())
	{
		return true;
	}
	return false;
}

bool DuetUID::operator!=(DuetUID In)
{
	if (Atlas().UID() == In.Atlas().UID() && Form().UID() == In.Form().UID())
	{
		return false;
	}
	return true;
}

StringC DuetUID::String()
{
	return StringC(AtlasUID_.UID()) + "." + StringC(FormUID_.UID());
}