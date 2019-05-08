//Copyright 2015-2019, All Rights Reserved.

/**
IO (InterfaceObject) 
Allows the player to manage and activate their Atlas Mods. 

 */

#pragma once

#include "CoreMinimal.h"
#include "Ui/Io.h"

class UiManager;
class UCohtmlHUD;


class OUNIVERSE_API DataIO : public Io
{

	friend UiManager;

private:
	
	DataIO(UCohtmlHUD* InUi);

};