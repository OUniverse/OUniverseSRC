//Copyright 2015-2019, All Rights Reserved.

/**
IO (InterfaceObject) 
Special on screen alert for critical errors.
 */

#pragma once

#include "CoreMinimal.h"
#include "Ui/Io.h"

class UiManager;
class UCohtmlHUD;


class OUNIVERSE_API ErrorIO : public Io
{
	friend UiManager;

private:
	
	ErrorIO(UCohtmlHUD* InUi);
};