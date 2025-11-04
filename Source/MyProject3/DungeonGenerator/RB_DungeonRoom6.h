// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyProject3/DungeonGenerator/RoomBase.h"
#include "RB_DungeonRoom6.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT3_API ARB_DungeonRoom6 : public ARoomBase
{
	GENERATED_BODY()
	
public:

	ARB_DungeonRoom6();

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* ExitPoint1;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* ExitPoint2;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* ExitPoint3;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* ExitPoint4;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* ExitPoint5;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* Cube9;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* Cube10;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* PropSpawner1;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* PropSpawner2;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* PropSpawner3;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* PropSpawner4;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* PropSpawner5;
};
