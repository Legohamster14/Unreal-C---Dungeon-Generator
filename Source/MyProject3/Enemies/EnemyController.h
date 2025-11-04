// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyController.generated.h"

class UBehaviorTreeComponent;
class UNavigationSystemV1;

UCLASS()
class MYPROJECT3_API AEnemyController : public AAIController
{
	GENERATED_BODY()

public:

	void MoveToPosition();

	void FindRandomPoint();

	FVector Destination;

	UNavigationSystemV1* NavSystem;

protected:

	virtual void BeginPlay() override;

	AEnemyController();
};
