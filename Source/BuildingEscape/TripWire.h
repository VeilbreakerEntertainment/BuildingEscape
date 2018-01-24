// Copyright 2017 Veilbreaker Entertainment

#pragma once

#include "Engine/TriggerVolume.h"
#include "Kismet/GameplayStatics.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TripWire.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTripped);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UTripWire : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTripWire();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable)
	FOnTripped OnTripped;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	ATriggerVolume* TripWireToSet = nullptr;

	AActor* Owner = nullptr;

	AActor* Player = nullptr;;

	bool IsTripped = false;
};
