// Copyright 2017 Veilbreaker Entertainment

#include "TripWire.h"

// Sets default values for this component's properties
UTripWire::UTripWire()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTripWire::BeginPlay()
{
	Super::BeginPlay();

	Player = Cast<AActor>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	Owner = GetOwner();

	if (!TripWireToSet)
		UE_LOG(LogTemp, Error, TEXT("%s missing trip wire!"), *GetOwner()->GetName()) // Game will crash without this set, if this is the case it will log this message so you know the problem
}

// Called every frame
void UTripWire::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll the Trigger Volume every frame
	if (TripWireToSet->IsOverlappingActor(Player) && IsTripped == false)
	{
		IsTripped = true;

		OnTripped.Broadcast();
	}
}