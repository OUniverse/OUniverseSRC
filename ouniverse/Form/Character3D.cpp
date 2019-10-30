//Copyright 2015-2019, All Rights Reserved.

#include "Form/Character3D.h"
#include "System/Cosmos.h"

#include "System/Input.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h" 
#include "Components/SkeletalMeshComponent.h"

#include "Component/DollyControl.h"
#include "Math/UnrealMathUtility.h"

#include "Min/DebugM.h"


ACharacter3D::ACharacter3D()
{


	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);


	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;


	//ConstructObject<USphereComponent>(USphereComponent::StaticClass, this, TEXT("MySphereComponent"));

	Skeleton_ = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("My Skeletal Mesh Component"));
	Skeleton_->SetupAttachment(RootComponent);
	//Skeleton_->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f - (GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight())));
	Skeleton_->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

	TSoftObjectPtr<USkeletalMesh> Mesh_SP = TSoftObjectPtr<USkeletalMesh>(FSoftObjectPath("/Game/study/sketchup/humanfemale_torso.humanfemale_torso"));
	USkeletalMesh* TestMesh = Mesh_SP.LoadSynchronous();
	Skeleton_->SetSkeletalMesh(TestMesh);
	Skeleton_->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f - (GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight())));

	OrbitBoom_ = CreateDefaultSubobject<USpringArmComponent>(TEXT("OrbitBoom"));
	OrbitBoom_->SetupAttachment(RootComponent);
	CamZoomGoal = 750.f;
	OrbitBoom_->TargetArmLength = CamZoomGoal;

	OrbitBoom_->SocketOffset = FVector(0.f, 0.f, 0.f);
	OrbitBoom_->RelativeLocation = FVector(0.f, 0.f, 70.f);
	OrbitBoom_->RelativeRotation = FRotator(-10.f, 0.f, 0.f);
	OrbitBoom_->bEnableCameraLag = true;
	OrbitBoom_->CameraLagSpeed = 3.0f;
	OrbitBoom_->bUsePawnControlRotation = true;

	OrbitCam_ = CreateDefaultSubobject<UCameraComponent>(TEXT("OrbitCam"));
	OrbitCam_->SetupAttachment(OrbitBoom_, USpringArmComponent::SocketName);
	OrbitCam_->bUsePawnControlRotation = false;

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

void ACharacter3D::BeginPlay()
{
	Super::BeginPlay();
}

void ACharacter3D::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}


UCameraComponent* ACharacter3D::GetControlCam()
{
	return OrbitCam_;
}

void ACharacter3D::MoveX(float Value)
{
	if (Controller != NULL)
	{

		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ACharacter3D::MoveY(float Value)
{
	if (Controller != NULL)
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

void ACharacter3D::TurnY(float Value)
{
	AddControllerYawInput(Value);
}

void ACharacter3D::LookX(float Value)
{
	AddControllerPitchInput(Value * BaseLookUpRate * GetWorld()->GetDeltaSeconds() * -1);
}


void ACharacter3D::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); // Call parent class tick function  
}

void ACharacter3D::Zoom(float AxisValue)
{
	float Result;
	Result = AxisValue * -50;
	Result += CamZoomGoal;

	CamZoomGoal = FMath::Clamp(Result, 200.0f, 1000.0f);

	OrbitBoom_->TargetArmLength = FMath::FInterpTo(OrbitBoom_->TargetArmLength, CamZoomGoal, GetWorld()->GetDeltaSeconds(), 10.0f);

}