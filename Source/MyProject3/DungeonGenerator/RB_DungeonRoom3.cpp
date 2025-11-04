// Fill out your copyright notice in the Description page of Project Settings.


#include "MyProject3/DungeonGenerator/RB_DungeonRoom3.h"
#include "Components/ArrowComponent.h"

ARB_DungeonRoom3::ARB_DungeonRoom3()
{

	//create exit arrows and closing wall
	ExitArrow1 = CreateDefaultSubobject<UArrowComponent>(TEXT("ExitArrow1"));
	ExitArrow2 = CreateDefaultSubobject<UArrowComponent>(TEXT("ExitArrow2"));

	ClosingWall = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ClosingWall1"));

	PropSpawner1 = CreateDefaultSubobject<UArrowComponent>(TEXT("PropSpawner1"));
	PropSpawner2 = CreateDefaultSubobject<UArrowComponent>(TEXT("PropSpawner2"));
	PropSpawner3 = CreateDefaultSubobject<UArrowComponent>(TEXT("PropSpawner3"));

	//organis exit arrows and closing wall
	ExitArrow1->SetupAttachment(ExitPointsFolder);
	ExitArrow2->SetupAttachment(ExitPointsFolder);

	ClosingWall->SetupAttachment(GeometryFolder);

	PropSpawner1->SetupAttachment(PropSpawnerFolder);
	PropSpawner2->SetupAttachment(PropSpawnerFolder);
	PropSpawner3->SetupAttachment(PropSpawnerFolder);
}
