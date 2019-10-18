//Copyright 2015-2019, All Rights Reserved.

#include "System/CharacterUE.h"

#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"


#include "Components/SkeletalMeshComponent.h"

ACharacterUE::ACharacterUE()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	//ConstructObject<USphereComponent>(USphereComponent::StaticClass, this, TEXT("MySphereComponent"));

	Skeleton_ = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("My Skeletal Mesh Component"));
	Skeleton_->SetupAttachment(RootComponent); 
	//Skeleton_->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f - (GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight())));
	Skeleton_->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

	TSoftObjectPtr<USkeletalMesh> Mesh_SP = TSoftObjectPtr<USkeletalMesh>(FSoftObjectPath("/Game/study/sketchup/humanfemale_torso.humanfemale_torso"));
	USkeletalMesh* TestMesh = Mesh_SP.LoadSynchronous();
	Skeleton_->SetSkeletalMesh(TestMesh);

	OrbitSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	OrbitSpringArm->SetupAttachment(RootComponent);
	OrbitSpringArm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 50.0f), FRotator(-10.0f, 0.0f, 0.0f));
	OrbitSpringArm->TargetArmLength = 400.f;
	OrbitSpringArm->bEnableCameraLag = true;
	OrbitSpringArm->CameraLagSpeed = 3.0f;

	OrbitCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("GameCamera"));
	OrbitCamera->SetupAttachment(OrbitSpringArm, USpringArmComponent::SocketName);
}