//Copyright 2015-2019, All Rights Reserved.

#include "Form/FormF.h"
#include "System/FormTypes.h"
#include "Interface/Json.h"
#include "Key/GlobalK.h"


int FormF::Type()
{
	return FormTypesC::Types::Form;
}

FormF::FormF(JsonS& InJ)
{
	Json_ = InJ;
	UID_ = Json_.UInt32(GlobalK::UID);
	ID_ =  Json_.String(GlobalK::ID);
}

FormF* FormF::Create(JsonS& InJ)
{ 
	return new FormF(InJ); 
}

void FormF::Marshal() {}	

U32 FormF::UID()
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
	S.Add(GlobalK::UID, UID().Ref());
	S.Add(GlobalK::ID, ID());
	S.Add(GlobalK::Type, Type());
	return S;
}