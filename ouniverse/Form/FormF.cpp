//Copyright 2015-2019, All Rights Reserved.

#include "Form/FormF.h"
#include "System/FormTypes.h"
#include "Interface/Json.h"
#include "Key/GlobalK.h"

int FormF::Type()
{
	return FormTypesC::Types::Form;
}

FormF::FormF()
{

}

FormF* FormF::Create(JsonS& InJ)
{ 
	FormF* Obj = new FormF();
	Obj->Setup(InJ);
	return Obj;
}

void FormF::Setup(JsonS& InJ)
{
	Json_ = InJ;
	UID_ = Json_.ToFormUID(GlobalK::UID);
	ID_ = Json_.String(GlobalK::ID);
}

void FormF::Demarshal() 
{

}	

FormUID FormF::UID()
{
	return UID_;
}

StringC FormF::ID()
{
	return ID_;
}

void FormF::Update(JsonS& InJ)
{
	ID_ = InJ.String(GlobalK::ID);
}

StringC FormF::Serialize()
{
	return ToJson().Serialize();
}


JsonS FormF::ToJson()
{
	JsonS S = JsonS();
	return ToJsonInternal(S);
}

JsonS FormF::ToJsonInternal(JsonS& S)
{
	S.Add(GlobalK::UID, UID());
	S.Add(GlobalK::ID, ID());
	S.Add(GlobalK::Type, Type());
	return S;
}