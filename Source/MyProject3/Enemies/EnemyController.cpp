// Fill out your copyright notice in the Description page of Project Settings.


#include "MyProject3/Enemies/EnemyController.h"
#include "NavigationSystem.h"
#include "NavigationPath.h"
#include "MyProject3/Enemies/EnemyBase.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AISense_Sight.h"
#include "Perception/AISenseConfig_Sight.h"

AEnemyController::AEnemyController()
{
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));

	//setup perception
	EnemyPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("EnemyPerceptionComponent"));
	sightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	EnemyPerceptionComponent->ConfigureSense(*sightConfig);
	EnemyPerceptionComponent->SetDominantSense(sightConfig->GetSenseImplementation());

	UAIPerceptionSystem::RegisterPerceptionStimuliSource(this, sightConfig->GetSenseImplementation(), GetPawn());
	sightConfig->SightRadius = 300.0f;
	sightConfig->LoseSightRadius = 350.0f;
	sightConfig->PeripheralVisionAngleDegrees = 110.0f;
	sightConfig->DetectionByAffiliation.bDetectEnemies = true;
	sightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	sightConfig->DetectionByAffiliation.bDetectFriendlies = false;
	EnemyPerceptionComponent->ConfigureSense(*sightConfig);
	EnemyPerceptionComponent->SetDominantSense(sightConfig->GetSenseImplementation());
}

void AEnemyController::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(BehaviorTree.Get())) 
	{
		RunBehaviorTree(BehaviorTree.Get());
		BehaviorTreeComponent->StartTree(*BehaviorTree.Get());
	}

	PerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &AEnemyController::PerceptionUpdated);
}

void AEnemyController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
}

void AEnemyController::StartEnemyTimer()
{
	Blackboard->SetValueAsBool(HasLineOfSight, true);
	Blackboard->SetValueAsObject(PlayerActor, nullptr);
}

void AEnemyController::PerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	if (Stimulus.WasSuccessfullySensed())
	{
		if (Stimulus.Type == UAISense::GetSenseID<UAISense_Sight>())
		{
			if (Actor->ActorHasTag("Player")) 
			{
				GetWorldTimerManager().ClearTimer(EnemyTimer);

				Blackboard->SetValueAsBool(HasLineOfSight, true);
				Blackboard->SetValueAsObject(PlayerActor, Actor);
			}
		}
	}
	else
	{
		GetWorldTimerManager().SetTimer(EnemyTimer, this, &AEnemyController::StartEnemyTimer, LineOfSightTimer, false);
	}
}

