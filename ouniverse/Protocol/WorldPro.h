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
class UCharacterE;


UCLASS()
class OUNIVERSE_API UWorldPro : public UProtocol
{
	GENERATED_BODY()

	friend UMaestro;

public:

	UWorldPro();

	void Start();

	virtual InputReplyS Forward(InputActionS InIA) override;

	void Possess(UCharacterE* InEx);

private:

	static UWorldPro* Create(AControlUE* InControl, UCosmos* InCosmos);
	void Init(AControlUE* InControl, UCosmos* InCosmos);
	
	UPROPERTY()
	UCosmos* Cosmos_;
	UPROPERTY()
	AControlUE* Control_;

	UParty* Party_;

};
