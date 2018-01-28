// Copyright 2017 Veilbreaker Entertainment

#pragma once

#include "Kismet/GameplayStatics.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TeleportStone.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UTeleportStone : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTeleportStone();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	UFUNCTION()
	void OnActivated(UActorComponent* Component, bool bReset);

	void OnTeleport();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	FVector TeleportLocation = FVector(-11030, -10, 120);

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	FRotator TeleportRotation = FRotator(0, 0, 90);

	AActor* Player = nullptr;

	FTimerHandle TeleportStoneTimer;

	float MaxTeleportTime = 3.f;
};
