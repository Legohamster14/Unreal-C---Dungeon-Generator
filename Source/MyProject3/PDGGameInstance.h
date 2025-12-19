// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PDGGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT3_API UPDGGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPDGGameInstance();

	UPROPERTY(BlueprintReadOnly)
	int32 LevelsCleared = 0;

protected:
};
