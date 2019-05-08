//Copyright 2015-2019, All Rights Reserved.

/**
The MuffinManager is a Singleton extension to MAJOR and manages Muffins and baking them and some other stuff.
 */

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Encryption.generated.h"


USTRUCT()
struct FEncryption
{
	GENERATED_BODY()

	FString Result;

	FEncryption();
	FEncryption(FString StringData, bool bEncryptNotDecyrpt);

	FString Encrypt(FString InputString);
	FString Decrypt(FString InputString);
	FString Out();
};