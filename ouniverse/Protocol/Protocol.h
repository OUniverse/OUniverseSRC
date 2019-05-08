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

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Protocol.generated.h"

class UMajor;

UCLASS()
class OUNIVERSE_API UProtocol : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY()
	UMajor* Major;

	void Init(UMajor* InMajor);
	virtual void Activate();

	virtual void Conclude();
};