// Fill out your copyright notice in the Description page of Project Settings.


#include "MyProject3/Enemies/EnemyBase.h"
#include "Components/BoxComponent.h"
#include "MyProject3/Player/PlayerCharacter.h"
//Make enemy attack player


// Sets default values
AEnemyBase::AEnemyBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AttackArea = CreateDefaultSubobject<UBoxComponent>(TEXT("Attack Area"));
	AttackArea->SetGenerateOverlapEvents(true);
	AttackArea->SetupAttachment(RootComponent);
	AttackArea->SetCollisionProfileName("Trigger", false);
}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();

	//setup the attack area
	AttackArea->OnComponentBeginOverlap.AddDynamic(this, &AEnemyBase::OnAttackAreaOverlap);
	AttackArea->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//destroys itself when health is below 0
	if (Health <= 0) {
		Destroy();
	}
	
	AttackCooldown -= DeltaTime;
}

// Called to bind functionality to input
void AEnemyBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


//takes health away from the other actor if it is the player
void AEnemyBase::OnAttackAreaOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<APlayerCharacter>(OtherActor))
	{
		Cast<APlayerCharacter>(OtherActor)->Health -= 10;
	}
}


//turns attack area collision on
void AEnemyBase::Attack()
{
	AttackArea->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	FTimerHandle StopAttackTimer;
	GetWorldTimerManager().SetTimer(StopAttackTimer, this, &AEnemyBase::StopAttack, .1f, false);
}

//turns attack area collision off
void AEnemyBase::StopAttack()
{
	AttackArea->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}