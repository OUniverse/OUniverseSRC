//Copyright 2015-2019, All Rights Reserved.

/**
IO (InterfaceObject)
Toaster notification, meant to convey game context related messages.
 */

#include "CoreMinimal.h"
#include "Ui/Io.h"

class UiManager;
class GlassC;


class OUNIVERSE_API ToastIO : public Io
{
	friend UiManager;

private:

	ToastIO(GlassC* InGlass);

};