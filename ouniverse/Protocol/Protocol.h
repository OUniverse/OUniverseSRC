//Copyright 2015-2019, All Rights Reserved.

/**
Each Protocol is a modes the game can be in. Examples of a mode would be the Title Screen vs InGame.
Protocols contain special logic for handling tasks of different isolated modes the game can be in.

You can think of a Protocol as OUniverse's own GameMode type. Since OUniverse streams everything into one base level
it doesn't have an opportunity to switch out the GameMode and instead uses Protocols which it can dynamicaly switch.

Protocols are loaded via the ProtocolManager class attached to the MAJOR singleton.

This is the abstract Protocol class which all actual Protocols extend from.
 */

#pragma once

#include "System/Input.h"
#include "Protocol.generated.h"

class UMaestro;

UCLASS()
class OUNIVERSE_API UProtocol : public UInputSchema
{
	GENERATED_BODY()

	friend UMaestro;

protected:

	UProtocol();

	virtual ~UProtocol() {};

	virtual void Mount();
	virtual void Dismount();

private:

};