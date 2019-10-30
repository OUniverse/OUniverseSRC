//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Interface/Map.h"
#include "System/DuetUID.h"
#include "Protocol/Protocol.h"
#include "WorldPro.generated.h"

class UCosmos;
class AControlUE;
class UParty;
class UCharacterA;
class PopulaceC;

UCLASS()
class OUNIVERSE_API UWorldPro : public UProtocol
{
	GENERATED_BODY()

	friend UMaestro;

public:

	UWorldPro();

	void Start();

	void Possess(UCharacterA* InEx);

private:

	static UWorldPro* Create(AControlUE* InControl, UCosmos* InCosmos);
	void Init(AControlUE* InControl, UCosmos* InCosmos);
	
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
