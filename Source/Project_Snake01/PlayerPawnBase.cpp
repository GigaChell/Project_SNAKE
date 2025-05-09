
#include "PlayerPawnBase.h"
#include "Camera/CameraComponent.h"
#include "SnakeBase.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"


APlayerPawnBase::APlayerPawnBase()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	PawnCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PawnCamera"));
	RootComponent = PawnCamera;

}

void APlayerPawnBase::BeginPlay()
{
	Super::BeginPlay();
	SetActorRotation(FRotator(-90, 0, 0));
	CreateSnakeActor();

	FInputModeGameOnly InputMode; // установка фокуса сразу на игру чтобы не кликать во вьюпорт
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetInputMode(InputMode);

}

void APlayerPawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void APlayerPawnBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Vertical", this, &APlayerPawnBase::HandlePlayerVerticalInput);
	PlayerInputComponent->BindAxis("Horizontal", this, &APlayerPawnBase::HandlePlayerHorizontalInput);
}

void APlayerPawnBase::CreateSnakeActor()
{
	SnakeActor = GetWorld()->SpawnActor<ASnakeBase>(SnakeActorClass, FTransform());
}

void APlayerPawnBase::HandlePlayerVerticalInput(float value)
{
	if (IsValid(SnakeActor) && !SnakeActor->Moving)
	{
		if (value > 0 && SnakeActor->LastMoveDirection!=EMovementDirection::DOWN)
		{
			SnakeActor->LastMoveDirection = EMovementDirection::UP;
			SnakeActor->Moving = true;
		}
		else if (value < 0 && SnakeActor->LastMoveDirection != EMovementDirection::UP)
		{
			SnakeActor->LastMoveDirection = EMovementDirection::DOWN;
			SnakeActor->Moving = true;
		}
	}
}

void APlayerPawnBase::HandlePlayerHorizontalInput(float value)
{
	if (IsValid(SnakeActor) && !SnakeActor->Moving)
	{
		if (value > 0 && SnakeActor->LastMoveDirection != EMovementDirection::LEFT)
		{
			SnakeActor->LastMoveDirection = EMovementDirection::RIGTH;
			SnakeActor->Moving = true;
		}
		else if (value < 0 && SnakeActor->LastMoveDirection != EMovementDirection::RIGTH)
		{
			SnakeActor->LastMoveDirection = EMovementDirection::LEFT;
			SnakeActor->Moving = true;
		}
	}
}

