//Copyright 2015-2019, All Rights Reserved.

/**
IO (InterfaceObject)
Handles any visual element that freezes gameplay and requires at least one click to close.
This includes PopUp notifications that require confirmation or tutorial windows.
 */

#include "CoreMinimal.h"
#include "Ui/Io.h"
#include "Interface/Array.h"

class UiManager;
class GlassC;
struct PopupSchema;

class OUNIVERSE_API PopupIO : public Io
{

	friend UiManager;

public:

	enum Types : uint8
	{
		MainMenuInfo,
	};

private:

	PopupIO(GlassC* InGlass);

	ArrayC<PopupSchema*> Popups;

};

struct OUNIVERSE_API PopupSchema
{

public:

	PopupIO::Types Type;
};