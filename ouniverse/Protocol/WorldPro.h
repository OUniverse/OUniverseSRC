//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Interface/Map.h"
#include "System/DuetUID.h"
#include "System/Input.h"

#include "Protocol/Protocol.h"

class UCosmos;
class AControlUE;
class UParty;
class UCharacterA;
class PopulaceC;


class OUNIVERSE_API WorldProC : public ProtocolC, public InputStackC
{


	friend MaestroC;

public:


	void Start();

	void Possess(UCharacterA* InEx);

private:

	static WorldProC* Create(int InID, MaestroC* InMaestro, AControlUE* InControl, UCosmos* InCosmos);

	WorldProC(int InID, MaestroC* InMaestro, AControlUE* InControl, UCosmos* InCosmos);
	
	PopulaceC* Populace_;

	UPROPERTY()
	UCosmos* Cosmos_;
	UPROPERTY()
	AControlUE* Control_;

	UPROPERTY()
	UParty* Party_;

	UPROPERTY()
	UCharacterA* PossessedCharacter_;
	
	UPROPERTY()
	UInputSchemaCharacter* CharacterInputBeacon_;
};
