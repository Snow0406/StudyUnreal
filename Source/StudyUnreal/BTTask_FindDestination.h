// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_FindDestination.generated.h"

/**
 * 
 */
UCLASS()
class STUDYUNREAL_API UBTTask_FindDestination : public UBTTaskNode
{
	GENERATED_BODY()
public:
	UBTTask_FindDestination();
public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
