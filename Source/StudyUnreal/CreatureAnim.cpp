// Fill out your copyright notice in the Description page of Project Settings.


#include "CreatureAnim.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Creature.h"

void UCreatureAnim::PlayAttackMontage()
{
		if (IsValid(AttackMontage))
		{
			if (!Montage_IsPlaying(AttackMontage))
			{
				Montage_Play(AttackMontage);
			}
		}
}

void UCreatureAnim::AnimNotify_Hit()
{
	OnAttackHit.Broadcast();
}

void UCreatureAnim::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	auto Pawn = TryGetPawnOwner();
	if (IsValid(Pawn))
	{
		Character = Cast<ACreature>(Pawn);
		if (IsValid(Character))
		{
			CharacterMovement = Character->GetCharacterMovement();
		}
	}
	OnDeath = false;
}

void UCreatureAnim::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (IsValid(Character))
	{
		Velocity = CharacterMovement->Velocity;
		FRotator Rotation = Character->GetActorRotation();
		Speed = Velocity.Size2D();

		if (Character->GetHp() <= 0 && !OnDeath)
		{
			OnDeath = true;
		}
	}
}
