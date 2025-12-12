// Fill out your copyright notice in the Description page of Project Settings.


#include "MyProject3/DungeonGenerator/DungeonGenerator.h"
#include "MyProject3/DungeonGenerator/RB_DungeonRoom5.h"
#include "MyProject3/DungeonGenerator/RoomBase.h"
#include "Components/BoxComponent.h"
#include "MyProject3/DungeonGenerator/ClosingWall.h"
#include "MyProject3/DungeonGenerator/PropBase.h"
#include "MyProject3/Enemies/EnemyBase.h"
#include "NavigationSystem.h"
#include "NavigationPath.h"

// Sets default values
ADungeonGenerator::ADungeonGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADungeonGenerator::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle UnusedExitsHandle;
	FTimerHandle SpawnPropsHandle;
	FTimerHandle SpawnEnemiesHandle;
	
	//spawns the first room and starts the loop to generate the rest
	SpawnStarterRoom();
	SpawnNextRoom();

	//close unused exits and spawn props after 1 second
	//GetWorld()->GetTimerManager().SetTimer(UnusedExitsHandle, this, &ADungeonGenerator::CloseUnusedExits, 1.0f, false);
	//GetWorld()->GetTimerManager().SetTimer(SpawnPropsHandle, this, &ADungeonGenerator::SpawnProps, 1.0f, false);
	//spawns enemies after 2 seconds
	//GetWorldTimerManager().SetTimer(SpawnEnemies, this, &ADungeonGenerator::SpawnEnemies, 2.0f, false);

	//gets the nav mesh
	NavSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(this);
}

// Called every frame
void ADungeonGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ADungeonGenerator::SpawnStarterRoom()
{
	//spawn starter room
	ARB_DungeonRoom5* SpawnedStarterRoom = this->GetWorld()->SpawnActor<ARB_DungeonRoom5>(StarterRoom);

	//set starter room location
	SpawnedStarterRoom->SetActorLocation(this->GetActorLocation());

	//puts the exit points of the starter room into an array
	SpawnedStarterRoom->ExitPointsFolder->GetChildrenComponents(false, Exits);
	SpawnedStarterRoom->PropSpawnerFolder->GetChildrenComponents(false, PropSpawnPoints);
}

void ADungeonGenerator::SpawnNextRoom()
{
	bRoomCanSpawn = true;

	//spawns next room
	LatestSpawnedRoom = this->GetWorld()->SpawnActor<ARoomBase>(SpawnableRooms[rand() % SpawnableRooms.Num()]);


	//set location and rotation to a certain exit point
	USceneComponent* SelectedExitPoint = Exits[rand() % Exits.Num()];

	LatestSpawnedRoom->SetActorLocation(SelectedExitPoint->GetComponentLocation());
	LatestSpawnedRoom->SetActorRotation(SelectedExitPoint->GetComponentRotation());

	RemoveOverlappingRooms();

	//only removes the exit points and prop spawn points if the room has spawned
	if (bRoomCanSpawn) {
		Exits.Remove(SelectedExitPoint);
		TArray<USceneComponent*> LatestExitPoints;
		LatestSpawnedRoom->ExitPointsFolder->GetChildrenComponents(false, LatestExitPoints);
		Exits.Append(LatestExitPoints);

		TArray<USceneComponent*> LatestSpawnPoints;
		LatestSpawnedRoom->PropSpawnerFolder->GetChildrenComponents(false, LatestSpawnPoints);
		PropSpawnPoints.Append(LatestSpawnPoints);

		SpawnedRooms.Add(LatestSpawnedRoom);
	}

	RoomAmount--;

	if (RoomAmount > 0) {
		SpawnNextRoom();
	}
	else {
		CloseUnusedExits();
		SpawnProps();
	}
}

void ADungeonGenerator::RemoveOverlappingRooms()
{
	//puts collider of the latest spawned room into the array
	TArray<USceneComponent*> OverlappedRooms;
	LatestSpawnedRoom->OverlapFolder->GetChildrenComponents(false, OverlappedRooms);

	TArray<UPrimitiveComponent*> OverlappingComponents;
	//checks to see if there is any overlap
	for (USceneComponent* Element : OverlappedRooms) {
		Cast<UBoxComponent>(Element)->GetOverlappingComponents(OverlappingComponents);
	}


	//removes the room if there is overlap
	if (OverlappingComponents.Num() > 0)
	{
		bRoomCanSpawn = false;
		RoomAmount++;
		LatestSpawnedRoom->Destroy();
	}
}

void ADungeonGenerator::CloseUnusedExits()
{
	//closes every exit point in the scene
	for (USceneComponent* Element : Exits)
	{
		AClosingWall* SpawnedClosingWall = GetWorld()->SpawnActor<AClosingWall>(ClosingWall);

		FVector RelativeOffset(-50.0f, 0.0f, 450.0f);
		FVector WorldOffset = Element->GetComponentRotation().RotateVector(RelativeOffset);

		SpawnedClosingWall->SetActorLocation(Element->GetComponentLocation() + WorldOffset);
		SpawnedClosingWall->SetActorRotation(Element->GetComponentRotation() + FRotator(0.0f, 90.0f, 0.0f));
	}
}

void ADungeonGenerator::SpawnProps()
{
	//spawn props at every spawn point in the scene
	for (USceneComponent* Element : PropSpawnPoints)
	{
		APropBase* SpawnedProp = GetWorld()->SpawnActor<APropBase>(Props[rand() % Props.Num()]);

		SpawnedProp->SetActorLocation(Element->GetComponentLocation());
		SpawnedProp->SetActorRotation(FRotator(0.0f, rand() % 360, 0.0f));
	}
	FTimerHandle SpawnEnemiesHandle;

	GetWorldTimerManager().SetTimer(SpawnEnemiesHandle, this, &ADungeonGenerator::SpawnEnemies, 2.0f, false);
}

void ADungeonGenerator::SpawnEnemies()
{
	//finds a random point on the nav mesh
	FVector RandomPoint;
	FNavLocation RandomNavPoint;
	FVector RandomRoomPosition;

	RandomRoomPosition = SpawnedRooms[rand() % SpawnedRooms.Num()]->GetActorLocation();


	if (NavSystem->GetRandomPointInNavigableRadius(RandomRoomPosition, 10000.0f, RandomNavPoint))
	{
		RandomPoint = RandomNavPoint;
		//spawn an enemy at the random point
		LatestSpawnedEnemy = this->GetWorld()->SpawnActor<AEnemyBase>(SpawnableEnemies[rand() % SpawnableEnemies.Num()]);
		FVector SpawnOffset = FVector(0, 0, 100);
		LatestSpawnedEnemy->SetActorLocation(RandomPoint + SpawnOffset);

		EnemyAmount--;

		if (EnemyAmount > 0)
		{
			SpawnEnemies();
		}
	}
	else
	{
		SpawnEnemies();
	}


}
