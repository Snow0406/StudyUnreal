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

void UEnemyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (IsValid(Character))
	{
		ShouldMove = Speed > 3.f;
	}
}
