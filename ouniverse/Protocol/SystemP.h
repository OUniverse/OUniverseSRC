//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/ProtocolP.h"

class UserLibC;
class KernelC;

class OUNIVERSE_API SystemP : public ProtocolP
{
	friend ProtocolManager;

public:

	void EndTitle();

private:

	bool First_;

	SystemP(KernelC* InKernel, UserLibC* InUserLib);

	virtual void Activate() override;

	KernelC* Kernel_;
	UserLibC* UserLib_;
	
	void GoUser();

	void GoTitle();

	void GoSession();

	void ForwardUser();

	void ForwardTitle();

};