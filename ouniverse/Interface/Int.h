//Copyright 2015-2019, All Rights Reserved.

/**

## String

**Class:** StringC

Generic string implementation.
> Wrapper around a std::string with some custom functionality.

*/

#pragma once

#include "inttypes.h"
#include <string>

class Int
{

public:


	const static int MaxU8;
	const static int MaxU16;
	const static int MaxU32;
	const static uint64_t MaxU64;

	const static int MaxS8;
	const static int MaxS16;
	const static int MaxS32;
	const static long long MaxS64;

};

class U8
{
public:

	U8();
	U8(int InInt);
	
	uint8_t& Ref();

	explicit operator int() const;
	explicit operator bool() const;

	bool operator<(const U8& l) const;

private:

	uint8_t I;

};

class U16
{
public:

	U16();
	U16(int InInt);

	uint16_t& Ref();

	explicit operator int() const;
	explicit operator bool() const;

	bool operator<(const U16& l) const;

private:

	uint16_t I;

};


class U32
{
public:

	U32();
	U32(int InInt);

	std::string ToStd();

	uint32_t& Ref();

	explicit operator int() const;
	explicit operator bool() const;

	bool operator<(const U32& l) const;

private:

	uint32_t I;
};


class U64
{
public:

	U64();
	U64(long long InInt);
	U64(const char* IntAsString);

	std::string ToStd();

	uint64_t& Ref();

	explicit operator bool() const;

	bool operator>(U64 InInt);
	bool operator>=(U64 InInt);
	bool operator<(U64 InInt);
	bool operator<=(U64 InInt);

	bool operator<(const U64& l) const;

private:

	uint64_t I;
};


class S8
{
public:

	S8() {};
};

class S16
{
public:

	S16() {};
};

class S32
{
public:

	S32() {};
};

class S64
{
public:

	S64() {};
};