//Copyright 2015-2019, All Rights Reserved.

/**
The GraphicsManager is a Singleton extension to MAJOR and manages global graphics settings.
 */

#pragma once

#include "Form/ObjectA.h"


class ActorF;
class ACharacter3D;

class OUNIVERSE_API ActorA : public ObjectA
{

public:

	ActorA();

	void Spawn();

	void ControlPossess();

	void Mount(ACharacter3D* InCharacterUE);

	void Dismount();

	ACharacter3D* M3D();

private:

	ACharacter3D* M3D_;

};
