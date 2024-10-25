// Copyright Epic Games, Inc. All Rights Reserved.


#include "Project_Snake01GameModeBase.h"
#include "Food.h"

void AProject_Snake01GameModeBase::BeginPlay()
{
	Super::BeginPlay();

	// Облявляем переменную для хранения ID таймера
	FTimerHandle FoodTimer;

	// запускаем таймер, который будет вызывать функцию каждые 10 сек
	GetWorld()->GetTimerManager().SetTimer(FoodTimer, this, &AProject_Snake01GameModeBase::SpawnFood, 1.0f, true);
}

void AProject_Snake01GameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AProject_Snake01GameModeBase::SpawnFood()
{
	int32 RandomIndex = FMath::RandRange(0, SpawnActorArray.Num() - 1);
	auto ClassForSpawn = SpawnActorArray[RandomIndex];

	int RandomX = FMath::RandRange(-1000, 1000);
	int RandomY = FMath::RandRange(-1000, 1000);

	if (ClassForSpawn)
	{
		GetWorld()->SpawnActor<AActor>(ClassForSpawn, FTransform(FVector(RandomX, RandomY, 0)));
	}
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Spawn FOOD!"));
}
