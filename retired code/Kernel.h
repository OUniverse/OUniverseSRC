//Copyright 2015-2019, All Rights Reserved.

/**

## Session

> **Singleton Service: Created once only by the boot process.**

A service singleton which manages the session once a user is selected.

**Creator:** UBoot
**Holder:** Major

 */

#pragma once

class DataC;

class UserC;
class LoadoutC;
class SessionC;
class LoadoutLibC;
class SessionLibC;
class CosmosC;

class OUNIVERSE_API KernelC
{

private:


	UserC* User_;
	bool HasUser_;
	
	SessionC* Session_;
	bool HasSession_;
	SessionLibC* SessionLib_;

	LoadoutC* Loadout_;
	bool HasLoadout_;
	LoadoutLibC* LoadoutLib_;
	
	CosmosC* Cosmos_;

public:

	KernelC() {};
	KernelC(DataC* InData);

	static KernelC* Create(DataC* InData);

	static KernelC* Get();

	UserC*		GetUser();
	LoadoutC*	GetLoadout();	
	SessionC*	GetSession();
	CosmosC*	GetCosmos();

	DataC* Data_;

	void SetUser(UserC* InNewUser);

	bool SetLoadout(int InLoadoutUID);
	bool SetLoadout(LoadoutC* InLoadout);

	bool SetSession(int InSessionUID);
	bool SetSession(SessionC* InSession);

	SessionLibC* SessionLib();
};