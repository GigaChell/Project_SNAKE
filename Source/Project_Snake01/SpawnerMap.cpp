// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnerMap.h"

// Sets default values
ASpawnerMap::ASpawnerMap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	



}

// Called when the game starts or when spawned
void ASpawnerMap::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnerMap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawnerMap::OnConstruction()
{
	// Очистка старых блоков, чтобы пересоздать платформу, если настройки изменились
    for (UStaticMeshComponent* Block : PlatformBlocks)
    {
        if (Block)
        {
            Block->DestroyComponent();
        }
    }
    PlatformBlocks.Empty();

    // Генерация платформы в виде сетки блоков
    for (int32 X = 0; X < GridWidth; X++)
    {
        for (int32 Y = 0; Y < GridHeight; Y++)
        {
            // Создание и настройка блока
            UStaticMeshComponent* Block = NewObject<UStaticMeshComponent>(this);
            Block->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
            Block->SetStaticMesh(BlockMesh);
            Block->SetRelativeLocation(FVector(X * BlockSize, Y * BlockSize, 0));

            // Добавление блока в мир
            Block->RegisterComponent();
            PlatformBlocks.Add(Block);
        }
    }
}





