// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDecorator_Attackable.h"
#include "AIController.h"
#include "MyPlayer.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTDecorator_Attackable::UBTDecorator_Attackable()
{
	NodeName = TEXT("Attackable");
}

bool UBTDecorator_Attackable::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	bool Result = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);
	auto CurrentPawn = OwnerComp.GetAIOwner()->GetPawn();

	if (CurrentPawn == NULL)
	{
		return false;
	}
	
	auto Target = Cast<AMyPlayer>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(FName("Target")));
	if (Target == NULL)
	{
		return false;
	}

	if (Result && Target->GetDistanceTo(CurrentPawn) < 200.f)
	{
		return true;
	}

	return false;
}
