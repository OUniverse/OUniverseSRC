//Copyright 2015-2019, All Rights Reserved.

#include "Form/CharacterA.h"
#include "Data/CharacterD.h"
#include "Form/Character3D.h"

#include "System/Scope.h"

#include "Component/CharacterInput.h"

#include "System/Cosmos.h"
#include "System/Class.h"

#include "Min/DebugM.h"


UCharacterA* UCharacterA::Create(CharacterD* InForm)
{
	UCharacterA* Neu = NewObject<UCharacterA>(ScopeC::World(),ClassC::F_CharacterA());
	Neu->InitBase(InForm);
	return Neu;
}

AActor* UCharacterA::Spawn()
{
	UCosmos* Cosmos = UCosmos::Get();
	//TSoftClassPtr<ACharacter3D> CharacterClass = TSoftClassPtr<ACharacter3D>(FSoftClassPath(ACharacter3D::Class));
	Character3D_ = ScopeC::World()->SpawnActor<ACharacter3D>(ClassC::F_Character3D(), FVector(0.0f, 0.0f, 100.0f), FRotator(0.0f, 0.0f, 0.0f));
	Cosmos->RegisterSpawn(Character3D_);
	return  Character3D_;
}

ACharacter3D* UCharacterA::Character3D()
{
	return Character3D_;
}

void UCharacterA::Possess()
{
	Input_ = UCharacterInput::Create(this);
}

void UCharacterA::MoveX(float AxisValue)
{
	Character3D_->MoveX(AxisValue);
}

void UCharacterA::MoveY(float AxisValue)
{
	Character3D_->MoveY(AxisValue);
}

void UCharacterA::LookX(float AxisValue)
{
	Character3D_->LookX(AxisValue);
}

void UCharacterA::TurnY(float AxisValue)
{
	Character3D_->TurnY(AxisValue);
}


void UCharacterA::Zoom(float AxisValue)
{
	Character3D_->Zoom(AxisValue);
}