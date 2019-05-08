//Copyright 2015-2019, All Rights Reserved.

/**
IO (InterfaceObject)
Databloom Creation Engine
 */

#pragma once

#include "CoreMinimal.h"
#include "Ui/Io.h"


class OUNIVERSE_API CreationIO : public Io
{

	friend UiManager;

private:

	CreationIO(UCohtmlHUD* InUi);
	
	void Activate() override;
};