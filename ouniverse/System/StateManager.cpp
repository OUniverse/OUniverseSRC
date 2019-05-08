//Copyright 2015-2019, All Rights Reserved.

#include "System/StateManager.h"
#include "State/State.h"
#include "System/Major.h"



StateManager* StateManager::Create()
{
	return new StateManager();
}


StateManager::StateManager()
{
	Major* M = Major::Get();

	StateVector.assign(Types::MAX, NULL);
}

State* StateManager::GetState(Types Type)
{
	return StateVector[Type];
}

State* StateManager::Activate(Types Type)
{
	State* ActivatedState = GetState(Type);
	ActivatedState->Activate();
	return ActivatedState;
}