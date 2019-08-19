//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/ScribeP.h"
#include "System/Data.h"
#include "System/AtlasLib.h"

#include "System/Glass.h"
#include "Min/DebugM.h"

#include "System/Atlas^.h"

#include <cohtml\Binding\Vector.h>
#include <cohtml\Binding\String.h>

ScribeP::ScribeP(DataC* InData)
{
	Data_ = InData;
}

void ScribeP::Activate()
{
	DBUG("SCRIBE PROTOCOL ACTIVE")
	DBUG(FCommandLine::GetOriginal())
		

	GBIND("ScribeP.ReqAtlasPre", this, &ScribeP::ReqAtlasPre);
	GBIND("ScribeP.LoadAtlasi", this, &ScribeP::LoadAtlasi);
	GBIND("ScribeP.FormQuery", this, &ScribeP::FormQuery);

	GSEND0("start");

	//GSEND1("data.rec_atlaspre", Data_->GetAtlasPreArray().Vector());
}

void ScribeP::ReqAtlasPre()
{
	DBUG("REQUESTING ATLAS PRE")

	GSEND1("data.rec_atlaspre", Data_->GetAtlasPreArray().Vector());
}

void ScribeP::LoadAtlasi(std::vector<std::string> AtlasiSelection,bool ReqScribe)
{
	
	StringC DataString = StringC(AtlasiSelection[0]);
	//JsonS J = JsonS(DataString);


	int l = AtlasiSelection.size();
	ArrayC<U64> Atlasi;

	for (int i = 0; i < l; i++)
	{
		Atlasi.Add(U64(DataString.ToChar()));
		DBUG(StringC(Atlasi[i].ToStd()).ToChar())
	}

	Data_->GetAtlasLib()->Mount(Atlasi);


	if (ReqScribe)
	{
		Data_->GetFormPilots();
	}

}

void ScribeP::FormQuery(std::string Query)
{

}