// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CreatureAnim.h"
#include "MyAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class STUDYUNREAL_API UMyAnimInstance : public UCreatureAnim
{
	GENERATED_BODY()
private:
	UPROPERTY(Category = "Animation", Editanywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	bool IsFalling;
	UPROPERTY(Category = "Animation", Editanywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	float YawOffset; 
	UPROPERTY(Category = "Animation", Editanywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	FRotator AimRotation;
	UPROPERTY(Category = "Animation", Editanywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	float RotateYaw;
	UPROPERTY(Category = "Animation", Editanywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	FRotator MovingRotation;
	UPROPERTY(Category = "Animation", Editanywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	FRotator PrevRotation;
	UPROPERTY(Category = "Animation", Editanywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	float PrevDistanceCurve;
	UPROPERTY(Category = "Animation", Editanywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	float DistanceCurve;
	UPROPERTY(Category = "Animation", Editanywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	float DeltaDistanceCurve;
public:
	UMyAnimInstance();
public:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
};
