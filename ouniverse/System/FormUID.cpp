//Copyright 2015-2019, All Rights Reserved.

#include "System/FormUID.h"

int FormUID::Max = 4294967295;

FormUID::FormUID()
{
	UID_ = 0;
}

FormUID::FormUID(int InInt)
{
	UID_ = InInt;
}

FormUID::FormUID(StringC InS)
{
	UID_ = 0;
	InS.BeInt(UID_);
}

int FormUID::UID() const
{
	return UID_;
}


int FormUID::UID()
{
	return UID_;
}

bool FormUID::operator<(const FormUID& l) const
{
	return UID() < l.UID();
}


bool FormUID::operator==(FormUID In)
{
	if (UID() == In.UID())
	{
		return true;
	}
	return false;
}


bool FormUID::operator!=(FormUID In)
{
	if (UID() == In.UID())
	{
		return false;
	}
	return true;
}

int FormUID::ToInt()
{
	return UID_;
}

int FormUID::ForJson()
{
	return UID_;
}

int FormUID::ForUI()
{
	return UID_;
}

int FormUID::ForLog()
{
	return UID_;
}

int& FormUID::Ref()
{
	return UID_;
}