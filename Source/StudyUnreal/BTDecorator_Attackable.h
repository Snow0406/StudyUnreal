// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_Attackable.generated.h"

/**
 * 
 */
UCLASS()
class STUDYUNREAL_API UBTDecorator_Attackable : public UBTDecorator
{
	GENERATED_BODY()
public:
	UBTDecorator_Attackable();

public:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;

	
};
