// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyProject3/DungeonGenerator/RoomBase.h"
#include "RB_DungeonRoom4.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT3_API ARB_DungeonRoom4 : public ARoomBase
{
	GENERATED_BODY()
	
public:

	ARB_DungeonRoom4();

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* ExitPoint1;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* BigPropSpawner1;

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
