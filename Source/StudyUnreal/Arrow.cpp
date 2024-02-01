// Fill out your copyright notice in the Description page of Project Settings.


#include "Arrow.h"
#include "Components/BoxComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystem.h"
#include "Kismet/GameplayStatics.h"

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

		Box = CreateDefaultSubobject<UBoxComponent>(FName("Collision Mesh"));
		Box->SetupAttachment(Mesh);
		Box->SetRelativeLocation(FVector(0.f, 0.f, -55.f));
		Box->SetRelativeScale3D(FVector(0.2f, 0.2f, 0.2f));
		Box->OnComponentBeginOverlap.AddDynamic(this, &AArrow::OnOverlapBegin);

		ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovemenetComponent"));
		ProjectileMovementComponent->SetUpdatedComponent(DefaultRoot);
		ProjectileMovementComponent->InitialSpeed = 3000.f;
		ProjectileMovementComponent->MaxSpeed = 3000.f;
		ProjectileMovementComponent->bRotationFollowsVelocity = true;
	}
	static ConstructorHelpers::FObjectFinder<UParticleSystem> PS(TEXT("/Script/Engine.ParticleSystem'/Game/ParagonSparrow/FX/Particles/Sparrow/Abilities/Primary/FX/P_Sparrow_HitHero.P_Sparrow_HitHero'"));
	if (PS.Succeeded())
	{
		Particle = PS.Object;
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

void AArrow::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this && OtherComp)
	{
		Box->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		if (Particle)
		{
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Particle, Box->GetComponentLocation());
		}
		ProjectileMovementComponent->StopMovementImmediately();
		ProjectileMovementComponent->ProjectileGravityScale = 0.f;
		this->AttachToActor(OtherActor, FAttachmentTransformRules(EAttachmentRule::KeepWorld, true));

		UGameplayStatics::ApplyDamage(OtherActor, 10.f, ProjectileMovementComponent->GetOwner()->GetInstigatorController(), NULL, NULL);
		
		FTimerHandle timerHandle;
		GetWorld()->GetTimerManager().SetTimer(timerHandle, [&]() {Destroy(); }, 3.f, false);
	}
}
