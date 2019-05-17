//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "CoreMinimal.h"
#include "Interface/String.h"

class PayloadC;

class AtlasC
{
	friend PayloadC;

public: 

	static bool Extension(StringC InExtension);

private:

	AtlasC(StringC InPath);

	struct VersionS
	{
		int Incremental;
		int Compatability;

		VersionS(const char* JSerialized);
	};

	struct QuantityS
	{
		int Form;
		int Translation;
		int Credit;

		QuantityS(const char* JSerialized);
	};

	struct DetailsS
	{
		int ID;
		StringC Name;
		StringC Author;
		StringC Description;
		StringC Website;
		StringC Icon;
		StringC Date;

		DetailsS(const char* JSerialized);
	};

	StringC Path;

	VersionS* Version;
	QuantityS* Quantity;
	DetailsS* Details;

	void Scan(PayloadC* P);

};