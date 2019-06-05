//Copyright 2015-2019, All Rights Reserved.

#include "Interface/Json.h"


JsonS::JsonS(const char* JSerialized)
{
	J.Parse(JSerialized);
}

JsonS::JsonS(StringC JSerialized)
{
	J.Parse(JSerialized.ToChar());
}

JsonArrayProxy JsonS::Array(const char* Query)
{
	return J[Query].GetArray();
}

StringC JsonS::String(const char* Query)
{
	return std::string(J[Query].GetString());
}

int JsonS::Int(const char* Query)
{

	return J[Query].GetInt();
}

UInt8 JsonS::ToUInt8(const char* Query)
{
	return UInt8(J[Query].GetInt());
}

UInt16 JsonS::ToUInt16(const char* Query)
{
	return UInt16(J[Query].GetInt());
}

UInt32 JsonS::ToUInt32(const char* Query)
{
	return UInt32(J[Query].GetInt());
}

UInt64 JsonS::ToUInt64(const char* Query)
{
	return UInt64(J[Query].GetInt());
}

