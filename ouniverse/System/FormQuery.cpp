//Copyright 2015-2019, All Rights Reserved.

#include "System/FormQuery.h"
#include "Data/DataD.h"

#include "System/FormData.h"

bool FormQueryBooleanS::Valid(AtlasC* Atlas, DataD* Form)
{
	return false;
}

FormQueryBooleanS::~FormQueryBooleanS()
{

}

FQB_ID_CaseInsensitiveS::FQB_ID_CaseInsensitiveS(StringC InQueryID)
{
	QueryID_ = InQueryID.ToLower();
}

bool FQB_ID_CaseInsensitiveS::Valid(AtlasC* Atlas, DataD* Form)
{
	
	if (Form->ID().ToLower().Contains(QueryID_))
	{
		return true;
	}
	
	return false;

}


FormQueryS::FormQueryS(StringC InQuery, ArrayC<FormWrapS>* InFormArr)
{

	ValidForms_ = InFormArr;

	BooleanLen_ = 0;

	if (InQuery != "")
	{
		FQB_ID_CaseInsensitiveS* Check = new FQB_ID_CaseInsensitiveS(InQuery);
		AddBoolean(Check);
	}
}

FormQueryS::~FormQueryS()
{

		for (int i = 0; i < BooleanLen(); i++)
		{
			delete Booleans_[i];
		}
}


void FormQueryS::AddBoolean(FormQueryBooleanS* InBoolean)
{
	BooleanLen_++;
	Booleans_.Add(InBoolean);
}

int FormQueryS::BooleanLen()
{
	return BooleanLen_;
}
void FormQueryS::Scan(FormWrapS InForm)
{

	bool isValid = true;
	for (int i = 0; i < BooleanLen(); i++)
	{
		if (!Booleans_[i]->Valid(InForm.Atlas(),InForm.Form()))
		{
			isValid = false;
			break;
		}
	}

	if (isValid)
	{
		ValidForms_->Add(InForm);
	}
}






















FormDataQueryC::FormDataQueryC(StringC InQuery, ArrayC<FormDataC*>* InFormArr)
{

	ValidForms_ = InFormArr;

	BooleanLen_ = 0;

	if (InQuery != "")
	{
		FQB_ID_CaseInsensitiveS* Check = new FQB_ID_CaseInsensitiveS(InQuery);
		AddBoolean(Check);
	}
}

FormDataQueryC::~FormDataQueryC()
{

	for (int i = 0; i < BooleanLen(); i++)
	{
		delete Booleans_[i];
	}
}


void FormDataQueryC::AddBoolean(FormQueryBooleanS* InBoolean)
{
	BooleanLen_++;
	Booleans_.Add(InBoolean);
}

int FormDataQueryC::BooleanLen()
{
	return BooleanLen_;
}

void FormDataQueryC::Scan(FormDataC* InForm)
{

	bool isValid = true;
	for (int i = 0; i < BooleanLen(); i++)
	{
		if (!Booleans_[i]->Valid(InForm->Atlas(),InForm->Form()))
		{
			isValid = false;
			break;
		}
	}

	if (isValid)
	{
		ValidForms_->Add(InForm);
	}
}