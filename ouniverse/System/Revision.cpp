//Copyright 2015-2019, All Rights Reserved.

#include "System/Revision.h"
#include "Interface/Json.h"

#include "Key/GlobalK.h"

#include "Min/DebugM.h"



RevisionC::RevisionC(JsonS& InJ)
{
	Json_ = InJ;

	TAUID_ = U64(Json_.String(GlobalK::UID_Atlas_Target).ToChar());
	TUID_ = Json_.UInt32(GlobalK::UID_Target);
	UID_ = StringC(TAUID_.ToStd()) + StringC(".") + StringC(TUID_.ToStd());
	DBUG(UID_.ToChar())
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
	return ToJsonInternal(S);
}

JsonS RevisionC::ToJsonInternal(JsonS& S)
{
	S.Add(GlobalK::UID_Atlas_Target, TAUID_);
	//S.Add(RevisionC::K_TUID, TUID_);
	S.Add(GlobalK::UID_Target, UID());
	return S;
}