// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CreatureAnim.h"
#include "EnemyAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class STUDYUNREAL_API UEnemyAnimInstance : public UCreatureAnim
{
	GENERATED_BODY()

public:
	UEnemyAnimInstance();
public:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
};
