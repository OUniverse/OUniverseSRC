//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/Protocol.h"
#include "WriterPro.generated.h"

UCLASS()
class OUNIVERSE_API UWriterPro : public UProtocol
{
	GENERATED_BODY()

	friend UMaestro;

public:

	static UWriterPro* Create();

	void Init();

private:

	UWriterPro();

};