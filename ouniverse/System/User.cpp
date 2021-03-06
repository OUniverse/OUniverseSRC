//Copyright 2015-2019, All Rights Reserved.

#include "System/User.h"

#include "Interface/Json.h"
#include "Interface/Provenance.h"

#include "File/User@.h"


#include "System/Log.h"

#include <fstream>

#include "System/LoadoutLib.h"

#include "Key/GlobalK.h"
#include "Key/UserK.h"


#include "Min/DebugM.h"


const int UserC::Provenance = 1;

UserC* UserC::Create(FolderC InFolder)
{
	UserC* NewUser = new UserC();
	NewUser->Folder_ = InFolder;
	return NewUser;
}

void UserC::Mount()
{
	LOG(10627, Combo_UID_ID(), "Mounting User: $V$")
}

StringC UserC::Combo_UID_ID()
{
	return StringC(UID_.ToString() +  StringC(" | ") + ID_);
}

void UserC::Dismount()
{
	LOG(25404, Combo_UID_ID(), "Dismounting User: $V$")
}


UserC::UserC()
{
	Valid_ = false;
}

void UserC::LoadMethod(StringC InFolderName)
{

	LOG(6835, InFolderName, "Processing New User: $V$")

	int ErrCode;
	ErrCode = UID_.ParseTitle(InFolderName);	

	if (ErrCode)
	{
		LOG(13451, ErrCode, "Name is incorrect. 1:Prefix Wrong, 2:Name can't become an Integer, 3:Integer of name is larger then max allowed size.  Error Code: $V$")
		return;
	}

	
	File_ = Folder_.ToFile(UserFI::FileName,UserFI::Extension);

	if (!File_.Exists())
	{
		LOG(13789, File_.ToString(), "File missing: $V$")
			return;
	}

	std::string LineSS;
	std::ifstream FileSS;

	FileSS.open(File_.ToString().ToChar());

	std::getline(FileSS, LineSS);
	ProvenanceC Prov = ProvenanceC(UserC::Provenance, StringC(LineSS).ToIntZeroFail());

	if(!Prov.IsValid())
	{
		LOG(505, Void(), "Provenance is Invalid");
		return;
	}

	if (!Prov.IsCurrent())
	{
		return;
	}



	std::getline(FileSS, LineSS);
	JsonS J = JsonS(StringC(LineSS));    

	if (!J.Has(GlobalK::ID))
	{
		LOG(300, GlobalK::ID, "Missing required Json Value: $V$")
			return;
	}

	if (!J.Key(GlobalK::ID).IsString())
	{
		LOG(302, GlobalK::ID, "Expected a Json String but value was wrong type: $V$﻿")
			return;
	}

	if (!J.Has(GlobalK::Glyph))
	{
		LOG(300, GlobalK::UID, "Missing required Json Value: $V$")
			return;
	}

	if (!J.Key(GlobalK::Glyph).IsNumber())
	{
		LOG(301, GlobalK::Glyph, "Expected a Json Number but value was wrong type: $V$﻿")
			return;
	}

	if (!J.Has(UserK::Score))
	{
		LOG(300, UserK::Score, "Missing required Json Value: $V$")
			return;
	}

	if (!J.Key(UserK::Score).IsNumber())
	{
		LOG(301, UserK::Score, "Expected a Json Number but value was wrong type: $V$﻿")
			return;
	}

	ID_ = J.String(GlobalK::ID);
	Glyph_ = J.Int(GlobalK::Glyph);
	Score_ = J.Int(UserK::Score);

	LOG(51990, ID_, "User is valid: $V$")
	Valid_ = true;
	
}

void UserC::CreateMethod(int InUID, StringC InID)
{
	File_ = Folder_.ToFile(UserFI::FileName, UserFI::Extension);
	UID_ = UserUID(InUID);
	ID_ = InID;
	Glyph_ = GlyphC(0);
	Score_ = 0;

	Valid_ = true;

	Save();
}

void UserC::Save()
{
	JsonS J = JsonS();
	J.Add(GlobalK::ID, ID_);
	J.Add(GlobalK::Glyph, Glyph_.ForUI());
	J.Add(UserK::Score, Score_);

	StringC Data = StringC(UserC::Provenance).NewLine();
	Data += J.Serialize();
	File_.Doc().Write(Data);
}

UserUID UserC::UID()
{
	return UID_;
}

StringC UserC::ID()
{
	return ID_;
}

int UserC::Score()
{
	return Score_;
}

bool UserC::IsValid()
{
	return Valid_;
}


FolderC UserC::Folder()
{
	return Folder_;
}