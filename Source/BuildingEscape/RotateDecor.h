// Copyright 2017 Veilbreaker Entertainment

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RotateDecor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API URotateDecor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URotateDecor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnActivated(UActorComponent* Component, bool bReset);

	AActor* Owner = nullptr;
};
