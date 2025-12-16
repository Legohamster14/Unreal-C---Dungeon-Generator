// Fill out your copyright notice in the Description page of Project Settings.


#include "MyProject3/DungeonGenerator/RB_DungeonRoom3.h"
#include "Components/ArrowComponent.h"

ARB_DungeonRoom3::ARB_DungeonRoom3()
{

	//create exit arrows and closing wall
	ExitArrow1 = CreateDefaultSubobject<UArrowComponent>(TEXT("ExitArrow1"));
	ExitArrow2 = CreateDefaultSubobject<UArrowComponent>(TEXT("ExitArrow2"));

	ClosingWall = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ClosingWall1"));

	BigPropSpawner1 = CreateDefaultSubobject<UArrowComponent>(TEXT("BigPropSpawner1"));
	BigPropSpawner2 = CreateDefaultSubobject<UArrowComponent>(TEXT("BigPropSpawner2"));
	BigPropSpawner3 = CreateDefaultSubobject<UArrowComponent>(TEXT("BigPropSpawner3"));

	SmallPropSpawner1 = CreateDefaultSubobject<UArrowComponent>(TEXT("SmallPropSpawner1"));
	SmallPropSpawner2 = CreateDefaultSubobject<UArrowComponent>(TEXT("SmallPropSpawner2"));
	SmallPropSpawner3 = CreateDefaultSubobject<UArrowComponent>(TEXT("SmallPropSpawner3"));
	SmallPropSpawner4 = CreateDefaultSubobject<UArrowComponent>(TEXT("SmallPropSpawner4"));
	SmallPropSpawner5 = CreateDefaultSubobject<UArrowComponent>(TEXT("SmallPropSpawner5"));

	//organis exit arrows and closing wall
	ExitArrow1->SetupAttachment(ExitPointsFolder);
	ExitArrow2->SetupAttachment(ExitPointsFolder);

	ClosingWall->SetupAttachment(GeometryFolder);

	BigPropSpawner1->SetupAttachment(BigPropsFolder);
	BigPropSpawner2->SetupAttachment(BigPropsFolder);
	BigPropSpawner3->SetupAttachment(BigPropsFolder);

	SmallPropSpawner1->SetupAttachment(SmallPropsFolder);
	SmallPropSpawner2->SetupAttachment(SmallPropsFolder);
	SmallPropSpawner3->SetupAttachment(SmallPropsFolder);
	SmallPropSpawner4->SetupAttachment(SmallPropsFolder);
	SmallPropSpawner5->SetupAttachment(SmallPropsFolder);
}
