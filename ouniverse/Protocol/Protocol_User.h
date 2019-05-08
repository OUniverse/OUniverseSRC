//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the UserSelection menus.
 */

#pragma once

#include "CoreMinimal.h"
#include "Protocol/Protocol.h"
#include "Protocol_User.generated.h"

class UU_User;

UCLASS()
class OUNIVERSE_API UProtocol_User: public UProtocol
{
	GENERATED_BODY()

public:

	virtual void Activate() override;
	
	
	UFUNCTION()
	void UserSelected();
};