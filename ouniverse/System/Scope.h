//Copyright 2015-2019, All Rights Reserved.


#pragma once

class UWorld;
class UObject;

class BootC;

class ScopeC
{
	friend BootC;

private:

	ScopeC(UObject* InWorldContextObject, UWorld* InWorld);

public:

	static UWorld* World();
	static UObject* WorldContext();
};