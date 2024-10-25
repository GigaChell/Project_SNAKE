// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Project_Snake01GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_SNAKE01_API AProject_Snake01GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	void SpawnFood();
	
		UPROPERTY (EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<AActor>> SpawnActorArray;
};
