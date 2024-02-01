// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Creature.h"
#include "MyPlayer.generated.h"
/**
 * 
 */
UCLASS()
class STUDYUNREAL_API AMyPlayer : public ACreature
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere)
	class USpringArmComponent* SpringArm;
	UPROPERTY(EditAnywhere)
	class UCameraComponent* Camera;

public:
	AMyPlayer();

public:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	void KeyUpDown(float value);
	void KeyLeftRight(float value);
	void MouseLookUpDown(float value);
	void MouseLookLeftRight(float value);
public:
	virtual void Attack() override;
	virtual void OnHit() override;
	
};
