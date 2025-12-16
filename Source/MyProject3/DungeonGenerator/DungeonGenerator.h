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
class AChest;

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

	UPROPERTY(EditAnywhere, Category = "Rooms")
	TArray<ARoomBase*> SpawnedRooms;

	UPROPERTY(EditAnywhere, Category = "Enemies")
	TArray<AEnemyBase*> SpawnedEnemies;

	UPROPERTY(EditAnywhere, Category = "Unused Exits Closing Wall")
	TSubclassOf<AClosingWall> ClosingWall;

	UPROPERTY(EditAnywhere, Category = "Props")
	TArray<TSubclassOf<APropBase>> BigProps;

	UPROPERTY(EditAnywhere, Category = "Props")
	TArray<TSubclassOf<APropBase>> SmallProps;

	UPROPERTY(EditAnywhere, Category = "Props")
	TArray<APropBase*> SpawnedProps;

	UPROPERTY(EditAnywhere, Category = "Room Info")
	int32 RoomAmount = 20;

	UPROPERTY(EditAnywhere, Category = "Enemies")
	int32 EnemyAmount = 20;

	UPROPERTY(EditAnywhere, Category = "Enemies")
	TArray<TSubclassOf<AEnemyBase>> SpawnableEnemies;

	AEnemyBase* LatestSpawnedEnemy;

	UPROPERTY(EditAnywhere, Category = "End")
	TSubclassOf<AChest> ChestReference;

	AChest* EndGoal;

	bool bRoomCanSpawn;

	ARoomBase* LatestSpawnedRoom;

	TArray<USceneComponent*> Exits;

	TArray<USceneComponent*> BigPropSpawnPoints;

	TArray<USceneComponent*> SmallPropSpawnPoints;

	void SpawnStarterRoom();

	void SpawnNextRoom();

	void RemoveOverlappingRooms();

	void CloseUnusedExits();

	void SpawnProps();

	void SpawnEnemies();

	void SpawnEndGoal();

	virtual void Tick(float DeltaTime) override;

	class UNavigationSystemV1* NavSystem;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
