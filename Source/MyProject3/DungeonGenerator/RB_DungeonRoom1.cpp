// Fill out your copyright notice in the Description page of Project Settings.


#include "MyProject3/DungeonGenerator/RB_DungeonRoom1.h"
#include "Components/ArrowComponent.h"

ARB_DungeonRoom1::ARB_DungeonRoom1()
{

	//creates exit arrows
	ExitArrow1 = CreateDefaultSubobject<UArrowComponent>(TEXT("ExitArrow1"));
	ExitArrow2 = CreateDefaultSubobject<UArrowComponent>(TEXT("ExitArrow2"));
	ExitArrow3 = CreateDefaultSubobject<UArrowComponent>(TEXT("ExitArrow3"));

	PropSpawner1 = CreateDefaultSubobject<UArrowComponent>(TEXT("PropSpawner1"));
	PropSpawner2 = CreateDefaultSubobject<UArrowComponent>(TEXT("PropSpawner2"));

	//organise exit arrows
	ExitArrow1->SetupAttachment(ExitPointsFolder);
	ExitArrow2->SetupAttachment(ExitPointsFolder);
	ExitArrow3->SetupAttachment(ExitPointsFolder);

	PropSpawner1->SetupAttachment(PropSpawnerFolder);
	PropSpawner2->SetupAttachment(PropSpawnerFolder);

}
