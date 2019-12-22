//Copyright 2015-2019, All Rights Reserved.

#include "System/FormLib.h"
#include "System/FormTypes.h"

#include "Key/GlobalK.h"

#include "System/AtlasLib.h"

#include "System/FormData.h"

#include "Data/DataD.h"
#include "Form/ObjF.h"
#include "Data/CharacterD.h"
#include "Form/WorldF.h"
#include "Form/EpochF.h"
#include "Form/RegionF.h"
#include "Form/AreaF.h"

#include "System/Log.h"



FormLibC::FormLibC(AtlasC* InOwningAtlas)
{

	Len_ = 0;
	FormDataLen_ = 0;
	OwningAtlas = InOwningAtlas;

	FactoryArray.Init(FormTypesC::Types::TYPES_MAX, NULL);
	FactoryArray[FormTypesC::Types::Form]		= DataD::Create;
	FactoryArray[FormTypesC::Types::Obj]		= ObjF::Create;
	FactoryArray[FormTypesC::Types::Character]	= CharacterD::Create;
	FactoryArray[FormTypesC::Types::World]		= WorldF::Create;
	FactoryArray[FormTypesC::Types::Epoch]		= EpochF::Create;
	FactoryArray[FormTypesC::Types::Region]		= RegionF::Create;
	FactoryArray[FormTypesC::Types::Area]		= AreaF::Create;
}

FormLibC::~FormLibC()
{
	for(int i = 0; i < Len(); i++)
	{
		delete Lib_.At(i);
	}

	for (int i = 0; i < FormDataLen_; i++)
	{
		delete FormDataLib_.At(i);
	}
}

int FormLibC::Len()
{
	return Len_;
}

void FormLibC::AddList(JsonS* InJ, AtlasC* InAtlas, int InDataMode)
{

	int L = InJ->Len();


	if (InDataMode == AtlasLibC::DataMode::Writer)
	{
		for (int i = 0; i < L; i++)
		{
			JsonS NeuForm = InJ->At(i);
			int Type = NeuForm.Int(GlobalK::Type);
			DataD* Form = FactoryArray[Type](NeuForm);
			Add(Form);
			AddData(InAtlas,Form);
		}
	}
	else
	{
		for (int i = 0; i < L; i++)
		{
			JsonS NeuForm = InJ->At(i);
			int Type = NeuForm.Int(GlobalK::Type);
			DataD* Form = FactoryArray[Type](NeuForm);
			Add(Form);
		}
	}

	
}

void FormLibC::Demarshal()
{
	int L = Lib_.Len();

	for (int i = 0; i < L; i++)
	{
		Lib_.At(i)->Demarshal();
	}
}

void FormLibC::Add(DataD* InForm)
{
	Len_++;
	LOG(54439, InForm->UID().ForLog(), "Adding Form: $V$")
	Lib_.Add(InForm->UID(), InForm);
}

void FormLibC::AddData(AtlasC* InAtlas, DataD* InForm)
{
	FormDataLen_++;

	FormDataC* Neu = new FormDataC(InAtlas,InForm);
	FormDataLib_.Add(InForm->UID(), Neu);
}

DataD* FormLibC::Get(FormUID InUID)
{
	return Lib_[InUID];
}

bool FormLibC::Try(FormUID InUID, DataD*& InForm)
{
	return Lib_.Try(InUID, InForm);
}

void FormLibC::Query(FormQueryS* InQuery)
{
	FormWrapS FormWrap;

	for (int i = 0; i < Len(); i++)
	{
		FormWrap = FormWrapS(OwningAtlas, Lib_.At(i));
		InQuery->Scan(FormWrap);
	}

}

void FormLibC::QueryFormData(FormDataQueryC* InQuery)
{

	for (int i = 0; i < Len(); i++)
	{
		InQuery->Scan(FormDataLib_.At(i));
	}

}

FormWrapS FormLibC::GetFormWrap(FormUID InUID)
{
	return FormWrapS(OwningAtlas, Lib_[InUID]);
}


StringC FormLibC::Serialize()
{
	return ToJson().Serialize();
}

JsonS FormLibC::ToJson()
{
	ArrayC<JsonS> JArr;

	JsonS J = JsonS();

	for (int i = 0; i < Len(); i++)
	{
		JArr.Add(Lib_.At(i)->ToJson());
	}

	J.Array(JArr);

	return J;
}