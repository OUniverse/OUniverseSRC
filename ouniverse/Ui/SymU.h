//Copyright 2015-2019, All Rights Reserved.

/**

## UiManager

> **Singleton Service: Created once only by the boot process.**

The UiManager is a service singleton which manages all user interface elements (UI).

#### IO
IO is used here as an abbreviation for Interface Object and is any menu component
* A menu IO can be made up of many smaller IOs.

#### Tasks:
* Coordinates all of the UI's IO elements.
* Allows the IO elements to register with other systems (For example the console registering for the console CommandC).
* Activates each IO so that they bind themselves to the actual UI.
* Provides functions for other parts of the program to trigger UI events like popup notifications or data ribbons.

**Creator:** UBoot
**Holder:** Major

 */

#pragma once

class UserLibC;
class UserDaisC;
class LoadoutLibC;
class LoadoutDaisC;
class OniManagerC;

#include <string>

class OUNIVERSE_API SymU
{

public:

	SymU(UserLibC* InUserLib, UserDaisC* InUserD, LoadoutLibC* InLoadoutLib, LoadoutDaisC* InLoadoutD, OniManagerC* InOniManager);

	void Open();
	void Close();

private:

	UserLibC* UserL_;
	UserDaisC* UserDais_;
	LoadoutLibC* LoadoutL_;
	LoadoutDaisC* LoadoutDais_;
	OniManagerC* Oni_;

	bool Open_;

	void User_REQ(int uid);

	void PreUsers_REQ();
	
	void UserConfig_REQ(int uid);

	void User_SAVE(std::string Dat);

	void User_NEW();

	void UserSelected_ACT(int uid);
	
	void Loadouts_REQ();

	void LoadoutSelected_ACT(int uid);

};