//Copyright 2015-2019, All Rights Reserved.

/**
ProtocolManager is a Singleton extension to MAJOR (GameInstance) and handles different modes the game can be in.
For example the login or title screen requires different logic compared to playing the game.
Protocols serves as the base logic and drive for different modes the game can be in.

- Handles the load/unload of Protocols.
- Synchronizes a change in Protocols by ensuring an old one is unloaded before loading in a new one.
 */

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ProtocolManager.generated.h"

class UMajor;
class UProtocol;
class UUser;

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EProtocol : uint8
{
	Pilot,
	User,
	Creation,
	World,
	CharGen,
	Title,
};

UCLASS()
class OUNIVERSE_API UProtocolManager : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY()
	UMajor* Major;

	TMap<EProtocol,UProtocol*> ProtocolMap;

	UProtocolManager();
	FORCEINLINE void Init(UMajor* InMajor);
	UProtocol* GetProtocol(EProtocol ProtocolType);
	UProtocol* Activate(EProtocol ProtocolType);
};