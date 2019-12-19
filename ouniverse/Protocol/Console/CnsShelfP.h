//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/Protocol.h"
#include "System/Input.h"


class ConsoleNewPro;
class UUi;

class UCnsShelf;

class CnsLogP;
class CnsOutputP;

class FocusDockC;
class FocusUiRackC;

class OUNIVERSE_API CnsShelfP : public ProtocolC, public InputC
{

public:

	CnsShelfP(int InID, UUi* InUi, ConsoleNewPro* InPro);

	UUi* Ui_;

	UCnsShelf* View_;

	ConsoleNewPro* Pro_;

	CnsLogP* CnsLog_;
	CnsOutputP* CnsOutput_;

	static enum Focus {
		FDock,
		FRack,
		FLog,
		FOutput,
		FOCUS_MAX,
	};

	static enum Dock {
		DShelf,
	};
	
	static enum Pro {
		PLog,
		POutput,
	};

	FocusDockC* ODock_;
	FocusUiRackC* ORack_;

	void OpenConsole();
	void CloseConsole();

};