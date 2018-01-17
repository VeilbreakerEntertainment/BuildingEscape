// Copyright 2017 Veilbreaker Entertainment

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/ChildActorComponent.h"
#include "OpenMirrorPassage.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenMirrorPassage : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenMirrorPassage();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	FVector LocalOffset = FVector(-150, 0, 0);

	UChildActorComponent* WallCandleOneAsChild = nullptr;
	UChildActorComponent* WallCandleTwoAsChild = nullptr;
	USceneComponent* RootComponent = nullptr;
	USceneComponent* Mirror = nullptr;
	AActor* WallCandleOne = nullptr;
	AActor* WallCandleTwo = nullptr;
};
