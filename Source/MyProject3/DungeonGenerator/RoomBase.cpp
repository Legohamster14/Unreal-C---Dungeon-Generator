// Fill out your copyright notice in the Description page of Project Settings.


#include "MyProject3/DungeonGenerator/RoomBase.h"
#include "Components/BoxComponent.h"
#include "Components/ArrowComponent.h"

// Sets default values
ARoomBase::ARoomBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//create objects for blueprint
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	GeometryFolder = CreateDefaultSubobject<USceneComponent>(TEXT("GeometryFolder"));
	OverlapFolder = CreateDefaultSubobject<USceneComponent>(TEXT("OverlapFolder"));
	ExitPointsFolder = CreateDefaultSubobject<USceneComponent>(TEXT("ExitPointsFolder"));
	PropSpawnerFolder = CreateDefaultSubobject<USceneComponent>(TEXT("PropSpawnerFolder"));
	MiscFolder = CreateDefaultSubobject<USceneComponent>(TEXT("MiscFolder"));
	BigPropsFolder = CreateDefaultSubobject<USceneComponent>(TEXT("BigPropsFolder"));
	SmallPropsFolder = CreateDefaultSubobject<USceneComponent>(TEXT("SmallPropsFolder"));
	ChestSpawnFolder = CreateDefaultSubobject<USceneComponent>(TEXT("ChestSpawnFolder"));

	Cube_1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube_1"));
	Cube_2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube_2"));
	Cube_3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube_3"));
	Cube_4 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube_4"));
	Cube_5 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube_5"));
	Cube_6 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube_6"));
	Cube_7 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube_7"));
	Cube_8 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube_8"));

	Floor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Floor"));
	Ceiling = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ceiling"));

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));

	BoxCollision->SetCollisionProfileName("RoomOverlapPreset", false);

	//organise blueprint hierarchy
	DefaultSceneRoot->SetupAttachment(RootComponent);
	GeometryFolder->SetupAttachment(DefaultSceneRoot);
	OverlapFolder->SetupAttachment(DefaultSceneRoot);
	ExitPointsFolder->SetupAttachment(DefaultSceneRoot);
	PropSpawnerFolder->SetupAttachment(DefaultSceneRoot);
	MiscFolder->SetupAttachment(DefaultSceneRoot);
	SmallPropsFolder->SetupAttachment(PropSpawnerFolder);
	BigPropsFolder->SetupAttachment(PropSpawnerFolder);
	ChestSpawnFolder->SetupAttachment(DefaultSceneRoot);

	Cube_1->SetupAttachment(GeometryFolder);
	Cube_2->SetupAttachment(GeometryFolder);
	Cube_3->SetupAttachment(GeometryFolder);
	Cube_4->SetupAttachment(GeometryFolder);
	Cube_5->SetupAttachment(GeometryFolder);
	Cube_6->SetupAttachment(GeometryFolder);
	Cube_7->SetupAttachment(GeometryFolder);
	Cube_8->SetupAttachment(GeometryFolder);
	Floor->SetupAttachment(GeometryFolder);
	Ceiling->SetupAttachment(GeometryFolder);

	BoxCollision->SetupAttachment(OverlapFolder);

	Arrow->SetupAttachment(DefaultSceneRoot);
}

// Called when the game starts or when spawned
void ARoomBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARoomBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

