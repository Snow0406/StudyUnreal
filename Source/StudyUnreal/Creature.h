// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Creature.generated.h"

UCLASS()
class STUDYUNREAL_API ACreature : public ACharacter
{
	GENERATED_BODY()
protected:
	UPROPERTY(VisibleAnywhere)
	bool IsAttacking = false;
	UPROPERTY(VisibleAnywhere)
	class UMyActorComponent* MyActorComponent;
	UPROPERTY(VisibleAnywhere)
	class UCreatureAnim* CreatureAnimInstance;
public:
	ACreature();
protected:
	virtual void BeginPlay() override;
public:
	UFUNCTION()
	void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterripted);
	UFUNCTION()
	virtual void Attack();
	UFUNCTION()
	void OnHit();
};
