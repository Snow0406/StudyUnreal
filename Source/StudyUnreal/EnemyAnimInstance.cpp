// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

UEnemyAnimInstance::UEnemyAnimInstance()
{
	ConstructorHelpers::FObjectFinder<UAnimMontage> AM(TEXT("/Script/Engine.AnimMontage'/Game/ParagonYin/Characters/Heroes/Yin/Animations/E_Ability_Attack_A_Montage.E_Ability_Attack_A_Montage'"));
	if (AM.Succeeded())
	{
		AttackMontage = AM.Object;
	}

}

void UEnemyAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	auto Pawn = TryGetPawnOwner();
	if (IsValid(Pawn))
	{
		Character = Cast<ACharacter>(Pawn);
		if (IsValid(Character))
		{
			CharacterMovement = Character->GetCharacterMovement();
		}
	}
}

void UEnemyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (IsValid(Character))
	{
		Velocity = CharacterMovement->Velocity;
		FRotator Rotation = Character->GetActorRotation();
		Speed = Velocity.Size2D();

		//auto Acceleration = CharacterMovement->GetCurrentAcceleration();
		//ShouldMove = Speed > 3.f && Acceleration != FVector::Zero();
		ShouldMove = Speed > 3.f;
	}
}

void UEnemyAnimInstance::PlayAttackMontage()
{
	if (IsValid(AttackMontage))
	{
		if (!Montage_IsPlaying(AttackMontage))
		{
			Montage_Play(AttackMontage);
		}
	}
}
