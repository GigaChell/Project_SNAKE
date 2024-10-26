// Fill out your copyright notice in the Description page of Project Settings.


#include "Bonus.h"
#include "SnakeBase.h"

// Sets default values
ABonus::ABonus()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	MeshComponent->SetCollisionResponseToAllChannels(ECR_Overlap);
	SetRootComponent(MeshComponent);
	

}

// Called when the game starts or when spawned
void ABonus::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABonus::Destroyed()
{
	// вызываем делегат и сообщает что вызов активирован
	BonusActivated.Broadcast();

	Super::Destroyed();
}


// Called every frame
void ABonus::Tick(float DeltaTime)
{

	FVector NewLocation = GetActorLocation();
	FRotator NewRotation = GetActorRotation();
	float RunningTime = GetGameTimeSinceCreation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Z += DeltaHeight * FloatSpeed;			//Scale our height by FloatSpeed
	float DeltaRotation = DeltaTime * RotationSpeed;
	NewRotation.Yaw += DeltaRotation;
	SetActorLocationAndRotation(NewLocation, NewRotation);

	Super::Tick(DeltaTime);

}

void ABonus::Interact(AActor* Interactor, bool bIsHead)
{
	if (bIsHead)
	{
		auto Snake = Cast<ASnakeBase>(Interactor);
		if (IsValid(Snake))
		{
			// Сохраняем текущую скорость, чтобы вернуть её через N секунд
			float OriginalSpeed = Snake->MovementSpeed;

			// Увеличиваем скорость
			Snake->MovementSpeed = Snake->MovementSpeed * 0.7f;
			Snake->SetActorTickInterval(Snake->MovementSpeed);

			//Запускаем таймер для возврата к исходной скорости через N секунд
				FTimerHandle UnusedHandle;
			GetWorld()->GetTimerManager().SetTimer(UnusedHandle, [Snake, OriginalSpeed]()
				{
					// Возвращаем скорость
					Snake->MovementSpeed = OriginalSpeed;
					Snake->SetActorTickInterval(Snake->MovementSpeed);
				}, 3.0f, false);


			BonusActivated.Broadcast();
			// Уничтожаем бонус
			
			Destroy();

		}
	}
}

