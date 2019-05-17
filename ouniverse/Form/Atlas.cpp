//Copyright 2015-2019, All Rights Reserved.

#include "Form/Atlas.h"
#include "Form/Payload.h"

#include <fstream>
#include <string>

#include "Interface/Json.h"


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
	JsonS J = JsonS(JSerialized);

	Incremental		= J.Int("inc");
	Compatability	= J.Int("cmp");
}

AtlasC::DetailsS::DetailsS(const char*  JSerialized)
{
	JsonS J = JsonS(JSerialized);

	ID			= J.Int("id");
	Name		= J.String("name");
	Icon		= J.String("icon");
	Description	= J.String("desc");
	Author		= J.String("author");
	Website		= J.String("web");
	Date		= J.String("date");

}

AtlasC::QuantityS::QuantityS(const char* JSerialized)
{
	JsonS J = JsonS(JSerialized);

	Form		= J.Int("form");
	Translation = J.Int("translation");
	Credit		= J.Int("credit");
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
	else
	{

		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, InPath.ToFString());

		//while (std::getline(File, Line)) {

		std::getline(File, Line);
		Version = new VersionS(Line.c_str());
		std::getline(File, Line);
		Details = new DetailsS(Line.c_str());
		std::getline(File, Line);
		Quantity = new QuantityS(Line.c_str());
	}


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