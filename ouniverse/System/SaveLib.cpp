//Copyright 2015-2019, All Rights Reserved.

#include "System/SaveLib.h"
#include "System/Save.h"


#include "System/Log.h"

#include "Min/DebugM.h"




SaveLibC::~SaveLibC()
{
	for (int i = 0; i < Num(); i++)
	{
		delete Lib_[i];
	}
}

SaveLibC::SaveLibC(FolderC InFolder, SaveW* SaveW_)
{
	Folder_ = InFolder;
	Num_ = 0;
	DirLoaded_ = false;
}

void SaveLibC::LoadSaves()
{

	LOG(27073, Folder_.ToString(), "Loading all Save data from folder: $V$")

		if (DirLoaded_ == false)
		{

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

			DirLoaded_ = true;
			LOG(48414, Num(), "Loading Save data complete. Valid Saves found: $V$")
			LOGP
			return;
		}

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
int SaveLibC::Num()
{
	return Num_;
}

bool SaveLibC::IsSaveChosen()
{
	return false;
}

bool SaveLibC::HasSoloSave()
{
	return false;
}

bool SaveLibC::HasLastSave()
{
	return false;
}

void SaveLibC::AddSave(SaveC* NewSave)
{
	Num_++;
	Lib_.Add(NewSave);
}

ArrayC<SaveC*> SaveLibC::Saves()
{
	return Lib_;
}