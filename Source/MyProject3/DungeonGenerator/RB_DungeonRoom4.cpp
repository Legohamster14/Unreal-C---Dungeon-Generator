// Fill out your copyright notice in the Description page of Project Settings.


#include "MyProject3/DungeonGenerator/RB_DungeonRoom4.h"
#include "Components/ArrowComponent.h"

ARB_DungeonRoom4::ARB_DungeonRoom4()
{
	ExitPoint1 = CreateDefaultSubobject<UArrowComponent>(TEXT("ExitPoint1"));

	PropSpawner1 = CreateDefaultSubobject<UArrowComponent>(TEXT("PropSpawner1"));

	ExitPoint1->SetupAttachment(ExitPointsFolder);

	PropSpawner1->SetupAttachment(PropSpawnerFolder);
}
