// Fill out your copyright notice in the Description page of Project Settings.


#include "MyProject3/DungeonGenerator/RB_DungeonRoom5.h"
#include "Components/ArrowComponent.h"

ARB_DungeonRoom5::ARB_DungeonRoom5()
{
	ExitPoint1 = CreateDefaultSubobject<UArrowComponent>(TEXT("ExitPoint1"));
	ExitPoint2 = CreateDefaultSubobject<UArrowComponent>(TEXT("ExitPoint2"));
	ExitPoint3 = CreateDefaultSubobject<UArrowComponent>(TEXT("ExitPoint3"));

	BigPropSpawner1 = CreateDefaultSubobject<UArrowComponent>(TEXT("BigPropSpawner1"));
	BigPropSpawner2 = CreateDefaultSubobject<UArrowComponent>(TEXT("BigPropSpawner2"));
	BigPropSpawner3 = CreateDefaultSubobject<UArrowComponent>(TEXT("BigPropSpawner3"));
	BigPropSpawner4 = CreateDefaultSubobject<UArrowComponent>(TEXT("BigPropSpawner4"));
	BigPropSpawner5 = CreateDefaultSubobject<UArrowComponent>(TEXT("BigPropSpawner5"));
	BigPropSpawner6 = CreateDefaultSubobject<UArrowComponent>(TEXT("BigPropSpawner6"));

	SmallPropSpawner1 = CreateDefaultSubobject<UArrowComponent>(TEXT("SmallPropSpawner1"));
	SmallPropSpawner2 = CreateDefaultSubobject<UArrowComponent>(TEXT("SmallPropSpawner2"));
	SmallPropSpawner3 = CreateDefaultSubobject<UArrowComponent>(TEXT("SmallPropSpawner3"));
	SmallPropSpawner4 = CreateDefaultSubobject<UArrowComponent>(TEXT("SmallPropSpawner4"));
	SmallPropSpawner5 = CreateDefaultSubobject<UArrowComponent>(TEXT("SmallPropSpawner5"));
	SmallPropSpawner6 = CreateDefaultSubobject<UArrowComponent>(TEXT("SmallPropSpawner6"));
	SmallPropSpawner7 = CreateDefaultSubobject<UArrowComponent>(TEXT("SmallPropSpawner7"));
	SmallPropSpawner8 = CreateDefaultSubobject<UArrowComponent>(TEXT("SmallPropSpawner8"));
	SmallPropSpawner9 = CreateDefaultSubobject<UArrowComponent>(TEXT("SmallPropSpawner9"));
	SmallPropSpawner10 = CreateDefaultSubobject<UArrowComponent>(TEXT("SmallPropSpawner10"));
	SmallPropSpawner11 = CreateDefaultSubobject<UArrowComponent>(TEXT("SmallPropSpawner11"));
	SmallPropSpawner12 = CreateDefaultSubobject<UArrowComponent>(TEXT("SmallPropSpawner12"));
	SmallPropSpawner13 = CreateDefaultSubobject<UArrowComponent>(TEXT("SmallPropSpawner13"));
	SmallPropSpawner14 = CreateDefaultSubobject<UArrowComponent>(TEXT("SmallPropSpawner14"));
	SmallPropSpawner15 = CreateDefaultSubobject<UArrowComponent>(TEXT("SmallPropSpawner15"));

	ChestSpawn1 = CreateDefaultSubobject<UArrowComponent>(TEXT("ChestSpawn1"));
	ChestSpawn2 = CreateDefaultSubobject<UArrowComponent>(TEXT("ChestSpawn2"));
	ChestSpawn3 = CreateDefaultSubobject<UArrowComponent>(TEXT("ChestSpawn3"));
	ChestSpawn4 = CreateDefaultSubobject<UArrowComponent>(TEXT("ChestSpawn4"));
	ChestSpawn5 = CreateDefaultSubobject<UArrowComponent>(TEXT("ChestSpawn5"));

	ExitPoint1->SetupAttachment(ExitPointsFolder);
	ExitPoint2->SetupAttachment(ExitPointsFolder);
	ExitPoint3->SetupAttachment(ExitPointsFolder);

	BigPropSpawner1->SetupAttachment(BigPropsFolder);
	BigPropSpawner2->SetupAttachment(BigPropsFolder);
	BigPropSpawner3->SetupAttachment(BigPropsFolder);
	BigPropSpawner4->SetupAttachment(BigPropsFolder);
	BigPropSpawner5->SetupAttachment(BigPropsFolder);
	BigPropSpawner6->SetupAttachment(BigPropsFolder);

	SmallPropSpawner1->SetupAttachment(SmallPropsFolder);
	SmallPropSpawner2->SetupAttachment(SmallPropsFolder);
	SmallPropSpawner3->SetupAttachment(SmallPropsFolder);
	SmallPropSpawner4->SetupAttachment(SmallPropsFolder);
	SmallPropSpawner5->SetupAttachment(SmallPropsFolder);
	SmallPropSpawner6->SetupAttachment(SmallPropsFolder);
	SmallPropSpawner7->SetupAttachment(SmallPropsFolder);
	SmallPropSpawner8->SetupAttachment(SmallPropsFolder);
	SmallPropSpawner9->SetupAttachment(SmallPropsFolder);
	SmallPropSpawner10->SetupAttachment(SmallPropsFolder);
	SmallPropSpawner11->SetupAttachment(SmallPropsFolder);
	SmallPropSpawner12->SetupAttachment(SmallPropsFolder);
	SmallPropSpawner13->SetupAttachment(SmallPropsFolder);
	SmallPropSpawner14->SetupAttachment(SmallPropsFolder);
	SmallPropSpawner15->SetupAttachment(SmallPropsFolder);

	ChestSpawn1->SetupAttachment(ChestSpawnFolder);
	ChestSpawn2->SetupAttachment(ChestSpawnFolder);
	ChestSpawn3->SetupAttachment(ChestSpawnFolder);
	ChestSpawn4->SetupAttachment(ChestSpawnFolder);
	ChestSpawn5->SetupAttachment(ChestSpawnFolder);
}
