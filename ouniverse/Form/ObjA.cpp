//Copyright 2015-2019, All Rights Reserved.

#include "Form/ObjA.h"
#include "System/Cosmos.h"

#include "GameFramework/Actor.h"


UObjA::UObjA() {}

UObjA* UObjA::Create(FormF* InForm)
{
	UObjA* Neu = NewObject<UObjA>();
	Neu->InitBase(InForm);
	return Neu;
}

AActor* UObjA::Spawn()
{
	AActor* Act = NewObject<AActor>();

	UCosmos* Cosmos = UCosmos::Get();
	//TSoftClassPtr<AObject3D> CharacterClass = TSoftClassPtr<ACharacter3D>(FSoftClassPath(AObject3D::Class));
	//AActor* NewAA = Cosmos->Scope()->SpawnActor<AObject3D>(CharacterClass.LoadSynchronous(), FVector(0.0f,0.0f,0.0f), FRotator(0.0f, 0.0f, 0.0f));

	Cosmos->RegisterSpawn(Act);
	return Act;
}
