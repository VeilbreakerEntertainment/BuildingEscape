// Copyright 2017 Veilbreaker Entertainment

#include "CloseDoors.h"


// Sets default values for this component's properties
UCloseDoors::UCloseDoors()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UCloseDoors::BeginPlay()
{
	Super::BeginPlay();

	if (!TripWire)
		UE_LOG(LogTemp, Error, TEXT("%s missing trip wire!"), *GetOwner()->GetName())
}

void UCloseDoors::OnActivated(UActorComponent* Component, bool bReset)
{
	RootComponent = GetOwner()->GetRootComponent();

	RootComponent->AddLocalOffset(LocalOffset);
}