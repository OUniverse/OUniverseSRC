//Copyright 2015-2019, All Rights Reserved.

#include "System/Amendment.h"
#include "Interface/Json.h"

#include "Key/GlobalK.h"

#include "Min/DebugM.h"


AmendmentC::AmendmentC(JsonS& InJ)
{
	Json_ = InJ;

	TAUID_ = U64(Json_.String(GlobalK::UID_Atlas_Target).ToChar());
	TUID_ = Json_.UInt32(GlobalK::UID_Target);
	UID_ = StringC(TAUID_.ToStd()) + StringC(".") + StringC(TUID_.ToStd());
	DBUG(UID_.ToChar())
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
	return ToJsonInternal(S);
}

JsonS AmendmentC::ToJsonInternal(JsonS& S)
{
	S.Add(GlobalK::UID_Atlas_Target, TAUID_);
	//S.Add(RevisionC::K_TUID, TUID_);
	S.Add(GlobalK::UID_Target, UID());
	return S;
}