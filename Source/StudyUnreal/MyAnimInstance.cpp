// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCharacter.h"
#include "MyAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"

void UMyAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	UE_LOG(LogTemp, Log, TEXT("NativeInitializeAnimation"));
}

void UMyAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	UE_LOG(LogTemp, Log, TEXT("NativeBeginPlay"));
	auto Pawn = TryGetPawnOwner();
	if (IsValid(Pawn))
	{
		MyCharacter = Cast<AMyCharacter>(Pawn);
		if (IsValid(MyCharacter))
		{
			CharacterMovement = MyCharacter->GetCharacterMovement();
			UE_LOG(LogTemp, Log, TEXT("CharacterMovement IsValid"));
		}
	}
}

void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (IsValid(MyCharacter)) {
		FVector Velocity = CharacterMovement->Velocity;
		FRotator Rotaion = MyCharacter->GetActorRotation();
		FVector UnRotateVector = Rotaion.UnrotateVector(Velocity);

		Vertical = UnRotateVector.X;
		Horizontal = UnRotateVector.Y;
		Speed = Velocity.Size2D();

		auto Acceleration = CharacterMovement->GetCurrentAcceleration();
		ShouldMove = Speed > 3.f && Acceleration != FVector::Zero();
	}
}
