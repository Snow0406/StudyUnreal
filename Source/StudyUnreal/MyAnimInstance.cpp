// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

#include "MyCharacter.h"

//void UMyAnimInstance::NativeInitializeAnimation()
//{
//	Super::NativeInitializeAnimation();
//
//
//}

UMyAnimInstance::UMyAnimInstance()
{
	ConstructorHelpers::FObjectFinder<UAnimMontage> AnimMontage(TEXT("/Script/Engine.AnimMontage'/Game/ParagonSparrow/Characters/Heroes/Sparrow/Animations/Primary_Fire_Med_Montage.Primary_Fire_Med_Montage'"));
	if (AnimMontage.Succeeded())
	{
		FireMontage = AnimMontage.Object;
	}
}

void UMyAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	auto Pawn = TryGetPawnOwner();
	if (IsValid(Pawn))
	{
		MyCharacter = Cast<AMyCharacter>(Pawn);
		if (IsValid(MyCharacter))
		{
			CharacterMovement = MyCharacter->GetCharacterMovement();
		}
	}
}

void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (IsValid(MyCharacter))
	{
		Velocity = CharacterMovement->Velocity;
		FRotator Rotation = MyCharacter->GetActorRotation();
		Speed = Velocity.Size2D();

		auto Acceleration = CharacterMovement->GetCurrentAcceleration();
		ShouldMove = Speed > 3.f && Acceleration != FVector::Zero();
		IsFalling = CharacterMovement->IsFalling();

		AimRotation = MyCharacter->GetBaseAimRotation();
		FRotator VelocityRotation = UKismetMathLibrary::MakeRotFromX(Velocity);

		FRotator DeltaRotation = VelocityRotation - AimRotation;
		DeltaRotation.Normalize();

		YawOffset = DeltaRotation.Yaw;

	}


}

void UMyAnimInstance::PlayFireMontage()
{
	if (IsValid(FireMontage))
	{
		if (!Montage_IsPlaying(FireMontage))
		{
			Montage_Play(FireMontage);
		}
	}
}
