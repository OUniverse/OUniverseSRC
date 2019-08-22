//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/ScribeP.h"
#include "System/Data.h"
#include "System/AtlasLib.h"

#include "Key/GlobalK.h"

#include "System/Glass.h"

#include "System/Atlas^.h"

#include "Form/FormF.h"
#include "System/FormPilot.h"
#include "System/FormPilot^.h"

#include <cohtml\Binding\Vector.h>
#include <cohtml\Binding\String.h>


#include "Min/DebugM.h"


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
	GBIND("ScribeP.FormREQ", this, &ScribeP::FormREQ);
	GBIND("ScribeP.FormSAVE", this, &ScribeP::FormSAVE);

	GSEND0("start");

	//GSEND1("data.rec_atlaspre", Data_->GetAtlasPreArray().Vector());
}

void ScribeP::ReqAtlasPre()
{
	DBUG("REQUESTING ATLAS PRE")

		GSEND1("data.rec_atlaspre", Data_->GetAtlasPreArray().Vector());
}

void ScribeP::LoadAtlasi(std::vector<int> AtlasiArr, bool ReqScribe)
{

	int l = AtlasiArr.size();
	ArrayC<AtlasUID> Atlasi;

	AtlasUID AUID;

	for (int i = 0; i < l; i++)
	{
		AUID = AtlasUID(AtlasiArr[i]);
		Atlasi.Add(AUID);
	}


	Data_->GetAtlasLib()->Mount(Atlasi);


	if (ReqScribe)
	{

	}

}

void ScribeP::FormQuery(std::string InQuery)
{
	FormQueryS* Query = new FormQueryS(InQuery);
	Data_->Query(Query);

	int L = Query->ValidForms_.Len();

	ArrayC<FormPilotS*> FormPilots;
	FormWrapS CurForm;
	DuetUID LoopDuet;
	for (int i = 0; i < L; i++)
	{
		CurForm = Query->ValidForms_[i];
		LoopDuet = DuetUID(CurForm.Atlas()->UID(), CurForm.Form()->UID());
		FormPilots.Add(new FormPilotS(LoopDuet, CurForm.Form()->ID(), CurForm.Form()->Type()));
	}

	GSEND1("formlist>", FormPilots.Vector());

	L = FormPilots.Len();

	for (int i = 0; i < L; i++)
	{
		delete FormPilots[i];
	}

	delete Query;
	DBUG("END QUERY")

}

void ScribeP::FormREQ(int InAtlasUID, int InFormUID)
{

	FormWrapS FormWrap = Data_->GetFormWrap(DuetUID(InAtlasUID, InFormUID));

	GSEND2("form>", FormWrap.Atlas()->UID().ForUI(), FormWrap.Form()->Serialize().ToChar());
}

void ScribeP::FormSAVE(std::string InFormJ)
{
	JsonS J = JsonS(StringC(InFormJ));

	AtlasUID AtlasU = J.ToAtlasUID(GlobalK::UID_Atlas);
	FormUID FormU = J.ToFormUID(GlobalK::UID);
	
	UpdateForm(DuetUID(AtlasU, FormU),J);
}

void ScribeP::AtlasDocSAVE(int InAtlasUID)
{
	SaveAtlasDoc(AtlasUID(InAtlasUID));
}

void ScribeP::UpdateForm(DuetUID InDuet, JsonS InJ)
{
	Data_->UpdateForm(InDuet, InJ);
}

void ScribeP::UpdateAtlas(AtlasUID InAtlasUID, std::string AtlasJson)
{
	JsonS J = JsonS(StringC(AtlasJson));
	Data_->UpdateAtlas(InAtlasUID, J);
}

void ScribeP::SaveAtlasDoc(AtlasUID InAtlasUID)
{
	Data_->SaveAtlasDoc(InAtlasUID);
}

