// Fill out your copyright notice in the Description page of Project Settings.


#include "MyProject3/DungeonGenerator/RB_DungeonRoom4.h"
#include "Components/ArrowComponent.h"

ARB_DungeonRoom4::ARB_DungeonRoom4()
{
	ExitPoint1 = CreateDefaultSubobject<UArrowComponent>(TEXT("ExitPoint1"));

	BigPropSpawner1 = CreateDefaultSubobject<UArrowComponent>(TEXT("BigPropSpawner1"));

	SmallPropSpawner1 = CreateDefaultSubobject<UArrowComponent>(TEXT("SmallPropSpawner1"));
	SmallPropSpawner2 = CreateDefaultSubobject<UArrowComponent>(TEXT("SmallPropSpawner2"));
	SmallPropSpawner3 = CreateDefaultSubobject<UArrowComponent>(TEXT("SmallPropSpawner3"));
	SmallPropSpawner4 = CreateDefaultSubobject<UArrowComponent>(TEXT("SmallPropSpawner4"));
	SmallPropSpawner5 = CreateDefaultSubobject<UArrowComponent>(TEXT("SmallPropSpawner5"));

	ExitPoint1->SetupAttachment(ExitPointsFolder);

	BigPropSpawner1->SetupAttachment(BigPropsFolder);

	SmallPropSpawner1->SetupAttachment(SmallPropsFolder);
	SmallPropSpawner2->SetupAttachment(SmallPropsFolder);
	SmallPropSpawner3->SetupAttachment(SmallPropsFolder);
	SmallPropSpawner4->SetupAttachment(SmallPropsFolder);
	SmallPropSpawner5->SetupAttachment(SmallPropsFolder);
}
