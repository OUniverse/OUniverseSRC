//Copyright 2015-2019, All Rights Reserved.

#include "System/SessionLib.h"
 
#include "System/Session.h"
#include "Interface/FileQuery.h"

#include "System/Log.h"



const char* SessionLibC::EXT = "oss";



SessionLibC::SessionLibC(StringC InUserPath)
{

	Path_ = InUserPath;

	LOG(31258, Path_ / "", "Scanning directory : $V$")
	FileQueryS Fi = FileQueryS(Path_ /".", SessionLibC::EXT);
	

	Num_ = Fi.Num();

	LOG(34231, Num_, "Files in directory: $V$")

	for (int i = 0; i < Num_; i++)
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

	if (Num_ == 0)
	{
		LOG(22980, Void(), "No valid files found.")
	}
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

ArrayC<SessionC*> SessionLibC::Sessions()
{
	return SessionArray;
}