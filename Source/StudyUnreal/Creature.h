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
	UPROPERTY(VisibleAnywhere)
	class UWidgetComponent* HpBar;
public:
	ACreature();
protected:
	virtual void BeginPlay() override;
public:
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
public:
	void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterripted);
	virtual void Attack();
	virtual void OnHit() {};
};
