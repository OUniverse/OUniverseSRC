//Copyright 2015-2019, All Rights Reserved.

/**
UserManager is a Singleton extension to MAJOR (GameInstance) and manages all User data.
A User represents the person that is playing.

The UserManager class has the following abilities:
-Can return user from an ID or a serial number (In case ID is changed)
-Manages the shifting of Users or assigning a new User.
-Scans the user directory and creats a User class object for each valid user found.
 */

#pragma once

#include "CoreMinimal.h"
#include <vector> 


struct Incrementer;
class User;
class ConfigManager;

class OUNIVERSE_API UserManager
{

private:

	UserManager(ConfigManager* ConfigM, FString* UserDirectory);

public:

	static UserManager* Create(ConfigManager* ConfigM, FString* UserDirectory);

	bool bUsersScanned;
	int UserCount;

	User* LastSessionUser;

	std::vector <User*> Users;

	void GetAllUsers();

	void SetActiveUser(User* NewActiveUser);
	void SetActiveUserFromSN(int SN);

	User* GetActiveUser();

	bool bLastSessionUserFound();
	bool bActiveUserFound();
	bool bSingleUserFound();

private:

	
	ConfigManager* Config;

	FString* UsersDir;

	User* ActiveUser;


	bool TryUserFolder(FString InPath, User*& InUser);
	void CheckIniSettings();

	void AddUser(User* NewUser);

	struct Incrementer* Inc;

	bool TryGetUserByID(FString ID, User*& InUser);
	bool TryGetUserBySN(int SN, User*& InUser);
};