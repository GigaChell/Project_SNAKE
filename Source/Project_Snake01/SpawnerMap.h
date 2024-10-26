// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnerMap.generated.h"

UCLASS()
class PROJECT_SNAKE01_API ASpawnerMap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnerMap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void OnConstruction();

    // Ширина и высота сетки (количество блоков по оси X и Y)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform")
    int32 GridWidth = 10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform")
    int32 GridHeight = 10;

    // Размер каждого блока платформы
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform")
    float BlockSize = 100.0f;

    // Сетка для хранения блоков платформы
    UPROPERTY()
    TArray<UStaticMeshComponent*> PlatformBlocks;

    

    // Меш для блоков платформы
    UPROPERTY(EditAnywhere, Category = "Platform")
    UStaticMesh* BlockMesh;
};
