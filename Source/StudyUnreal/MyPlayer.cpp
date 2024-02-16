// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "Camera/PlayerCameraManager.h"
#include "MyAnimInstance.h"
#include "Arrow.h"
#include "Kismet/GameplayStatics.h"
#include "MyActorComponent.h"

AMyPlayer::AMyPlayer()
{
	PrimaryActorTick.bCanEverTick = false;

	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Character"));

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	SpringArm->SetupAttachment(GetCapsuleComponent());
	Camera->SetupAttachment(SpringArm);

	SpringArm->TargetArmLength = 400.f;
	SpringArm->SetRelativeRotation(FRotator(-35.f, 0.f, 0.f));
	SpringArm->SocketOffset = FVector(0.f, 120.f, 75.f);  // Ãß°¡
	SpringArm->bUsePawnControlRotation = true;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SkeletalMesh(TEXT("/Script/Engine.SkeletalMesh'/Game/ParagonSparrow/Characters/Heroes/Sparrow/Meshes/Sparrow.Sparrow'"));

	if (SkeletalMesh.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SkeletalMesh.Object);
		GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -90.f), FRotator(0.f, -90.f, 0.f));
	}

	static ConstructorHelpers::FClassFinder<UAnimInstance> AnimInstance(TEXT("/Script/Engine.AnimBlueprint'/Game/Animation/ABP_MyCharacter.ABP_MyCharacter_C'"));
	if (AnimInstance.Succeeded())
	{
		GetMesh()->SetAnimClass(AnimInstance.Class);
	}
	
}

void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AMyPlayer::KeyUpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AMyPlayer::KeyLeftRight);
	PlayerInputComponent->BindAxis(TEXT("LookLeftRight"), this, &AMyPlayer::MouseLookLeftRight);
	PlayerInputComponent->BindAxis(TEXT("LookUpDown"), this, &AMyPlayer::MouseLookUpDown);

	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &AMyPlayer::Jump);
	PlayerInputComponent->BindAction(TEXT("Fire"), EInputEvent::IE_Pressed, this, &AMyPlayer::Attack);
}

void AMyPlayer::KeyUpDown(float value)
{
	AddMovementInput(GetActorForwardVector(), value);
}

void AMyPlayer::KeyLeftRight(float value)
{
	AddMovementInput(GetActorRightVector(), value);
}

void AMyPlayer::MouseLookLeftRight(float value)
{
	AddControllerYawInput(value);
}

void AMyPlayer::MouseLookUpDown(float value)
{
	AddControllerPitchInput(value);
}

void AMyPlayer::Attack()
{
	Super::Attack();
}

void AMyPlayer::OnHit()
{
	Super::OnHit();

	float AttackRange = 10000.f;
	FHitResult HitResult;

	APlayerCameraManager* CamManager = UGameplayStatics::GetPlayerCameraManager(this, 0);

	FVector AimLocation = CamManager->GetCameraLocation();
	FVector TargetLocation = AimLocation + CamManager->GetActorForwardVector() * AttackRange;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);

	bool Result = GetWorld()->LineTraceSingleByChannel(
		OUT HitResult,
		AimLocation,
		TargetLocation,
		ECollisionChannel::ECC_GameTraceChannel3,
		Params
	);
	if (Result)
	{
		TargetLocation = HitResult.ImpactPoint;
		DrawDebugLine(GetWorld(), AimLocation, TargetLocation, FColor::Green, true);
	}
	else {
		//UE_LOG(LogTemp, Log, TEXT("No Hit"));
		DrawDebugLine(GetWorld(), AimLocation, TargetLocation, FColor::Red, true);
	}

	if (IsValid(CreatureAnimInstance))
	{
		FTransform SocketTransform = GetMesh()->GetSocketTransform(FName("ArrowSocket"));
		FVector SocketLocation = SocketTransform.GetLocation();
		FVector DeltaVector = TargetLocation - SocketLocation;
		FRotator SocketRotation = FRotationMatrix::MakeFromX(DeltaVector).Rotator();
		FActorSpawnParameters ArrowParams;
		ArrowParams.Owner = this;
		ArrowParams.Instigator = this;

		auto MyArrow = GetWorld()->SpawnActor<AArrow>(SocketLocation, SocketRotation, ArrowParams);
	}
}
