//Copyright 2015-2019, All Rights Reserved.

/**
Each data type is giving an extension of the DataFactory.
This allows the DataManager object to mass produce Data objects from the JSON it parses.
 */

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

class Data;

class DataFactory
{
public:
	virtual Data* Create();
};

class F_Data : public DataFactory
{
	Data* Create() override;
};

class F_Ref : public DataFactory
{
	Data* Create() override;
};

class F_Area : public DataFactory
{
	Data* Create() override;
};

class F_Actra : public DataFactory
{
	Data* Create() override;
};

class F_Static : public DataFactory
{
	Data* Create() override;
};
