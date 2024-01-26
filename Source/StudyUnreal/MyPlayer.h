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
	UPROPERTY(VisibleAnywhere)
	class UMyActorComponent* MyActorComponent;
public:
	AMyPlayer();
protected:
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
public:
	virtual void Attack() override;
	
};
