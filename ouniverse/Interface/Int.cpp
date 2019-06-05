//Copyright 2015-2019, All Rights Reserved.

#include "Interface/Int.h"
#include  <limits>

bool Int::Is32U(int N)
{
	if (N > USHRT_MAX || N <= -1)
	{
		return false;
	}

	return true;

} 

int Int::MaxU8() { return 255; }
int Int::MaxU16() { return 65535; }
int Int::MaxU32(){	return 4294967295; }
uint64_t Int::MaxU64() { return 18446744073709551615; }

int Int::Max8() { return 127; }
int Int::Max16() { return 32767; }
int Int::Max32() { return 2147483647; }
long long Int::Max64() { return 9223372036854775807; }



UInt8::UInt8()
{
	I = 0;
}


UInt8::UInt8(int InInt)
{
	I = InInt;
}


uint8_t& UInt8::Ref()
{
	return I;
}


UInt8::operator bool() const
{
	if (I == 0)
	{
		return false;
	}

	return true;
}




UInt16::UInt16() 
{ 
	I = 0;
}


UInt16::UInt16(int InInt)
{
	I = InInt;
}


uint16_t& UInt16::Ref()
{
	return I;
}


UInt16::operator bool() const
{
	if (I == 0)
	{
		return false;
	}

	return true;
}



UInt32::UInt32()
{
	I = 0;
}


UInt32::UInt32(int InInt)
{
	I = InInt;
}


uint32_t& UInt32::Ref()
{
	return I;
}

UInt32::operator bool() const
{
	if (I == 0)
	{
		return false;
	}

	return true;
}




UInt64::UInt64()
{ 
	I = 0; 
}


UInt64::UInt64(long long InInt)
{
	I = InInt;
}


uint64_t& UInt64::Ref()
{
	return I;
}


bool UInt64::operator>(UInt64 InInt)
{
	return (I > InInt.Ref());
}


bool UInt64::operator>=(UInt64 InInt)
{
	return (I >= InInt.Ref());
}


bool UInt64::operator<(UInt64 InInt)
{
	return (I < InInt.Ref());
}


bool UInt64::operator<=(UInt64 InInt)
{
	return (I <= InInt.Ref());
}


UInt64::operator bool() const
{
	if (I == 0)
	{
		return false;
	}

	return true;
}