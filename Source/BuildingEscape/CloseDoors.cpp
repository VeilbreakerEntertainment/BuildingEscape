// Copyright 2017 Veilbreaker Entertainment

#include "CloseDoors.h"

// Sets default values for this component's properties
UCloseDoors::UCloseDoors()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCloseDoors::BeginPlay()
{
	Super::BeginPlay();

	Player = Cast<AActor>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	Owner = GetOwner();

	if (!TripWire)
		UE_LOG(LogTemp, Error, TEXT("%s missing trip wire!"), *GetOwner()->GetName())
}

// Called every frame
void UCloseDoors::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//Poll the Trigger Volume every frame
	if (TripWire->IsOverlappingActor(Player) && IsTripped == false)
	{
		IsTripped = true;

		OnClose.Broadcast();
		UE_LOG(LogTemp, Warning, TEXT("TripWire or TripWire2 has been triggered by the player."))
	}
}