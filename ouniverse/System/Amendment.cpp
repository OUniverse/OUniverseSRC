//Copyright 2015-2019, All Rights Reserved.

#include "System/Amendment.h"
#include "Interface/Json.h"

#include "Key/GlobalK.h"


AmendmentC::AmendmentC(JsonS& InJ)
{
	Json_ = InJ;

	TargetAtlasUID_ = U64(Json_.String(GlobalK::UID_Atlas_Target).ToChar());
	TargetUID_ = Json_.UInt32(GlobalK::UID_Target);
	UID_ = StringC(TargetAtlasUID_.ToStd()) + StringC(".") + StringC(TargetUID_.ToStd());
}

AmendmentC* AmendmentC::Create(JsonS& InJ)
{
	return new AmendmentC(InJ);
}

StringC AmendmentC::UID()
{
	return UID_;
}


void AmendmentC::Update(JsonS& InJ)
{

}

StringC AmendmentC::Serialize()
{
	return ToJson().Serialize();
}


JsonS AmendmentC::ToJson()
{
	JsonS S = JsonS();
	S.Add(GlobalK::UID_Atlas_Target, StringC(TargetAtlasUID_.ToStd()));
	S.Add(GlobalK::UID_Target, TargetUID_.Ref());
	return S;
}