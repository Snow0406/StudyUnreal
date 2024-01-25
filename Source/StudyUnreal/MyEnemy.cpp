// Fill out your copyright notice in the Description page of Project Settings.


#include "MyEnemy.h"
#include "Components/CapsuleComponent.h"
#include "MyAIController.h"
#include "EnemyAnimInstance.h"

// Sets default values
AMyEnemy::AMyEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SkeletalMesh(TEXT("/Script/Engine.SkeletalMesh'/Game/ParagonYin/Characters/Heroes/Yin/Meshes/Yin.Yin'"));

	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Character"));

	if (SkeletalMesh.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SkeletalMesh.Object);
		GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -90.f), FRotator(0.f, -90.f, 0.f));
	}
	static ConstructorHelpers::FClassFinder<UAnimInstance> AI(TEXT("/Script/Engine.AnimBlueprint'/Game/Animation/ABP_Enemy.ABP_Enemy_C'"));
	if (AI.Succeeded())
	{
		GetMesh()->SetAnimClass(AI.Class);
	}


	AIControllerClass = AMyAIController::StaticClass();
}

// Called when the game starts or when spawned
void AMyEnemy::BeginPlay()
{
	Super::BeginPlay();

	EnemyAnimInstance = Cast<UEnemyAnimInstance>(GetMesh()->GetAnimInstance());
	EnemyAnimInstance->OnMontageEnded.AddDynamic(this, &AMyEnemy::OnAttackMontageEnded);
	
}

// Called every frame
void AMyEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMyEnemy::Attack()
{
	if (!IsAttacking)
	{
		IsAttacking = true;
		if (IsValid(EnemyAnimInstance))
		{
			EnemyAnimInstance->PlayAttackMontage();
		}
	}
}

void AMyEnemy::OnAttackMontageEnded(UAnimMontage* Montage, bool bInterripted)
{
	IsAttacking = false;
}

