//Copyright 2015-2019, All Rights Reserved.

#include "System/SaveLib.h"
#include "System/Save.h"


#include "System/Log.h"

#include "Min/DebugM.h"




SaveLibC::~SaveLibC()
{
	Unload();
}

SaveLibC::SaveLibC(SaveW* InSaveW)
{
	SaveW_ = InSaveW;
}

void SaveLibC::Unload()
{
	Lib_.Cull();
}


void SaveLibC::Load(FolderC InFolder)
{

	Unload();
	Folder_ = InFolder;
	LOG(27073, Folder_.ToString().ToChar(), "Loading all Save data from folder: $V$")



			ArrayC<FolderC> Fo = Folder_.GetFolders();
			int l = Fo.Len();

			for (int i = 0; i < l; i++)
			{
				DBUG(Fo[i].ToString().ToChar())
				SaveC* NewSave = SaveC::Create(Fo[i], Fo[i].GetFinalDir());

				if (NewSave->IsValid())
				{
					AddSave(NewSave);
				}

			}

			LOG(48414, Lib_.Len(), "Loading Save data complete. Valid Saves found: $V$")
			LOGP
			return;


	LOG(62059, Void(), "Loading Save data skipped. The directory has already been scanned since the program opened.")
}

void SaveLibC::SetSave(int UID)
{
	SaveC* TrySave;
	if (Try(UID,TrySave))
	{
		SaveW_->Set(TrySave);
	}
	else
	{
		DBUG("Save THAT SHOULD BE THERE WAS NOT")
	}
}

bool SaveLibC::Try(int UID, SaveC*& InSave)
{
	int L = Lib_.Len();
	for (int i = 0; i < L; i++)
	{
		if (Lib_[i]->UID() == UID)
		{
			InSave = Lib_[i];
			return true;
		}
	}

	return false;
}

void SaveLibC::AddSave(SaveC* NewSave)
{
	Lib_.Add(NewSave);
}

ArrayC<SaveC*> SaveLibC::Saves()
{
	return Lib_;
}