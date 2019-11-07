//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/Ubc.h"
#include "Ui_Relay.generated.h"


UCLASS(Blueprintable)
class OUNIVERSE_API UUi_Relay : public UUbc
{

	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure)
	UUbc* Relay();

	void SetRelay(UUbc* InRelay);

	UUbc* Relay_;

	UFUNCTION(BlueprintImplementableEvent)
	void RelaySet();

	int RelayUID_;

	void SetRelayUID(int InRelayUID);

	UFUNCTION(BlueprintPure)
	int RelayUID();

};