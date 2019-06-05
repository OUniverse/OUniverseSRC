//Copyright 2015-2019, All Rights Reserved.

/**

## String

**Class:** StringC

Generic string implementation.
> Wrapper around a std::string with some custom functionality.

*/

#pragma once

#include "inttypes.h"


class Int
{

public:


	static int MaxU8();
	static int MaxU16();
	static int MaxU32();
	static uint64_t MaxU64();

	static int Max8();
	static int Max16();
	static int Max32();
	static long long Max64();

};

class U8
{
public:

	U8();
	U8(int InInt);

	uint8_t& Ref();

	explicit operator bool() const;

private:

	uint8_t I;

};

class U16
{
public:

	U16();
	U16(int InInt);

	uint16_t& Ref();

	explicit operator bool() const;

private:

	uint16_t I;

};


class U32
{
public:

	U32();
	U32(int InInt);

	uint32_t& Ref();

	explicit operator bool() const;

private:

	uint32_t I;
};


class U64
{
public:

	U64();
	U64(long long InInt);

	uint64_t& Ref();

	explicit operator bool() const;

	bool operator>(U64 InInt);
	bool operator>=(U64 InInt);
	bool operator<(U64 InInt);
	bool operator<=(U64 InInt);

private:

	uint64_t I;
};