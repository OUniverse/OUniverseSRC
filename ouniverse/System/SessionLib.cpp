//Copyright 2015-2019, All Rights Reserved.

#include "System/SessionLib.h"
 
#include "Dais/Session.h"
#include "Interface/FileQuery.h"

#include "Min/LogM.h"

SessionLib::SessionLib(StringC SessionFolderPath)
{
	Path_ = SessionFolderPath;

	FileQueryS Fi = FileQueryS(Path_ / "", ".oss");

	int Num = Fi.Num();

	LOG(BOOT, 0, 0, StringC("Save Files Found: ")+StringC(Num))

	for (int i = 0; i < Num; i++)
	{
		//LOG(BOOT, 0, 0, Fi.Full(i))
		SessionC* NewSave = new SessionC(Fi.File(i), Fi.Full(i));

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

	LOG(BOOT, 0, 0, "SessionLib has completed loading save files")
}

SessionLib* SessionLib::Create(StringC SessionFolderPath)
{
	return new SessionLib(SessionFolderPath);
}

int SessionLib::Num()
{
	return Num_;
}