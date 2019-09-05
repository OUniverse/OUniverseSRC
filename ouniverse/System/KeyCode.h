//Copyright 2015-2019, All Rights Reserved.

/**

## Commands
Every action triggered by input in OUniverse has a Command associated with. (For example "Jump" "Accept" "Interact" are all Commands.).
Commands forward receipt of the input action via Event Delegates which can be registered for.
These Event Delegates broadcast all clicks and presses to all registered methods.

#### Tasks
* Allows other areas of the program to easily register for Command Events.
* Commands are stored on a Map keyed by KeyScanCodes so they can be easily remapped.

**Creator:** InputManager
**Holder:** InputManager
**Related:** CharKeyC

 */

#pragma once


class KeyCodeC
{

public:

	KeyCodeC();

	KeyCodeC(int InKeyCode);

	KeyCodeC(int InKeyCode, bool ShiftDN, bool CtrDN, bool AltDN);

	int Out();

	bool operator<(const KeyCodeC& l) const;

private:

	int KeyCode_;

};