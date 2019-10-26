//Copyright 2015-2019, All Rights Reserved.

#include "Form/CharacterE.h"
#include "Form/CharacterD.h"
#include "Form/Character3D.h"

#include "System/Cosmos.h"


UCharacterE* UCharacterE::Create(CharacterD* InDat)
{
	UCharacterE* Obj = NewObject<UCharacterE>();
	Obj->Init(InDat);
	return Obj;
}

void UCharacterE::Init(CharacterD* InDat)
{
	Dat_ = InDat;
}

AActor* UCharacterE::Spawn()
{
	UCosmos* Cosmos = UCosmos::Get();
	TSoftClassPtr<ACharacter3D> CharacterClass = TSoftClassPtr<ACharacter3D>(FSoftClassPath(ACharacter3D::Class));
	Character3D_ = Cosmos->Scope()->SpawnActor<ACharacter3D>(CharacterClass.LoadSynchronous(), FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	Cosmos->RegisterSpawn(Character3D_);
	return  Character3D_;
}

ACharacter3D* UCharacterE::Character3D()
{
	return Character3D_;
}

CharacterD* UCharacterE::Dat()
{
	return Dat_;
}