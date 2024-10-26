// Copyright Epic Games, Inc. All Rights Reserved.


#include "Project_Snake01GameModeBase.h"
#include "Food.h"
#include "Bonus.h"

void AProject_Snake01GameModeBase::BeginPlay()
{
	Super::BeginPlay();

	// Облявляем переменную для хранения ID таймера
	SpawnFood();
	
	FTimerHandle BonusTimer;

	// запускаем таймер, который будет вызывать функцию каждые 10 сек
	GetWorld()->GetTimerManager().SetTimer(BonusTimer, this, &AProject_Snake01GameModeBase::SpawnBonus, 2.0f, true);
	
}

void AProject_Snake01GameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AProject_Snake01GameModeBase::SpawnFood()
{
	if (SpawnFoodArray.Num())
	{
		int32 RandomIndex = FMath::RandRange(0, SpawnFoodArray.Num() - 1);
		auto ClassForSpawn = SpawnFoodArray[RandomIndex];

		int RandomX = FMath::RandRange(-700, 700);
		int RandomY = FMath::RandRange(-1000, 1000);
		auto SpawnLocation = FVector(RandomX, RandomY, 60);

		auto SpawnedFood = GetWorld()->SpawnActor<AActor>(ClassForSpawn, FTransform(FVector(SpawnLocation)));

		auto CurrentBonus = Cast<ABonus>(SpawnedFood);
	


		if (CurrentBonus)
		{
			CurrentBonus->SetLifeSpan(10.0f);

			//CurrentBonus->FMyDelegateBonus.AddDynamic(this, &AProject_Snake01GameModeBase::SpawnFood);

	
		}

	}

	
}

void AProject_Snake01GameModeBase::SpawnBonus()
{
	int32 RandomIndex = FMath::RandRange(0, SpawnBonusArray.Num() - 1);
	auto ClassForSpawn = SpawnBonusArray[RandomIndex];

	int RandomX = FMath::RandRange(-700, 700);
	int RandomY = FMath::RandRange(-1000, 1000);

	if (ClassForSpawn)
	{
		AActor* SpawnedBonus = GetWorld()->SpawnActor<AActor>(ClassForSpawn, FTransform(FVector(RandomX, RandomY, 0)));

		SpawnedBonus->SetLifeSpan(3.0f);

		 //if (SpawnedBonus)
   //     {
   //         // Устанавливаем скейл бонуса по всем осям
   //         FVector NewScale(2.0f, 2.0f, 2.0f); // Увеличение в 2 раза
   //         SpawnedBonus->SetActorScale3D(NewScale);
   //     }
	}
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Spawn BONUS!"));
}
