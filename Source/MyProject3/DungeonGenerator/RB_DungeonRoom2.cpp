// Fill out your copyright notice in the Description page of Project Settings.


#include "MyProject3/DungeonGenerator/RB_DungeonRoom2.h"
#include "Components/ArrowComponent.h"

ARB_DungeonRoom2::ARB_DungeonRoom2()
{

	//create exit arrows and closing wall
	ExitArrow1 = CreateDefaultSubobject<UArrowComponent>(TEXT("ExitArrow1"));
	ExitArrow2 = CreateDefaultSubobject<UArrowComponent>(TEXT("ExitArrow2"));

	ClosingWall = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ClosingWall1"));

	//organis exit arrows and closing wall
	ExitArrow1->SetupAttachment(ExitPointsFolder);
	ExitArrow2->SetupAttachment(ExitPointsFolder);

	ClosingWall->SetupAttachment(GeometryFolder);
}
