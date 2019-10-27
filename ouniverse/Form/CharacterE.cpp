//Copyright 2015-2019, All Rights Reserved.

#include "Form/CharacterE.h"
#include "Form/CharacterF.h"
#include "Form/Character3D.h"

#include "System/Cosmos.h"

#include "Min/DebugM.h"

UCharacterE* UCharacterE::Create(CharacterF* InForm)
{
	UCharacterE* Obj = NewObject<UCharacterE>();
	Obj->Init(InForm);
	return Obj;
}

void UCharacterE::Init(CharacterF* InForm)
{
	Form_ = InForm;
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

CharacterF* UCharacterE::Form()
{
	return Form_;
}

void UCharacterE::Test()
{
	DBUG(Form_->Name_.ToChar());
}

void UCharacterE::Possess()
{

}