// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Attack.h"
#include "MyEnemy.h"
#include "AIController.h"

UBTTask_Attack::UBTTask_Attack()
{
	NodeName = TEXT("Attack");
	bNotifyTick = true;
}

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);
	
	auto MyEnemy = Cast<AMyEnemy>(OwnerComp.GetAIOwner()->GetPawn());
	if (MyEnemy == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	if (MyEnemy->GetIsAttacking() == false)
	{
		MyEnemy->Attack();
		return EBTNodeResult::InProgress;
	}

	return Result;
}

void UBTTask_Attack::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	auto MyEnemy = Cast<AMyEnemy>(OwnerComp.GetAIOwner()->GetPawn());
	if (MyEnemy == nullptr)
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
		return;
	}

	if (MyEnemy->GetIsAttacking() == false)
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	}
}
