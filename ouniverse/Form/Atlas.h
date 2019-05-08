//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "CoreMinimal.h"

class PayloadC;

class AtlasC
{
	friend PayloadC;

public: 

	static bool Extension(const FString InExtension);

private:

	AtlasC(FString InPath);	

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
		FString ID;
		FString Name;
		FString Author;
		FString Description;
		FString Website;
		FString Icon;
		FString Date;

		DetailsS(const char* JSerialized);
	};

	FString Path;

	VersionS* Version;
	QuantityS* Quantity;
	DetailsS* Details;

	void Scan(PayloadC* P);

};