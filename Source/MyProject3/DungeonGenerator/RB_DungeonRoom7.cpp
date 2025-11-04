// Fill out your copyright notice in the Description page of Project Settings.


#include "MyProject3/DungeonGenerator/RB_DungeonRoom7.h"
#include "Components/ArrowComponent.h"

ARB_DungeonRoom7::ARB_DungeonRoom7()
{
	ExitPoint1 = CreateDefaultSubobject<UArrowComponent>(TEXT("ExitPoint1"));

	ExitPoint1->SetupAttachment(ExitPointsFolder);
}
