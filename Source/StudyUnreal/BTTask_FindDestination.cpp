// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FindDestination.h"
#include "MyAIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_FindDestination::UBTTask_FindDestination()
{
	NodeName = TEXT("FindPatrolDestination");
}

EBTNodeResult::Type UBTTask_FindDestination::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	auto CurrentPawn = OwnerComp.GetAIOwner()->GetPawn();

	if (CurrentPawn != NULL)
	{
		auto NavSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());
		if (NavSystem != NULL)
		{
			FNavLocation RandomLocation; 
			if (NavSystem->GetRandomPointInNavigableRadius(CurrentPawn->GetActorLocation(), 500.f, RandomLocation))
			{
				OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName("Destination"), RandomLocation.Location);
				return EBTNodeResult::Succeeded;
			}
		}
	}
	return EBTNodeResult::Failed;
}
