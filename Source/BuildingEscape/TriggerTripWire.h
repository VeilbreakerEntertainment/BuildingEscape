// Copyright 2017 Veilbreaker Entertainment

#pragma once

#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TriggerTripWire.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UTriggerTripWire : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTriggerTripWire();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

	AActor* Player = nullptr;
	AActor* RootActor = nullptr;

	ACharacter* PlayerCharacter = nullptr;
	ACharacter* HitCharacter = nullptr;
};