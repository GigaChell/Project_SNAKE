

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"   
#include "Food.generated.h"

UCLASS()
class PROJECT_SNAKE01_API AFood : public AActor, public IInteractable  
{
	GENERATED_BODY()
	
public:	
	
	AFood();

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly)
	UStaticMeshComponent* MeshComponent;

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	virtual void Interact(AActor* Interactor, bool bIsHead) override;
};
