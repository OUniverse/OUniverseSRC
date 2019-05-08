//Copyright 2015-2019, All Rights Reserved.

/**
OUniverse is a data driven game which is loaded from parsed JSON text documents shortly after the User is selected in the boot process.

The data is parsed from JSON text into a Data object. There are many different kinds of data objects but they all extend this Data.

When a databased object is created in the game, a template of it is created and combined with it's Data entry.
Data is stored via converting it's Atlas+ID into a FName where it is stored as a unique integer.

Data is not stored as a UObject and instead is stored as a standard C++ class.
- Large amounts of data objects are expected to be created. 
- The core game uses 10s of thousands and every Atlas mod could use just as many.
- Reduce the over head of massive amounts of UObjects.
 */

#pragma once

#include "CoreMinimal.h"
//#include "UObject/NoExportTypes.h"

#define PODFIELD_DATA "data"
#define PODFIELD_ID "i"
#define PODFIELD_NAME "n"
#define PODFIELD_DATATYPE "f"

class FJsonObject;

class Data
{

public:

	TSharedPtr<FJsonObject> Datra;
	FName ID;

	Data();

	virtual void Datify(TSharedPtr<FJsonObject> InDatra);

	void DatifyEnd();

	void Bloom();

	void BloomEnd();

	void Link();

	void LinkEnd();

	virtual ~Data();
};

class D_Area : public Data
{

public:
	FString MapID;
	virtual void Datify(TSharedPtr<FJsonObject> InDatra) override;
};


class D_Actra : public Data
{
public:
};

class D_Human : public Data
{

public:

};

class D_Ref : public Data
{

public:

};

class D_Static : public Data
{

public:

};
