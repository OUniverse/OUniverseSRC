//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/Protocol.h"
#include "System/Input.h"


class UUi;
class UMajor;
class MaestroC;

class CnsShelfP;
class CnsTrayP;

class FluxSwitchOpC;

class OUNIVERSE_API ConsoleNewPro : public ProtocolC, public InputStackC
{
	friend MaestroC;

public: 

	void OpenMenu();

	void GoUser();

	void Toggle();

private:

	bool bToggled;

	static ConsoleNewPro* Create(int InID, UMajor* InMajor);

	ConsoleNewPro(int InID, UMajor* InMajor);

	UMajor* Major_;
	MaestroC* Maestro_;
	UUi* Ui_;

	CnsShelfP* Shelf_;
	CnsTrayP* Tray_;
	
	static enum Pro {
		PTray,
		PShelf,
		PRO_MAX,
	};

};