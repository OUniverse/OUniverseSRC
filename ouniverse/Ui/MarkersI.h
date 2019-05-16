//Copyright 2015-2019, All Rights Reserved.

/**
IO (InterfaceObject)
HUD on screen markers at locations.
 */

#include "CoreMinimal.h"
#include "Ui/Io.h"

class UiManager;
class GlassC;

class OUNIVERSE_API MarkersIO : public Io
{

	friend UiManager;

private:

	MarkersIO(GlassC* InGlass);

};