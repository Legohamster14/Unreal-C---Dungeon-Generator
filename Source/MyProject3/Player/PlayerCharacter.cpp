// Fill out your copyright notice in the Description page of Project Settings.


#include "MyProject3/Player/PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "MyProject3/Enemies/EnemyBase.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
	Camera->SetupAttachment(RootComponent);
	Camera->bUsePawnControlRotation = true;

	//setup the attack area
	AttackArea = CreateDefaultSubobject<UBoxComponent>(TEXT("Attack Area"));
	AttackArea->SetGenerateOverlapEvents(true);
	AttackArea->SetupAttachment(RootComponent);
	AttackArea->SetCollisionProfileName("Trigger", false);

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	//box collision will trigger function on onoverlap
	AttackArea->OnComponentBeginOverlap.AddDynamic(this, &APlayerCharacter::OnAttackAreaOverlap);
	AttackArea->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 1.0f, FColor::Red, FString::Printf(TEXT("%s"), (AttackArea->IsCollisionEnabled() ? TEXT("True"): TEXT("False"))));
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Health <= 0)
	{
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 4.0f, FColor::Blue, TEXT("Player dead"));
		//Destroy();
	}
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//binds mouse input for attack
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &APlayerCharacter::Attack);

	//binds Keybord inputs for player
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);

	//binds Camera inputs for player
	PlayerInputComponent->BindAxis("CameraYaw", this, &APlayerCharacter::CameraYaw);
	PlayerInputComponent->BindAxis("CameraPitch", this, &APlayerCharacter::CameraPitch);

}

//moves player forwards and back
void APlayerCharacter::MoveForward(float InputValue) 
{
	FVector ForwardDirection = GetActorForwardVector();
	AddMovementInput(ForwardDirection, InputValue);


}


//move player left and and right
void APlayerCharacter::MoveRight(float InputValue)
{
	FVector RightDirection = GetActorRightVector();
	AddMovementInput(RightDirection, InputValue);

}

//makes the camera look left and right
void APlayerCharacter::CameraYaw(float InputValue)
{
	AddControllerYawInput(InputValue);
}

//makes the camera look up and down
void APlayerCharacter::CameraPitch(float InputValue)
{
	AddControllerPitchInput(InputValue);
}


//turns attack area collision on
void APlayerCharacter::Attack()
{
	AttackArea->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	FTimerHandle StopAttackTimer;
	GetWorldTimerManager().SetTimer(StopAttackTimer, this, &APlayerCharacter::StopAttack, 0.1f, false);
}


//turns attack area collision off
void APlayerCharacter::StopAttack()
{
	AttackArea->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void APlayerCharacter::OnAttackAreaOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//takes away health if the other actor is an enemy
	if (Cast<AEnemyBase>(OtherActor))
	{
		Cast<AEnemyBase>(OtherActor)->Health -= 10;
	}
}
