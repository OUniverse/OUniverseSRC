//Copyright 2015-2019, All Rights Reserved.

#include "Form/ObjectE.h"
#include "System/Cosmos.h"

#include "GameFramework/Actor.h"


UObjectE::UObjectE() {}

UObjectE* UObjectE::Create()
{
	UObjectE* Obj = NewObject<UObjectE>();
	Obj->Init();
	return Obj;
}

void UObjectE::Init()
{

}

AActor* UObjectE::Spawn()
{
	AActor* Act = NewObject<AActor>();

	UCosmos* Cosmos = UCosmos::Get();
	//TSoftClassPtr<AObject3D> CharacterClass = TSoftClassPtr<ACharacter3D>(FSoftClassPath(AObject3D::Class));
	//AActor* NewAA = Cosmos->Scope()->SpawnActor<AObject3D>(CharacterClass.LoadSynchronous(), FVector(0.0f,0.0f,0.0f), FRotator(0.0f, 0.0f, 0.0f));

	Cosmos->RegisterSpawn(Act);
	return Act;
}


UObjectE* UObjectE::Type3D()
{
	return Type3D_;
}

