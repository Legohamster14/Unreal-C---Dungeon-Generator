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

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));

	Chest = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Chest"));

	TextComponent = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Text Component"));

	TriggerArea = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Area"));
	TriggerArea->SetCollisionProfileName("Trigger", false);

	DefaultSceneRoot->SetupAttachment(RootComponent);
	Chest->SetupAttachment(DefaultSceneRoot);
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
	if (Cast<APlayerCharacter>(OtherActor))
	{
		Cast<APlayerCharacter>(OtherActor)->bInRangeOfChest = true;
		TextComponent->SetVisibility(true);
	}
}

void AChest::OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (Cast<APlayerCharacter>(OtherActor))
	{
		Cast<APlayerCharacter>(OtherActor)->bInRangeOfChest = false;
		TextComponent->SetVisibility(false);
	}
}
