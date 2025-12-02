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
	sightConfig->SightRadius = 1000.0f;
	sightConfig->LoseSightRadius = 1100.0f;
	sightConfig->PeripheralVisionAngleDegrees = 120.0f;
	sightConfig->DetectionByAffiliation.bDetectEnemies = true;
	sightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	sightConfig->DetectionByAffiliation.bDetectFriendlies = false;
	EnemyPerceptionComponent->ConfigureSense(*sightConfig);
	EnemyPerceptionComponent->SetDominantSense(sightConfig->GetSenseImplementation());
}

void AEnemyController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//attacks the player when close
	AttackCooldown -= DeltaTime;
	if (Player)
	{
		DistanceToPlayer = (GetPawn()->GetActorLocation() - Player->GetActorLocation()).Size();

		if (DistanceToPlayer <= 100.f && AttackCooldown <= 0)
		{
			AttackCooldown = .5f;
			Cast<AEnemyBase>(GetPawn())->Attack();
		}
	}
}

void AEnemyController::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(BehaviorTree.Get())) 
	{
		RunBehaviorTree(BehaviorTree.Get());
		BehaviorTreeComponent->StartTree(*BehaviorTree.Get());
	}

	//run the function when something enters perception area
	PerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &AEnemyController::PerceptionUpdated);

}

void AEnemyController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
}

void AEnemyController::StartEnemyTimer()
{
	Blackboard->SetValueAsBool(HasLineOfSight, false);
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
				//tells behaviour tree that player has been percieved
				Player = Actor;
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

