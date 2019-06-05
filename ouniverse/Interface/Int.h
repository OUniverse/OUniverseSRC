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

	static bool Is32U(int N);

	static int MaxU8();
	static int MaxU16();
	static int MaxU32();
	static uint64_t MaxU64();

	static int Max8();
	static int Max16();
	static int Max32();
	static long long Max64();

};

class UInt8
{
public:

	UInt8();
	UInt8(int InInt);

	uint8_t& Ref();

	explicit operator bool() const;

private:

	uint8_t I;

};

class UInt16
{
public:

	UInt16();
	UInt16(int InInt);

	uint16_t& Ref();

	explicit operator bool() const;

private:

	uint16_t I;

};

class UInt64
{
public:

	UInt64();
	UInt64(long long InInt);

	uint64_t& Ref();

	explicit operator bool() const;

	bool operator>(UInt64 InInt);
	bool operator>=(UInt64 InInt);
	bool operator<(UInt64 InInt);
	bool operator<=(UInt64 InInt);

private:

	uint64_t I;
};

class UInt32
{
public:

	UInt32();
	UInt32(int InInt);

	uint32_t& Ref();

	explicit operator bool() const;

private:

	uint32_t I;
};