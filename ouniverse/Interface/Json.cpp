//Copyright 2015-2019, All Rights Reserved.

#include "Interface/Json.h"


JsonS::JsonS(const char* JSerialized)
{
	J.Parse(JSerialized);
}

int JsonS::Int(const char* Query)
{
	return J[Query].GetInt();
}

StringC JsonS::String(const char* Query)
{
	return std::string(J[Query].GetString());
}