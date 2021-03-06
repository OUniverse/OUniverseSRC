//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/ScribeP.h"
#include "System/AtlasLib.h"

#include "Key/GlobalK.h"


#include "Form/FormF.h"


#include <cohtml\Binding\Vector.h>
#include <cohtml\Binding\String.h>


#include "Min/DebugM.h"


ScribePro::ScribePro(DataC* InData)
{
	Data_ = InData;
}

void ScribePro::Activate()
{
	DBUG("SCRIBE PROTOCOL ACTIVE")
	DBUG(FCommandLine::GetOriginal())

	//GBIND("AtlasPreREQ", this, &ScribeP::UI_AtlasiPreREQ);
	//GBIND("AtlasiMOUNT", this, &ScribeP::UI_AtlasiMount);
	//GBIND("FormQUERY", this, &ScribeP::UI_FormQUERY);
	//GBIND("FormREQ", this, &ScribeP::UI_FormREQ);
	//GBIND("FormSAVE", this, &ScribeP::UI_FormSAVE);

	//GSEND0("start");

	//GSEND1("data.rec_atlaspre", Data_->GetAtlasPreArray().Vector());
}

void ScribePro::UI_AtlasiPreREQ()
{
		//GSEND1("atlasipre>", Data_->GetAtlasPreArray().Vector());
}

void ScribePro::UI_AtlasiMount(std::vector<int> AtlasiArr, bool ReqScribe)
{

	int l = AtlasiArr.size();
	ArrayC<AtlasUID> Atlasi;

	AtlasUID AUID;

	for (int i = 0; i < l; i++)
	{
		AUID = AtlasUID(AtlasiArr[i]);
		Atlasi.Add(AUID);
	}


//	Data_->GetAtlasLib()->Mount(Atlasi);


	if (ReqScribe)
	{

	}

}

void ScribePro::UI_FormQUERY(std::string InQuery)
{
	

}

void ScribePro::UI_FormREQ(int InAtlasUID, int InFormUID)
{

	AtlasUID AU = AtlasUID(InAtlasUID);
	FormUID FU = FormUID(InFormUID);

	//FormWrapS FormWrap = Data_->GetFormWrap(DuetUID(AU, FU));

	//GSEND2("form>", FormWrap.Atlas()->UID().ForUI(), FormWrap.Form()->Serialize().ToChar());
}

void ScribePro::UI_FormSAVE(std::string InFormJ)
{
	JsonS J = JsonS(StringC(InFormJ));

	AtlasUID AtlasU = J.ToAtlasUID(GlobalK::UID_Atlas);
	FormUID FormU = J.ToFormUID(GlobalK::UID);
	
	UpdateForm(DuetUID(AtlasU, FormU),J);
}

void ScribePro::UI_AtlasDocSAVE(int InAtlasUID)
{
	SaveAtlasDoc(AtlasUID(InAtlasUID));
}

void ScribePro::UpdateForm(DuetUID InDuet, JsonS InJ)
{
	//Data_->UpdateForm(InDuet, InJ);
}

void ScribePro::UpdateAtlas(AtlasUID InAtlasUID, std::string AtlasJson)
{
	JsonS J = JsonS(StringC(AtlasJson));
	//Data_->UpdateAtlas(InAtlasUID, J);
}

void ScribePro::SaveAtlasDoc(AtlasUID InAtlasUID)
{
	//Data_->SaveAtlasDoc(InAtlasUID);
}

