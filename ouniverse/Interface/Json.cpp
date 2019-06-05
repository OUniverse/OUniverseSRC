//Copyright 2015-2019, All Rights Reserved.

#include "Interface/Json.h"


JsonS::JsonS(json InJ)
{
	J = InJ;
}

JsonS::JsonS(const char* JSerialized)
{
	J = json::parse(JSerialized);
}

JsonS::JsonS(StringC JSerialized)
{
	J = json::parse(JSerialized.ToChar());
}

JsonS JsonS::operator[](const char* Query)
{
	return JsonS(J[Query]);
}

JsonS JsonS::operator[](int Query)
{
	return JsonS(J[Query]);
}

int JsonS::Size()
{
	return J.size();
}
StringC JsonS::String(const char* Query)
{
	return J[Query].get<std::string>();
}

int JsonS::Int(const char* Query)
{
	return J[Query].get<int>();
}



UInt8 JsonS::ToUInt8()
{
	return UInt8(J.get<int>());
}

UInt16 JsonS::ToUInt16()
{
	return UInt16(J.get<int>());
}

UInt32 JsonS::ToUInt32()
{
	return UInt32(J.get<int>());
}

UInt64 JsonS::ToUInt64()
{
	return UInt64(J.get<int>());
}


UInt8 JsonS::ToUInt8(const char* Query)
{
	return UInt8(J[Query].get<int>());
}

UInt16 JsonS::ToUInt16(const char* Query)
{
	return UInt16(J[Query].get<int>());
}

UInt32 JsonS::ToUInt32(const char* Query)
{
	return UInt32(J[Query].get<int>());
}

UInt64 JsonS::ToUInt64(const char* Query)
{
	return UInt64(J[Query].get<int>());
}