//Copyright 2015-2019, All Rights Reserved.

/**
The GraphicsManager is a Singleton extension to MAJOR and manages global graphics settings.
 */

#pragma once

class UBoot;

class OUNIVERSE_API CosmosC
{
	friend UBoot;

private:

	static CosmosC* Create();

public:

	static CosmosC* Get();
	
	CosmosC();

};
