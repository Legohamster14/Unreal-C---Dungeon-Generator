// Fill out your copyright notice in the Description page of Project Settings.


#include "MyProject3/Enemies/EnemyController.h"
#include "NavigationSystem.h"
#include "NavigationPath.h"
#include "MyProject3/Enemies/EnemyBase.h"

AEnemyController::AEnemyController()
{

}

void AEnemyController::BeginPlay()
{
	Super::BeginPlay();

	//move to position after timer has finished
	FTimerHandle MoveTimer;
	GetWorld()->GetTimerManager().SetTimer(MoveTimer, this, &AEnemyController::MoveToPosition, 0.1f, false);
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
