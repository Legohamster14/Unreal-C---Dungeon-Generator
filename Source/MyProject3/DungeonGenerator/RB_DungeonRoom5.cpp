// Fill out your copyright notice in the Description page of Project Settings.


#include "MyProject3/DungeonGenerator/RB_DungeonRoom5.h"
#include "Components/ArrowComponent.h"

ARB_DungeonRoom5::ARB_DungeonRoom5()
{
	ExitPoint1 = CreateDefaultSubobject<UArrowComponent>(TEXT("ExitPoint1"));
	ExitPoint2 = CreateDefaultSubobject<UArrowComponent>(TEXT("ExitPoint2"));
	ExitPoint3 = CreateDefaultSubobject<UArrowComponent>(TEXT("ExitPoint3"));

	PropSpawner1 = CreateDefaultSubobject<UArrowComponent>(TEXT("PropSpawner1"));
	PropSpawner2 = CreateDefaultSubobject<UArrowComponent>(TEXT("PropSpawner2"));
	PropSpawner3 = CreateDefaultSubobject<UArrowComponent>(TEXT("PropSpawner3"));
	PropSpawner4 = CreateDefaultSubobject<UArrowComponent>(TEXT("PropSpawner4"));
	PropSpawner5 = CreateDefaultSubobject<UArrowComponent>(TEXT("PropSpawner5"));
	PropSpawner6 = CreateDefaultSubobject<UArrowComponent>(TEXT("PropSpawner6"));

	ExitPoint1->SetupAttachment(ExitPointsFolder);
	ExitPoint2->SetupAttachment(ExitPointsFolder);
	ExitPoint3->SetupAttachment(ExitPointsFolder);

	PropSpawner1->SetupAttachment(PropSpawnerFolder);
	PropSpawner2->SetupAttachment(PropSpawnerFolder);
	PropSpawner3->SetupAttachment(PropSpawnerFolder);
	PropSpawner4->SetupAttachment(PropSpawnerFolder);
	PropSpawner5->SetupAttachment(PropSpawnerFolder);
	PropSpawner6->SetupAttachment(PropSpawnerFolder);
}
