// Fill out your copyright notice in the Description page of Project Settings.


#include "MyProject3/DungeonGenerator/RB_DungeonRoom6.h"
#include "Components/ArrowComponent.h"

ARB_DungeonRoom6::ARB_DungeonRoom6()
{
	ExitPoint1 = CreateDefaultSubobject<UArrowComponent>(TEXT("ExitPoint1"));
	ExitPoint2 = CreateDefaultSubobject<UArrowComponent>(TEXT("ExitPoint2"));
	ExitPoint3 = CreateDefaultSubobject<UArrowComponent>(TEXT("ExitPoint3"));
	ExitPoint4 = CreateDefaultSubobject<UArrowComponent>(TEXT("ExitPoint4"));
	ExitPoint5 = CreateDefaultSubobject<UArrowComponent>(TEXT("ExitPoint5"));

	Cube9 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube9"));
	Cube10 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube10"));

	PropSpawner1 = CreateDefaultSubobject<UArrowComponent>(TEXT("PropSpawner1"));
	PropSpawner2 = CreateDefaultSubobject<UArrowComponent>(TEXT("PropSpawner2"));
	PropSpawner3 = CreateDefaultSubobject<UArrowComponent>(TEXT("PropSpawner3"));
	PropSpawner4 = CreateDefaultSubobject<UArrowComponent>(TEXT("PropSpawner4"));
	PropSpawner5 = CreateDefaultSubobject<UArrowComponent>(TEXT("PropSpawner5"));

	ExitPoint1->SetupAttachment(ExitPointsFolder);
	ExitPoint2->SetupAttachment(ExitPointsFolder);
	ExitPoint3->SetupAttachment(ExitPointsFolder);
	ExitPoint4->SetupAttachment(ExitPointsFolder);
	ExitPoint5->SetupAttachment(ExitPointsFolder);

	Cube9->SetupAttachment(GeometryFolder);
	Cube10->SetupAttachment(GeometryFolder);

	PropSpawner1->SetupAttachment(PropSpawnerFolder);
	PropSpawner2->SetupAttachment(PropSpawnerFolder);
	PropSpawner3->SetupAttachment(PropSpawnerFolder);
	PropSpawner4->SetupAttachment(PropSpawnerFolder);
	PropSpawner5->SetupAttachment(PropSpawnerFolder);
}
