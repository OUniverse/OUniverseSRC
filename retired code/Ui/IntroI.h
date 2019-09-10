//Copyright 2015-2019, All Rights Reserved.

/**
IO (InterfaceObject)
Initial Trailers and movies.
 */

#pragma once

#include "CoreMinimal.h"
#include "Ui/Io.h"

class UiManager;
class GlassC;


class OUNIVERSE_API IntroIO : public Io
{
	friend UiManager;

private:
	
	IntroIO(GlassC* InGlass);
	bool bOpen;
};