//Copyright 2015-2019, All Rights Reserved.

#include "Interface/Int.h"
#include  <limits>

#include <sstream>
#include <ostream>

/**
const int Int::MaxU8 = 255;
const int Int::MaxU16 = 65535;
const int Int::MaxU32 = 4294967295;
const uint64_t Int::MaxU64 = 18446744073709551615;

const int Int::MaxS8 = 127;
const int Int::MaxS16 = 32767;
const int Int::MaxS32 = 2147483647;
const long long Int::MaxS64 = 9223372036854775807;
*/


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

U8::operator int() const
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

bool U8::operator<(const U8& l) const
{
	return I < l.I;
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


U16::operator int() const
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

bool U16::operator<(const U16& l) const
{
	return I < l.I;
}





U32::U32()
{
	I = 0;
}


U32::U32(int InInt)
{
	I = InInt;
}

std::string U32::ToStd()
{
	std::ostringstream oss;
	oss << I;
	return oss.str();
}

uint32_t& U32::Ref()
{
	return I;
}

U32::operator int() const
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

bool U32::operator<(const U32& l) const
{
	return I < l.I;
}

bool U32::operator==(U32 In)
{
	if (I == In.I)
	{
		return true;
	}
	return false;
}


bool U32::operator!=(U32 In)
{
	if (I == In.I)
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

U64::U64(const char* IntAsString)
{
	std::istringstream iss(IntAsString);
	iss >> I;

}

std::string U64::ToStd()
{
	std::ostringstream oss;
	oss << I;
	return oss.str();
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

bool U64::operator<(const U64& l) const
{
	return I < l.I;
}