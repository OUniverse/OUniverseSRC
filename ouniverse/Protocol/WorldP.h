//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/ProtocolP.h"


class UCosmos;
class AControlUE;
class PartyC;
class ActorA;

class OUNIVERSE_API WorldP : public ProtocolP
{
	friend MaestroC;

public:

	void Start();

	virtual InputReplyS Forward(InputActionS InIA) override;

	void Possess(ActorA* InActor);

private:

	WorldP(AControlUE* InControl, UCosmos* InCosmos);

	UCosmos* Cosmos_;
	AControlUE* Control_;
	PartyC* Party_;
	
};
