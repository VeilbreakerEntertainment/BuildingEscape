// Copyright 2017 Veilbreaker Entertainment

#pragma once

#include "Kismet/GameplayStatics.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	//How far ahead of the player can we reach in cm
	float Reach = 150.f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;

	//Ray-cast and grab what's in reach
	void Grab();

	//Called when grab action key is released
	void Release();

	//Ray-cast and activate what's in reach
	void ActivateTarget();

	//Find attached components
	void FindPhysicsHandleComponent();

	//Setup input component
	void SetupInputComponent();

	//Return hit for first physics body in reach
	const FHitResult GetFirstPhysicsBodyInReach();

	//Returns current start of reach line
	FVector GetReachLineStart();

	//Returns current end of reach line
	FVector GetReachLineEnd();
};
