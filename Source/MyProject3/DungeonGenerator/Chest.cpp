// Fill out your copyright notice in the Description page of Project Settings.


#include "MyProject3/DungeonGenerator/Chest.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"
#include "MyProject3/Player/PlayerCharacter.h"

// Sets default values
AChest::AChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Chest = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Chest"));

	TextComponent = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Text Component"));

	TriggerArea = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Area"));
	TriggerArea->SetCollisionProfileName("Trigger", false);

	Chest->SetupAttachment(RootComponent);
	TriggerArea->SetupAttachment(Chest);
	TextComponent->SetupAttachment(Chest);
}


// Called when the game starts or when spawned
void AChest::BeginPlay()
{
	Super::BeginPlay();
	
	TriggerArea->OnComponentBeginOverlap.AddDynamic(this, &AChest::OnTriggerBeginOverlap);
	TriggerArea->OnComponentEndOverlap.AddDynamic(this, &AChest::OnTriggerEndOverlap);

	TextComponent->SetVisibility(false);
}

// Called every frame
void AChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AChest::OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::Blue, TEXT("Something entered trigger area"));
	if (Cast<APlayerCharacter>(OtherActor))
	{
		Cast<APlayerCharacter>(OtherActor)->bInRangeOfChest = true;
		TextComponent->SetVisibility(true);
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::Blue, TEXT("Player entered trigger area"));
	}
}

void AChest::OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::Blue, TEXT("Something exited trigger area"));
	if (Cast<APlayerCharacter>(OtherActor))
	{
		Cast<APlayerCharacter>(OtherActor)->bInRangeOfChest = false;
		TextComponent->SetVisibility(false);
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::Blue, TEXT("Player exited trigger area"));
	}
}
