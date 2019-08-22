//Copyright 2015-2019, All Rights Reserved.

#include "System/Amendment.h"
#include "Interface/Json.h"

#include "Key/GlobalK.h"


AmendmentC::AmendmentC(JsonS& InJ)
{
	Json_ = InJ;
	Target_ = DuetUID(Json_.Int(GlobalK::UID_Atlas_Target), Json_.Int(GlobalK::UID_Target));
	UID_ = Target_.String(); 
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
	S.Add(GlobalK::UID_Atlas_Target, Target_.Atlas().UID());
	S.Add(GlobalK::UID_Target, Target_.Form().UID());
	return S;
}