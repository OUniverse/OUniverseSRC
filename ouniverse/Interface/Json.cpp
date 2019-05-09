//Copyright 2015-2019, All Rights Reserved.

#include "Interface/Json.h"


JsonS::JsonS(const char* JSerialized)
{
	J.Parse(JSerialized);
}

int JsonS::operator%(const char* Query)
{
	return J[Query].GetInt();
}

int JsonS::Int(const char* Query)
{
	return J[Query].GetInt();
}

FString JsonS::String(const char* Query)
{
	return J[Query].GetString();
}

FString JsonS::operator&(const char* Query)
{
	return J[Query].GetString();
}
