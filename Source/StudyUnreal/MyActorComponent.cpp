// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActorComponent.h"

// Sets default values for this component's properties
UMyActorComponent::UMyActorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bWantsInitializeComponent = true;
	Level = 1;
}


void UMyActorComponent::InitializeComponent()
{
	Super::InitializeComponent();
}

// Called when the game starts
void UMyActorComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UMyActorComponent::SetLevel(int32 Lv)
{
}

void UMyActorComponent::OnDamaged(float DamageAmount)
{
}
