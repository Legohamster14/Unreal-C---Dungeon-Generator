// Fill out your copyright notice in the Description page of Project Settings.


#include "MyProject3/DungeonGenerator/PropBase.h"

// Sets default values
APropBase::APropBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));

	Prop1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Prop1"));
	Prop2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Prop2"));
	Prop3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Prop3"));
	Prop4 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Prop4"));

	DefaultSceneRoot->SetupAttachment(RootComponent);

	Prop1->SetupAttachment(DefaultSceneRoot);
	Prop2->SetupAttachment(DefaultSceneRoot);
	Prop3->SetupAttachment(DefaultSceneRoot);
	Prop4->SetupAttachment(DefaultSceneRoot);
}

// Called when the game starts or when spawned
void APropBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APropBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

