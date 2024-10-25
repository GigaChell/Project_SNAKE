

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

			int RandomX = FMath::RandRange(-390, 390); // generation x
			int RandomY = FMath::RandRange(-180, 180); // generation y
			this->SetActorLocation(FVector(RandomX, RandomY, 0)); // moving food
			Destroy();
			
		}
	}
}

