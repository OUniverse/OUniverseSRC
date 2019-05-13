//Copyright 2015-2019, All Rights Reserved.

#include "Form/Atlas.h"
#include "Form/Payload.h"

#include <fstream>
#include <string>

#include <rapidjson/document.h>


bool AtlasC::Extension(StringC InExtension)
{
	if (InExtension == StringC("atlas"))
	{
		return true;
	}
	return false;
}

AtlasC::VersionS::VersionS(const char* JSerialized)
{
	rapidjson::Document d;
	d.Parse(JSerialized);

	Incremental		= d["inc"].GetInt();
	Compatability	= d["cmp"].GetInt();
}

AtlasC::DetailsS::DetailsS(const char*  JSerialized)
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

AtlasC::QuantityS::QuantityS(const char* JSerialized)
{
	rapidjson::Document d;
	d.Parse(JSerialized);

	Form		= d["form"].GetInt();
	Translation = d["translation"].GetInt();
	Credit		= d["credit"].GetInt();
}

AtlasC::AtlasC(StringC InPath)
{
	Path = InPath;
	std::string Line;
	std::ifstream File;
	File.open(InPath.ToChar());

	if (!File.is_open()) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Loading Atlas FAILED"));
	}

	//while (std::getline(File, Line)) {

		std::getline(File, Line);
	    Version = new VersionS(Line.c_str());
		std::getline(File, Line);
		Details = new DetailsS(Line.c_str());
		std::getline(File, Line);
		Quantity = new QuantityS(Line.c_str());

	File.close();
}

void AtlasC::Scan(PayloadC* P)
{
	std::string Line;
	std::ifstream File;
	File.open(Path.ToChar());

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