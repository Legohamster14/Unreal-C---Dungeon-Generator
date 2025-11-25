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
				GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Blue, TEXT("Saw Player"));
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

void AEnemyController::MoveToPosition()
{
	FNavLocation Test;

	//sets up navigation system from the nav mesh in the world
	NavSystem = UNavigationSystemV1::GetCurrent(GetWorld());

	//runs if the nav system isnt null
	if (NavSystem) {

		//finds a random point 
		FindRandomPoint();

		//makes the agent move to the random point on the nav mesh
		MoveToLocation(Destination);

		//run the function again after 10 seconds
		FTimerHandle PlayAgain;
		GetWorld()->GetTimerManager().SetTimer(PlayAgain, this, &AEnemyController::MoveToPosition, 10.0f, false);
	}
}

void AEnemyController::FindRandomPoint()
{

	FVector CharacterLocation = GetCharacter()->GetActorLocation();

	//finds a random location in a area around the nav agent
	FVector RandomPoint = CharacterLocation + FVector(rand() % 15000 - 7500, rand() % 15000 - 7500, 0);

	//checks if the random point is on the nav nesh
	if (NavSystem->FindPathToLocationSynchronously(GetWorld(), CharacterLocation, RandomPoint)) {
		Destination = RandomPoint;
	}
	else
	{
		//repeat function if the random point isnt on the nav mesh
		FindRandomPoint();
	}
}

