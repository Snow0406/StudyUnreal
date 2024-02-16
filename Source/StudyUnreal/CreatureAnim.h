// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CreatureAnim.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnAttackHit);

/**
 * 
 */
UCLASS()
class STUDYUNREAL_API UCreatureAnim : public UAnimInstance
{
	GENERATED_BODY()
protected:
	UPROPERTY(Category = "Animation", Editanywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	float Speed;
	UPROPERTY(Category = "Animation", Editanywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	bool ShouldMove;
	UPROPERTY(Category = "Animation", Editanywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	FVector Velocity;
	UPROPERTY(Category = "Animation", Editanywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	bool OnDeath;
public:
	UPROPERTY(VisibleAnywhere)
	class ACreature* Character;
	UPROPERTY(VisibleAnywhere)
	class UCharacterMovementComponent* CharacterMovement;
	UPROPERTY(VisibleAnywhere)
	UAnimMontage* AttackMontage;
public:
	FOnAttackHit OnAttackHit;
public:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
public:
	virtual void PlayAttackMontage();
	UFUNCTION()
	void AnimNotify_Hit();
	
};
