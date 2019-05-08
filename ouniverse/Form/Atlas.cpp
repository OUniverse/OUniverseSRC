//Copyright 2015-2019, All Rights Reserved.

#include "Form/Atlas.h"
#include "Form/Payload.h"

#include <fstream>
#include <string>

#include <rapidjson/document.h>


bool Atlas::Extension(const FString InExtension)
{
	if (InExtension == "atlas")
	{
		return true;
	}
	return false;
}

Atlas::VersionSuite::VersionSuite(const char* JSerialized)
{
	rapidjson::Document d;
	d.Parse(JSerialized);

	Incremental		= d["inc"].GetInt();
	Compatability	= d["cmp"].GetInt();
}

Atlas::DetailsSuite::DetailsSuite(const char*  JSerialized)
{
	rapidjson::Document d;
	d.Parse(JSerialized);

	ID			= d["id"].GetString();
	Name		= d["name"].GetString();
	Description	= d["desc"].GetString();
	Author		= d["author"].GetString();
	Icon		= d["icon"].GetString();
	Date		= d["date"].GetString();
	Website		= d["web"].GetString();
}

Atlas::QuantitySuite::QuantitySuite(const char* JSerialized)
{
	rapidjson::Document d;
	d.Parse(JSerialized);

	Form		= d["form"].GetInt();
	Translation = d["translation"].GetInt();
	Credit		= d["credit"].GetInt();
}

Atlas::Atlas(FString InPath)
{
	Path = InPath;
	std::string Line;
	std::ifstream File;
	File.open(*Path);

	if (!File.is_open()) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Loading Atlas FAILED"));
	}

	//while (std::getline(File, Line)) {

		std::getline(File, Line);
	    Version = new VersionSuite(Line.c_str());
		std::getline(File, Line);
		Details = new DetailsSuite(Line.c_str());
		std::getline(File, Line);
		Quantity = new QuantitySuite(Line.c_str());

	File.close();
}

void Atlas::Scan(Payload* P)
{
	std::string Line;
	std::ifstream File;
	File.open(*Path);

	if (!File.is_open()) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Loading Atlas FAILED"));
	}

	for (int i=0;i<3;i++)
	{
		getline(File, Line);
	}
	

	for (int i = 0; i < Quantity->Form; i++)
	{
		getline(File, Line);
		P->AddForm(Line);
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, Line.c_str());
	}

	File.close();
	
}