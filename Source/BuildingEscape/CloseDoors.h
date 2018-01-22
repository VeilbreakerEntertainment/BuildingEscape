// Copyright 2017 Veilbreaker Entertainment

#pragma once

#include "Engine/TriggerVolume.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CloseDoors.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UCloseDoors : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCloseDoors();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	ATriggerVolume* TripWire = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	FVector LocalOffset = FVector(0, 0, -25);

	UFUNCTION()
	void OnActivated(UActorComponent* Component, bool bReset);

	USceneComponent* RootComponent = nullptr;
};
