//Copyright 2015-2019, All Rights Reserved.

/**
The GraphicsManager is a Singleton extension to MAJOR and manages global graphics settings.
 */

#pragma once

#include "Actual/ObjectA.h"


class ActorF;
class ACharacterUE;

class OUNIVERSE_API ActorA : public ObjectA
{

public:

	ActorA();

	void Spawn();

private:

	ACharacterUE* CharacterUE_;
};
