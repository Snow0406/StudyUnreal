// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActorComponent.h"
#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"

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
	auto MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (MyGameInstance)
	{
		auto CharacterData = MyGameInstance->GetCharacterData(Lv);
		if (CharacterData)
		{
			Level = CharacterData->Level;
			MaxHp = CharacterData->MaxHp;
			Hp = MaxHp;

			UE_LOG(LogTemp, Log, TEXT("Lv : %d"), Level);
			UE_LOG(LogTemp, Log, TEXT("Hp : %d"), Hp);
		}
	}
}

void UMyActorComponent::OnDamaged(float DamageAmount)
{
	int32 NewHP = Hp - DamageAmount;
	SetHp(NewHP);
	OnHpChange.Broadcast();
	UE_LOG(LogTemp, Warning, TEXT("HP : %d"), Hp);
}

void UMyActorComponent::SetHp(int32 NewHp)
{
	Hp = NewHp;
	if (Hp < 0) Hp = 0;
}

float UMyActorComponent::GetHpRatio()
{
	if (MaxHp == 0 || Hp == 0) return 0.f;
	else return (float)MaxHp / (float)Hp;
}
