// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Perception/AIPerceptionTypes.h>
#include "Perception/AIPerceptionComponent.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include <Perception/AISenseConfig_Sight.h>
#include "EnemyController.generated.h"

class UBehaviorTreeComponent;
class UNavigationSystemV1;

UCLASS()
class MYPROJECT3_API AEnemyController : public AAIController
{
	GENERATED_BODY()

public:

	UFUNCTION()
	void PerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

	UNavigationSystemV1* NavSystem;

	float LineOfSightTimer = 4.0f;

	FTimerHandle EnemyTimer;

	FName HasLineOfSight = "HasLineOfSight";

	FName PlayerActor = "PlayerActor";

protected:

	virtual void BeginPlay() override;

	virtual void OnPossess(APawn* InPawn) override;

	void StartEnemyTimer();

	AEnemyController();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "LostFerry", meta = (AllowPrivateAccess = true))
	TObjectPtr<UAIPerceptionComponent> EnemyPerceptionComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	UAISenseConfig_Sight* sightConfig;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	TObjectPtr<UBehaviorTree> BehaviorTree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	TObjectPtr<UBehaviorTreeComponent> BehaviorTreeComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	UBlackboardComponent* BlackboardComponent;
};
