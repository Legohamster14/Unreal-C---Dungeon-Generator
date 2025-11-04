// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyProject3/DungeonGenerator/RoomBase.h"
#include "RB_DungeonRoom7.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT3_API ARB_DungeonRoom7 : public ARoomBase
{
	GENERATED_BODY()
	
public:

	ARB_DungeonRoom7();

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* ExitPoint1;
};
