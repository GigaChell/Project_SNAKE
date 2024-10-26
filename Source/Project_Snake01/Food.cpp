

#include "Food.h"
#include "SnakeBase.h"



AFood::AFood()
{
 	
	PrimaryActorTick.bCanEverTick = true;
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	MeshComponent->SetCollisionResponseToAllChannels(ECR_Overlap);
	SetRootComponent(MeshComponent);

}

void AFood::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFood::Destroyed()
{
	// вызываем делегат и сообщает что вызов активирован
	FoodActivated.Broadcast();

	Super::Destroyed();
}


void AFood::Tick(float DeltaTime)
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

void AFood::Interact(AActor* Interactor, bool bIsHead)
{
	if (bIsHead)
	{
		auto Snake = Cast<ASnakeBase>(Interactor);
		if (IsValid(Snake))
		{
			Snake->AddSnakeElement();

			// Сохраняем текущие координаты для нового актора
			int RandomX = FMath::RandRange(-700, 700);
			int RandomY = FMath::RandRange(-1000, 1000);
			this->SetActorLocation(FVector(RandomX, RandomY, 60)); // moving food

			//FoodActivated.Broadcast();
			// Уничтожаем текущий объект
			//Destroy();

			//// Спавним новый объект AFood на локации NewLocation
			//GetWorld()->SpawnActor<AFood>(AFood::StaticClass(), NewLocation, FRotator::ZeroRotator);
		}
	}
}

