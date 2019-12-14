//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/Protocol.h"
#include "System/Input.h"

class UConShelf;
class UConTray;
class UMajor;
class UUi;

class OUNIVERSE_API ConsolePro : public ProtocolC, public InputUiC
{
	friend MaestroC;

public: 

	void GoToWriter();
	
	void Toggle();

private:

	bool bToggled;

	static ConsolePro* Create(int InID, UMajor* InMajor);

	ConsolePro(int InID, UMajor* InMajor);

	UUi* Ui_;
	UMajor* Major_;
	UConTray* Tray_;
	UConShelf* Shelf_;

};