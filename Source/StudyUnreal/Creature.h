// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Creature.generated.h"

UCLASS()
class STUDYUNREAL_API ACreature : public ACharacter
{
	GENERATED_BODY()
private:
	UPROPERTY(VisibleAnywhere)
	class UMyActorComponent* MyActorComponent;
public:
	ACreature();
protected:
	virtual void BeginPlay() override;
public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
public:
	virtual void Attack();
};
