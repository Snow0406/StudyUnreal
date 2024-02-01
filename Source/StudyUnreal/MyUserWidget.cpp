// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUserWidget.h"
#include "MyActorComponent.h"
#include "Components/ProgressBar.h"

void UMyUserWidget::BindHp(UMyActorComponent* ActorComp)
{
	MyActorComp = ActorComp;
	MyActorComp->OnHpChanged.AddUObject(this, &UMyUserWidget::UpdateHp);
	UpdateHp();
}

void UMyUserWidget::UpdateHp()
{
	PB_HpBar->SetPercent(MyActorComp->GetHpRatio());
}
