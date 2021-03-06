//Copyright 2015-2019, All Rights Reserved.

#include "System/SaveLib.h"
#include "System/Save.h"
#include "System/SaveDais.h"
#include "File/Save@.h"

#include "System/Log.h"

#include "Min/DebugM.h"




SaveLibC::~SaveLibC()
{
	Unload();
}

SaveLibC::SaveLibC(SaveDaisC* InSaveW)
{
	SaveDais_ = InSaveW;
}

void SaveLibC::Unload()
{
	Lib_.Cull();
}


void SaveLibC::Load(FolderC InFolder)
{
	Unload();
	Folder_ = InFolder;
	LOG(14863, Folder_.ToString().ToChar(), "Loading all Save data from folder: $V$")



			ArrayC<FileC> Fi = Folder_.GetFiles(SaveFI::Extension);
			int l = Fi.Len();

			for (int i = 0; i < l; i++)
			{
				DBUG(Fi[i].ToString().ToChar())
				SaveC* NewSave = SaveC::Create(Fi[i]);

				if (NewSave->IsValid())
				{
					Add(NewSave);
				}

			}

			LOG(15375, Lib_.Len(), "Loading Save data complete. Valid Saves found: $V$")
			LOGP
			return;
}

void SaveLibC::Set(int UID)
{
	SaveC* TrySave;
	if (Try(UID,TrySave))
	{
		SaveDais_->Set(TrySave);
	}
	else
	{
		DBUG("Save THAT SHOULD BE THERE WAS NOT")
		LOG(40016, UID, "The selected Save File is somehow not there. This is a terminating error. UID: $V$")
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

void SaveLibC::Add(SaveC* NewSave)
{
	Lib_.Add(NewSave);
}

ArrayC<SaveC*> SaveLibC::Saves()
{
	return Lib_;
}