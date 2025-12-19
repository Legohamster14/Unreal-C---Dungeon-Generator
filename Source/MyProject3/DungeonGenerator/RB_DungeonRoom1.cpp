// Fill out your copyright notice in the Description page of Project Settings.


#include "MyProject3/DungeonGenerator/RB_DungeonRoom1.h"
#include "Components/ArrowComponent.h"

ARB_DungeonRoom1::ARB_DungeonRoom1()
{

	//creates exit arrows
	ExitArrow1 = CreateDefaultSubobject<UArrowComponent>(TEXT("ExitArrow1"));
	ExitArrow2 = CreateDefaultSubobject<UArrowComponent>(TEXT("ExitArrow2"));
	ExitArrow3 = CreateDefaultSubobject<UArrowComponent>(TEXT("ExitArrow3"));

	BigPropSpawner1 = CreateDefaultSubobject<UArrowComponent>(TEXT("BigPropSpawner1"));
	BigPropSpawner2 = CreateDefaultSubobject<UArrowComponent>(TEXT("BigPropSpawner2"));

	SmallPropSpawner1 = CreateDefaultSubobject<UArrowComponent>(TEXT("SmallPropSpawner1"));
	SmallPropSpawner2 = CreateDefaultSubobject<UArrowComponent>(TEXT("SmallPropSpawner2"));
	SmallPropSpawner3 = CreateDefaultSubobject<UArrowComponent>(TEXT("SmallPropSpawner3"));
	SmallPropSpawner4 = CreateDefaultSubobject<UArrowComponent>(TEXT("SmallPropSpawner4"));
	SmallPropSpawner5 = CreateDefaultSubobject<UArrowComponent>(TEXT("SmallPropSpawner5"));

	ChestSpawn1 = CreateDefaultSubobject<UArrowComponent>(TEXT("ChestSpawn1"));
	ChestSpawn2 = CreateDefaultSubobject<UArrowComponent>(TEXT("ChestSpawn2"));

	//organise exit arrows
	ExitArrow1->SetupAttachment(ExitPointsFolder);
	ExitArrow2->SetupAttachment(ExitPointsFolder);
	ExitArrow3->SetupAttachment(ExitPointsFolder);

	BigPropSpawner1->SetupAttachment(BigPropsFolder);
	BigPropSpawner2->SetupAttachment(BigPropsFolder);

	SmallPropSpawner1->SetupAttachment(SmallPropsFolder);
	SmallPropSpawner2->SetupAttachment(SmallPropsFolder);
	SmallPropSpawner3->SetupAttachment(SmallPropsFolder);
	SmallPropSpawner4->SetupAttachment(SmallPropsFolder);
	SmallPropSpawner5->SetupAttachment(SmallPropsFolder);

	ChestSpawn1->SetupAttachment(ChestSpawnFolder);
	ChestSpawn2->SetupAttachment(ChestSpawnFolder);
}
