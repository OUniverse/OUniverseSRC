//Copyright 2015-2019, All Rights Reserved.

#include "Form/Character3D.h"

#include "System/Input.h"
#include "Io/CharacterIo.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h" 
#include "Components/SkeletalMeshComponent.h"

#include "Component/DollyControl.h"

const char* ACharacter3D::Class = "/Game/class/3d/Character3D.Character3D_C";

ACharacter3D::ACharacter3D()
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

	OrbitBoom_ = CreateDefaultSubobject<USpringArmComponent>(TEXT("OrbitBoom"));
	OrbitBoom_->SetupAttachment(RootComponent);
	OrbitBoom_->TargetArmLength = 750.f;
	OrbitBoom_->SocketOffset = FVector(0.f, 0.f, 0.f);
	OrbitBoom_->RelativeLocation = FVector(0.f, 0.f, 170.f);
	OrbitBoom_->RelativeRotation = FRotator(-10.f, 0.f, 0.f);
	OrbitBoom_->TargetArmLength = 400.f;
	OrbitBoom_->bEnableCameraLag = true;
	OrbitBoom_->CameraLagSpeed = 3.0f;

	OrbitCam_ = CreateDefaultSubobject<UCameraComponent>(TEXT("OrbitCam"));
	OrbitCam_->SetupAttachment(OrbitBoom_, USpringArmComponent::SocketName);


	//DollyControl_ = CreateDefaultSubobject<UDollyControl>(TEXT("ControlDolly"));
	//DollyControl_->AttachToComponent(RootComponent, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
	//DollyControl_->SetRelativeLocation(FVector(0));
	//DollyControl_->SetRelativeRotation(FRotator(0));

	//OrbitSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	//OrbitSpringArm->SetupAttachment(RootComponent);
	//OrbitSpringArm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 50.0f), FRotator(-10.0f, 0.0f, 0.0f));
	//OrbitSpringArm->TargetArmLength = 400.f;
	//OrbitSpringArm->bEnableCameraLag = true;
	//OrbitSpringArm->CameraLagSpeed = 3.0f;

	//CamControl_ = CreateDefaultSubobject<UCameraComponent>(TEXT("GameCamera"));
	//CamControl_->SetupAttachment(OrbitSpringArm, USpringArmComponent::SocketName);
}

UInputSchemaStack* ACharacter3D::Possess()
{
	Input_ = UInputSchemaStack::Create();
	return Input_;
}

UCameraComponent* ACharacter3D::GetControlCam()
{
	return OrbitCam_;
}