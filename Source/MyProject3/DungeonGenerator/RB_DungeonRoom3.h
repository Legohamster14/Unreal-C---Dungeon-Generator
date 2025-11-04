// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyProject3/DungeonGenerator/RoomBase.h"
#include "RB_DungeonRoom3.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT3_API ARB_DungeonRoom3 : public ARoomBase
{
	GENERATED_BODY()
	
public:

	ARB_DungeonRoom3();

	UPROPERTY(VisibleAnywhere, Category = "Componets")
	UArrowComponent* ExitArrow1;
	UPROPERTY(VisibleAnywhere, Category = "Componets")
	UArrowComponent* ExitArrow2;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* ClosingWall;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* PropSpawner1;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* PropSpawner2;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* PropSpawner3;
};
