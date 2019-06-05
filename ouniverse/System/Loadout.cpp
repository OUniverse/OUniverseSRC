//Copyright 2015-2019, All Rights Reserved.

#include "System/Loadout.h"

#include "Min/DebugM.h"

const char* LoadoutC::K_UID		= "u";
const char* LoadoutC::K_NAME	= "n";
const char* LoadoutC::K_ATLAS	= "a";

LoadoutC::ComboS::ComboS(JsonS InJ)
{
	UID_ = InJ.UInt16(LoadoutC::K_UID);
	Name_ = InJ.String(LoadoutC::K_NAME);

	DBUG(Name_.ToChar())
}

LoadoutC::LoadoutC(int InUID,StringC InStr)
{
	JsonS J = JsonS(StringC(InStr));

	UID_ = InUID;


	JsonS JA = J[LoadoutC::K_ATLAS];
	int L = JA.Size();		

	for (int i = 0; i < L; i++)
	{
		ComboS NewCombo = ComboS(JA[i]);
		Atlases_.Add(NewCombo);
	}

}

U8 LoadoutC::GetUID()
{
	return UID_;
}