// Fill out your copyright notice in the Description page of Project Settings.


#include "Arrow.h"
#include "Components/BoxComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AArrow::AArrow()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultRoot"));
	SetRootComponent(DefaultRoot);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh(TEXT("/Script/Engine.StaticMesh'/Game/ParagonSparrow/FX/Meshes/Heroes/Sparrow/Abilities/SM_Sparrow_Arrow.SM_Sparrow_Arrow'"));


	if (StaticMesh.Succeeded())
	{
		Mesh->SetStaticMesh(StaticMesh.Object);
		Mesh->SetupAttachment(DefaultRoot);
		Mesh->SetRelativeLocationAndRotation(FVector(100.f, 0.f, 0.f), FRotator(90.f, 0.f, 0.f));
		Mesh->SetCollisionProfileName(TEXT("NoCollision"));

		CollisionMesh = CreateDefaultSubobject<UBoxComponent>(FName("Collision Mesh"));
		CollisionMesh->SetupAttachment(Mesh);
		CollisionMesh->SetRelativeLocation(FVector(0.f, 0.f, -55.f));
		CollisionMesh->SetRelativeScale3D(FVector(0.2f, 0.2f, 0.2f));

		ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovemenetComponent"));
		ProjectileMovementComponent->SetUpdatedComponent(DefaultRoot);
		ProjectileMovementComponent->InitialSpeed = 3000.f;
		ProjectileMovementComponent->MaxSpeed = 3000.f;
		ProjectileMovementComponent->bRotationFollowsVelocity = true;
	}



}

// Called when the game starts or when spawned
void AArrow::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AArrow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}