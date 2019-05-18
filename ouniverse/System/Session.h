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
class KernelC;

class OUNIVERSE_API SessionC
{

private:

	KernelC* Kernel_;

	bool HasKernel_;
	
public:

	static SessionC* Get();

	static SessionC* Create();

	SessionC();

	void NewKernel(UserC* InNewUser);

};