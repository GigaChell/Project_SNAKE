// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"   //-------------------------модуль 21.3-------------------------
#include "Food.generated.h"

UCLASS()
class PROJECT_SNAKE01_API AFood : public AActor, public IInteractable  //-------------------------модуль 21.3-------------------------
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFood();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	virtual void Interact(AActor* Interactor, bool bIshead) override;
};
