//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/Protocol.h"
#include "System/Input.h"


class ConsoleNewPro;
class UUi;

class UCnsTray;
class FocusUiRackC;


class OUNIVERSE_API CnsTrayP : public ProtocolC, public InputC
{

public: 

	CnsTrayP(int InID, UUi* InUi, ConsoleNewPro* InPro);


	UUi* Ui_;

	UCnsTray* View_;

	ConsoleNewPro* Pro_;

	void OpenConsole();
	void CloseConsole();

};