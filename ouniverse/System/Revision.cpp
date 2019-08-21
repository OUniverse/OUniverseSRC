//Copyright 2015-2019, All Rights Reserved.

#include "System/Revision.h"
#include "Interface/Json.h"

#include "Key/GlobalK.h"


RevisionC::RevisionC(JsonS& InJ)
{
	Json_ = InJ;

	TargetAtlasUID_ = U64(Json_.String(GlobalK::UID_Atlas_Target).ToChar());
	TargetUID_ = Json_.UInt32(GlobalK::UID_Target);
	UID_ = StringC(TargetAtlasUID_.ToStd()) + StringC(".") + StringC(TargetUID_.ToStd());
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
	S.Add(GlobalK::UID_Atlas_Target, TargetAtlasUID_);
	S.Add(GlobalK::UID_Target, TargetUID_.Ref());
	return S;
}