

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"   
#include "Food.generated.h"


//обявление делагата
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMyDelegateFood);

UCLASS()
class PROJECT_SNAKE01_API AFood : public AActor, public IInteractable  
{
	GENERATED_BODY()
	
public:	
	
	AFood();

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly)
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatingActor")
	float FloatSpeed = 20.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatingActor")
	float RotationSpeed = 20.0f;

protected:
	
	virtual void BeginPlay() override;
	virtual void Destroyed() override;


public:	
	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	virtual void Interact(AActor* Interactor, bool bIsHead) override;

	// обявление делагата
	FMyDelegateFood FoodActivated;
};
