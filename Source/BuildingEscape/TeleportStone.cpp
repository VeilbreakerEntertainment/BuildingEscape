// Copyright 2017 Veilbreaker Entertainment

#include "TeleportStone.h"


// Sets default values for this component's properties
UTeleportStone::UTeleportStone()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UTeleportStone::BeginPlay()
{
	Super::BeginPlay();

	OnComponentActivated.AddDynamic(this, &UTeleportStone::OnActivated);
}

void UTeleportStone::OnActivated(UActorComponent* Component, bool bReset)
{
	GetWorld()->GetTimerManager().SetTimer(TeleportStoneTimer, this, &UTeleportStone::OnTeleport, MaxTeleportTime, false);
}

void UTeleportStone::OnTeleport()
{
	Player = Cast<AActor>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	Player->SetActorLocationAndRotation(TeleportLocation, TeleportRotation);
}

void UTeleportStone::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	// Clear the timer
	GetWorld()->GetTimerManager().ClearTimer(TeleportStoneTimer);
}