//Copyright 2015-2019, All Rights Reserved.

#include "Data/DataD.h"
#include "System/FormTypes.h"
#include "Interface/Json.h"
#include "Key/GlobalK.h"

#include "System/FormVar.h"

#include "System/FormFieldPoly.h"

int DataD::Type()
{
	return FormTypesC::Types::Form;
}

DataD::DataD()
{

}

DataD* DataD::Create(JsonS& InJ)
{ 
	DataD* Obj = new DataD();
	Obj->Setup(InJ);
	return Obj;
}

void DataD::Setup(JsonS& InJ)
{
	Json_ = InJ;
	UID_ = Json_.ToFormUID(GlobalK::UID);
	ID_ = Json_.String(GlobalK::ID);
}

void DataD::Demarshal() 
{

}	

FormUID DataD::UID()
{
	return UID_;
}

StringC DataD::ID()
{
	return ID_;
}

void DataD::Update(JsonS& InJ)
{
	ID_ = InJ.String(GlobalK::ID);
}

StringC DataD::Serialize()
{
	return ToJson().Serialize();
}


JsonS DataD::ToJson()
{
	JsonS S = JsonS();
	return ToJsonInternal(&S);
}



JsonS* DataD::ToWriter(JsonS* InJ)
{
	ToJsonInternal(InJ);
	//InJ->Erase(GlobalK::UID);
	//InJ->Erase(GlobalK::Type);
	return InJ;
}

JsonS* DataD::ToJsonInternal(JsonS* S)
{
	S->Add(GlobalK::UID, UID());
	S->Add(GlobalK::ID, ID());
	S->Add(GlobalK::Type, Type());
	return S;
}

bool DataD::TryVP(int VarID, void*& VP)
{
	switch (VarID) {
	case FormVarC::UID:
		VP = &UID_;
		return true;
	case FormVarC::ID:
		VP = &ID_;
		return true;
	}

	return false;
}


PolyC* DataD::Poly()
{
	PolyObjectC* Neu = new PolyObjectC("", 0);
	PolyInternal(Neu);
	return Neu;
}

PolyC* DataD::PolyInternal(PolyObjectC* InPoly)
{
	InPoly->AddKey(new PolyIntC("uid", 0, UID().ToInt()));
	InPoly->AddKey(new PolyStringC("id", 0, ID()));
	InPoly->AddKey(new PolyIntC("type", 0, Type()));

	return InPoly;
}