//Copyright 2015-2019, All Rights Reserved.

#include "System/UserManager.h"
#include "System/User.h"

#include "System/ConfigManager.h"
#include "Util/FileFriend.h"
#include "Util/Incrementer.h"
//For now including PathManager to get some extensions
#include "System/Paths.h"
#include "Json.h"


UserManager* UserManager::Create(ConfigManager* ConfigM, FString* UserDir)
{
	return new UserManager(ConfigM, UserDir);
}

UserManager::UserManager(ConfigManager* ConfigM, FString* UserDirectory)
{
	Config = ConfigM;
	UsersDir = UserDirectory;
	UserCount = 0;
	bUsersScanned = false;
	Inc = new Incrementer();
}

User* UserManager::GetActiveUser()
{
	return ActiveUser;
}

void UserManager::SetActiveUser(User* NewActiveUser)
{
	ActiveUser = NewActiveUser;
	//LOG(LBOOT, 1, "UserM: User Selected: " + NewActiveUser->ID);


	Config->LoadUserINI();
	//Major->PlaythroughManager->Reset();
	//Major->PlaythroughManager->LoadPlaythroughPilots();
}

void UserManager::SetActiveUserFromSN(int SN)
{
	User* SelectedUser;
	TryGetUserBySN(SN, *&SelectedUser);
	SetActiveUser(SelectedUser);
}

void UserManager::GetAllUsers()
{
	FString UsersDirectory = *UsersDir;

	//LOG(LBOOT, 1, "UserM: GetAllUsers...");
	if (bUsersScanned == false)
	{

		//LOG(LBOOT, 1, "	Path: " + UsersDirectory);

		User * CurrentUser = new User();

		FFolderCollector FolderCollector = FFolderCollector(UsersDirectory);
		int Count = FolderCollector.Num();


		//LOG(LBOOT, 1, "	Found " + FString::FromInt(Count) + " potential user folders.");
		for (int i = 0; i < Count; i++)
		{
			if (TryUserFolder(FolderCollector.FolderPath(i), CurrentUser))
			{
				//LOG(LBOOT, 1, "		User is Valid: " + CurrentUser->ID);
				AddUser(CurrentUser);
			}

		}

		CheckIniSettings();

		bUsersScanned = true;
		//LOG(LBOOT, 1, "- GetAllUsers Complete");
		return;
	}

	//LOG(LBOOT, 1, "- GetAllUsers: Directory already scanned.");
}


void UserManager::CheckIniSettings()
{
	//FString LastUserID = Config->GetString(ConfigManager::IniTypes::Global, OINI_LAST_USER);
	FString LastUserID = " THIS IS A MISTAKE";

	if (LastUserID != INI_NULLSTRING)
	{
		//LOG(LBOOT, 1, "	Searching for Last Session User: " + LastUserID);
		User * PotentialLastSessionUser;
		if (TryGetUserByID(LastUserID, PotentialLastSessionUser))
		{
			//LOG(LBOOT, 1, "		Last session user found!");
			LastSessionUser = PotentialLastSessionUser;
		}
		else {
			//LOG(LBOOT, 1, "		Last session user not found.");
		}
	}
}
bool UserManager::TryUserFolder(FString InPath, User * &InUser)
{
	bool UserApproved = false;
	FString Path = InPath + "/" + USER_STANDARD_FILEPREFIX + EXT_USER;

	///LOG(LBOOT, 1, "	Checking: " + Path);

	if (FPaths::FileExists(Path))
	{

		//LOG(LBOOT, 1, "	File Exists");
		FFileReader FileReader = FFileReader(Path);
		FileReader.ToJson();

		if (FileReader.bFileSuccess && FileReader.bJsonSuccess)
		{
			//LOG(LBOOT, 1, "		Folder is Valid.");
			bool bFailed = InUser->DeJson(FileReader.Json());

			if (InUser->IsViable())
			{
				UserApproved = true;
			}
		}
	}
	return UserApproved;
}

void UserManager::AddUser(User * NewUser)
{
	UserCount++;
	Users.push_back(NewUser);
	NewUser->SN = Inc->Next();
}

bool UserManager::bLastSessionUserFound()
{
	if (LastSessionUser!=NULL)
	{
		return true;
	}
	return false;
}

bool UserManager::bSingleUserFound()
{
	if (UserCount == 1)
	{
		return true;
	}
	return false;
}


bool UserManager::bActiveUserFound()
{
	if (ActiveUser!=NULL)
	{
		return true;
	}
	return false;
}

bool UserManager::TryGetUserByID(FString ID, User * &InUser)
{
	for (int i = 0; i < UserCount; i++)
	{
		if (Users[i]->ID == ID)
		{
			InUser = Users[i];
			return true;
		}
	}
	return false;
}


bool UserManager::TryGetUserBySN(int SN, User * &InUser)
{

	for (int i = 0; i < UserCount; i++)
	{
		if (Users[i]->SN == SN)
		{
			InUser = Users[i];
			return true;
		}
	}
	return false;
}