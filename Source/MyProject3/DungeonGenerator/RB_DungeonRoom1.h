// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyProject3/DungeonGenerator/RoomBase.h"
#include "RB_DungeonRoom1.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT3_API ARB_DungeonRoom1 : public ARoomBase
{
	GENERATED_BODY()
	

public:

	ARB_DungeonRoom1();

	UPROPERTY(VisibleAnywhere, Category = "Componets")
	UArrowComponent* ExitArrow1;
	UPROPERTY(VisibleAnywhere, Category = "Componets")
	UArrowComponent* ExitArrow2;
	UPROPERTY(VisibleAnywhere, Category = "Componets")
	UArrowComponent* ExitArrow3;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* BigPropSpawner1;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* BigPropSpawner2;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* SmallPropSpawner1;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* SmallPropSpawner2;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* SmallPropSpawner3;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* SmallPropSpawner4;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* SmallPropSpawner5;
};
