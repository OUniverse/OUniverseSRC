//Copyright 2015-2019, All Rights Reserved.

/**

## Session

> **Singleton Service: Created once only by the boot process.**

A service singleton which manages the session once a user is selected.

**Creator:** UBoot
**Holder:** Major

 */

#pragma once

class UserC;
class SessionC;
class SessionLib;

class OUNIVERSE_API KernelC
{

private:


	UserC* User_;
	bool HasUser_;
	
	SessionC* Session_;
	bool HasSession_;
	SessionLib* SessionLib_;

public:

	KernelC();

	static KernelC* Create();

	static KernelC* Get();

	UserC*		GetUser();
	SessionC*	GetSession();	

	void SetUser(UserC* InNewUser);

	void SetSession(SessionC* InNewSession);

};