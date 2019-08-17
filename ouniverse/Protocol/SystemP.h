//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/ProtocolP.h"
#include <string>
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
	
	void GoPhasePreUser();
	void GoPhasePreData();
	void GoPhasePreLoad();

	void SetupPhasePreUser();
	void SetupPhasePreData();
	void SetupPhasePreLoad();


	void GoUser();
	
	void SetupUser();

	void UserOnward();



	void TitleGo();

	void TitleSetup();

	void TitleForward(int InUID);

	void TitleOnward();



	void SessionGo();

	void SessionSetup();

	void SessionSelected();


	void PageClosed();

	void PhaseClosed();

	void UserSelected(int InUID);

	enum Pages {
		User,
		Title,
		Session,
		PAGES_MAX,
	};

	enum Phases {
		PreUser,
		PreData,
		PreLoad,
		PHASES_MAX,
	};

	SystemP::Pages ActivePage;

	SystemP::Phases ActivePhase;

};