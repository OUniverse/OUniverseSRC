//Copyright 2015-2019, All Rights Reserved.

#include "System/SessionLib.h"
 
#include "System/Session.h"
#include "Interface/FileQuery.h"

#include "Min/LogM.h"

SessionLibC::SessionLibC(StringC InUserPath)
{
	Path_ = InUserPath;

	FileQueryS Fi = FileQueryS(Path_ / "", ".oss");

	int Num = Fi.Num();

	LOG(BOOT, 0, 0, StringC("Save Files Found: ")+StringC(Num))

	for (int i = 0; i < Num; i++)
	{
		//LOG(BOOT, 0, 0, Fi.Full(i))
		SessionC* NewSave = new SessionC(Fi.File(i), Fi.Full(i));
		SessionArray.Add(NewSave);
		//LOG(BOOT, 0, 0, ".oss found ")
		//	LOG(BOOT, 0, 0, Fi.Full(i))
		//LOG(BOOT, 0, 0, FileReadS(Fi.Full(i)).Out().ToChar())
		//if (NewSave->IsValid())
		//{
		//	PreDaisArray.Add(NewSave);
		//}
		//else
		//{
		//	delete NewSave;
		//}

	}

	if (Num == 0)
	{
		LOG(BOOT, 0, 0, "This user has no save files.")
	}
	LOG(BOOT, 0, 0, "SessionLib has completed loading save files")
}

bool SessionLibC::Try(int InUID, SessionC*& OutSession)
{

	int L = SessionArray.Len();
	for (int i = 0; i < L; i++)
	{
		if (SessionArray[i]->GetUID() == InUID)
		{
			OutSession = SessionArray[i];
			return true;
		}
	}

	return false;
}

SessionLibC* SessionLibC::Create(StringC InUserPath)
{
	return new SessionLibC(InUserPath);
}

int SessionLibC::Num()
{
	return Num_;
}