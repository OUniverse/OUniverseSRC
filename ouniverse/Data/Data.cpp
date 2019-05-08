//Copyright 2015-2019, All Rights Reserved.

#include "Data/Data.h"
#include "json.h"

Data::Data()
{

}

Data::~Data() {};

void Data::Datify(TSharedPtr<FJsonObject> InDatra)
{
	Datra = InDatra;
	ID = FName(*(Datra->GetStringField(PODFIELD_ID)));
}

void Data::DatifyEnd()
{

}

void Data::Bloom()
{

}

void Data::BloomEnd()
{

}

void Data::Link()
{

}

void Data::LinkEnd()
{

}

void D_Area::Datify(TSharedPtr<FJsonObject> InDatra)
{
	MapID = InDatra->GetStringField("mid");
	Data::Datify(InDatra);
}
