//Copyright 2015-2019, All Rights Reserved.

/**
IO (InterfaceObject)
Banner effect with text that gives player notifications.
Meant to show messages outside the lore of the game.
Ex: Battery power in a controller is low etc.
 */

#include "CoreMinimal.h"
#include "Ui/Io.h"

class UiManager;
class GlassC;


class OUNIVERSE_API NoticeIO : public Io
{
	friend UiManager;

private:

	NoticeIO(GlassC* InGlass);

};