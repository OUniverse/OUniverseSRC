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



U8 JsonS::UInt8()
{
	return U8(J.get<int>());
}

U16 JsonS::UInt16()
{
	return U16(J.get<int>());
}

U32 JsonS::UInt32()
{
	return U32(J.get<int>());
}

U64 JsonS::UInt64()
{
	return U64(J.get<int>());
}


U8 JsonS::UInt8(const char* Query)
{
	return U8(J[Query].get<int>());
}

U16 JsonS::UInt16(const char* Query)
{
	return U16(J[Query].get<int>());
}

U32 JsonS::UInt32(const char* Query)
{
	return U32(J[Query].get<int>());
}

U64 JsonS::UInt64(const char* Query)
{
	return U64(J[Query].get<int>());
}