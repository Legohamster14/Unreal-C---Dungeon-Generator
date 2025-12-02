// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DungeonGenerator.generated.h"

class ARB_DungeonRoom5;
class ARoomBase;
class AClosingWall;
class APropBase;
class AEnemyBase;

UCLASS()
class MYPROJECT3_API ADungeonGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADungeonGenerator();

	UPROPERTY(EditAnywhere, Category = "Rooms")
	TSubclassOf<ARB_DungeonRoom5> StarterRoom;

	UPROPERTY(EditAnywhere, Category = "Rooms")
	TArray<TSubclassOf<ARoomBase>> SpawnableRooms;

	UPROPERTY(EditAnywhere, Category = "Unused Exits Closing Wall")
	TSubclassOf<AClosingWall> ClosingWall;

	UPROPERTY(EditAnywhere, Category = "Props")
	TArray<TSubclassOf<APropBase>> Props;

	UPROPERTY(EditAnywhere, Category = "Room Info")
	int32 RoomAmount = 20;

	UPROPERTY(EditAnywhere, Category = "Enemies")
	int32 EnemyAmount = 20;

	UPROPERTY(EditAnywhere, Category = "Enemies")
	TArray<TSubclassOf<AEnemyBase>> SpawnableEnemies;

	AEnemyBase* LatestSpawnedEnemy;

	bool bRoomCanSpawn;

	ARoomBase* LatestSpawnedRoom;

	TArray<USceneComponent*> Exits;

	TArray<USceneComponent*> PropSpawnPoints;

	void SpawnStarterRoom();

	void SpawnNextRoom();

	void RemoveOverlappingRooms();

	void CloseUnusedExits();

	void SpawnProps();

	void SpawnEnemies();

	virtual void Tick(float DeltaTime) override;

	class UNavigationSystemV1* NavSystem;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
