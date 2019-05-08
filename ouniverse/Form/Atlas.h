//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "CoreMinimal.h"

class Payload;

class Atlas
{
	friend Payload;

public: 

	static bool Extension(const FString InExtension);

private:

	Atlas(FString InPath);	

	struct VersionSuite
	{
		int Incremental;
		int Compatability;

		VersionSuite(const char* JSerialized);
	};

	struct QuantitySuite
	{
		int Form;
		int Translation;
		int Credit;

		QuantitySuite(const char* JSerialized);
	};

	struct DetailsSuite
	{
		FString ID;
		FString Name;
		FString Author;
		FString Description;
		FString Website;
		FString Icon;
		FString Date;

		DetailsSuite(const char* JSerialized);
	};

	FString Path;

	VersionSuite* Version;
	QuantitySuite* Quantity;
	DetailsSuite* Details;

	void Scan(Payload* P);

};