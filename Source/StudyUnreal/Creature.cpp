// Fill out your copyright notice in the Description page of Project Settings.


#include "Creature.h"
#include "MyActorComponent.h"
#include "CreatureAnim.h"
#include "Components/WidgetComponent.h"
#include "MyUserWidget.h"


ACreature::ACreature()
{
	//UE_LOG(LogTemp, Log, TEXT("ACreature"));
	MyActorComponent = CreateDefaultSubobject<UMyActorComponent>(TEXT("MyActorComponent"));
	HpBar = CreateDefaultSubobject<UWidgetComponent>(TEXT("HpBar"));
	HpBar->SetupAttachment(GetMesh());
	HpBar->SetWidgetSpace(EWidgetSpace::Screen);
	static ConstructorHelpers::FClassFinder<UMyUserWidget> MyUW(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/UI/WBP_HpBar.WBP_HpBar_C'"));

	if (MyUW.Succeeded())
	{
		HpBar->SetWidgetClass(MyUW.Class);
		HpBar->SetDrawSize(FVector2D(200.f, 30.f));
		HpBar->SetRelativeLocation(FVector(0.f, 0.f, 200.f));
	}

}

// Called when the game starts or when spawned
void ACreature::BeginPlay()
{
	Super::BeginPlay();
	CreatureAnimInstance = Cast<UCreatureAnim>(GetMesh()->GetAnimInstance());
	if (CreatureAnimInstance)
	{
		CreatureAnimInstance->OnMontageEnded.AddDynamic(this, &ACreature::OnAttackMontageEnded);
		CreatureAnimInstance->OnAttackHit.AddUObject(this, &ACreature::OnHit);
	}
	auto HpWidget = Cast<UMyUserWidget>(HpBar->GetUserWidgetObject());
	if (HpWidget)
	{
		HpWidget->BindHp(MyActorComponent);
	}
}

float ACreature::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	MyActorComponent->OnDamaged(DamageAmount);
	return DamageAmount;
}

void ACreature::OnAttackMontageEnded(UAnimMontage* Montage, bool bInterripted)
{
	IsAttacking = false;
}

void ACreature::Attack()
{
	if (!IsAttacking)
	{
		IsAttacking = true;

		if (IsValid(CreatureAnimInstance))
		{
			CreatureAnimInstance->PlayAttackMontage();
		}

	}
}
