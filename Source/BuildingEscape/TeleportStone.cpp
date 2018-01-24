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
	Player = Cast<AActor>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	Player->SetActorLocationAndRotation(TeleportLocation, TeleportRotation);
	UE_LOG(LogTemp, Warning, TEXT("Player teleport has been called."))
}