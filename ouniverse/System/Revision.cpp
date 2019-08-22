//Copyright 2015-2019, All Rights Reserved.

#include "System/Revision.h"
#include "Interface/Json.h"

#include "Key/GlobalK.h"

RevisionC::RevisionC(JsonS& InJ)
{
	Json_ = InJ;
	Target_ = DuetUID(Json_.Int(GlobalK::UID_Atlas_Target), Json_.Int(GlobalK::UID_Target));
	UID_ = Target_.String();
}

RevisionC* RevisionC::Create(JsonS& InJ)
{
	return new RevisionC(InJ);
}

StringC RevisionC::UID()
{
	return UID_;
}


void RevisionC::Update(JsonS& InJ)
{

}

StringC RevisionC::Serialize()
{
	return ToJson().Serialize();
}


JsonS RevisionC::ToJson()
{
	JsonS S = JsonS();
	S.Add(GlobalK::UID_Atlas_Target, Target_.Atlas().UID());
	S.Add(GlobalK::UID_Target, Target_.Form().UID());
	return S;
}