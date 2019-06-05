//Copyright 2015-2019, All Rights Reserved.

#include "Interface/Int.h"
#include  <limits>


int Int::MaxU8() { return 255; }
int Int::MaxU16() { return 65535; }
int Int::MaxU32(){	return 4294967295; }
uint64_t Int::MaxU64() { return 18446744073709551615; }

int Int::Max8() { return 127; }
int Int::Max16() { return 32767; }
int Int::Max32() { return 2147483647; }
long long Int::Max64() { return 9223372036854775807; }



U8::U8()
{
	I = 0;
}


U8::U8(int InInt)
{
	I = InInt;
}


uint8_t& U8::Ref()
{
	return I;
}


U8::operator bool() const
{
	if (I == 0)
	{
		return false;
	}

	return true;
}




U16::U16() 
{ 
	I = 0;
}


U16::U16(int InInt)
{
	I = InInt;
}


uint16_t& U16::Ref()
{
	return I;
}


U16::operator bool() const
{
	if (I == 0)
	{
		return false;
	}

	return true;
}



U32::U32()
{
	I = 0;
}


U32::U32(int InInt)
{
	I = InInt;
}


uint32_t& U32::Ref()
{
	return I;
}

U32::operator bool() const
{
	if (I == 0)
	{
		return false;
	}

	return true;
}




U64::U64()
{ 
	I = 0; 
}


U64::U64(long long InInt)
{
	I = InInt;
}


uint64_t& U64::Ref()
{
	return I;
}


bool U64::operator>(U64 InInt)
{
	return (I > InInt.Ref());
}


bool U64::operator>=(U64 InInt)
{
	return (I >= InInt.Ref());
}


bool U64::operator<(U64 InInt)
{
	return (I < InInt.Ref());
}


bool U64::operator<=(U64 InInt)
{
	return (I <= InInt.Ref());
}


U64::operator bool() const
{
	if (I == 0)
	{
		return false;
	}

	return true;
}