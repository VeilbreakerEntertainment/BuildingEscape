// Copyright 2017 Veilbreaker Entertainment

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OpenPassage.generated.h"

class UStaticMesh;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenPassage : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenPassage();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnActivated(UActorComponent* Component, bool bReset);

	UPROPERTY(EditAnywhere)
	UStaticMesh* PassageToTrigger = nullptr;

	USceneComponent* RootComponent = nullptr;
};